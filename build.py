#!/usr/bin/env python3
from pathlib import Path
import shutil
import struct
import subprocess

ROOT = Path(__file__).resolve().parent
SRC = ROOT / "src" / "main.c"
DIST = ROOT / "dist"
OUT = DIST / "RiichiCity-Stove-PrivateRoom-Patch-1.0.2.exe"

# The public repository intentionally does not embed the distribution icon.
# This keeps third-party artwork out of the source tree. The generated binary
# is functionally identical apart from the executable icon.

DEFS = {
    "kernel32": """LIBRARY KERNEL32.dll
EXPORTS
ExitProcess
GetModuleFileNameW
GetEnvironmentVariableW
GetFileAttributesW
CreateDirectoryW
CreateFileW
GetFileSizeEx
ReadFile
WriteFile
CloseHandle
CopyFileW
MoveFileExW
DeleteFileW
FindFirstFileW
FindNextFileW
FindClose
GetProcessHeap
HeapAlloc
HeapFree
CreateToolhelp32Snapshot
Process32FirstW
Process32NextW
GetCurrentProcessId
MultiByteToWideChar
GetCommandLineW
LocalFree
Sleep
CreateProcessW
""",
    "user32": """LIBRARY USER32.dll
EXPORTS
MessageBoxW
EnumWindows
GetWindowThreadProcessId
IsWindowVisible
ShowWindowAsync
SetForegroundWindow
""",
    "comdlg32": """LIBRARY COMDLG32.dll
EXPORTS
GetOpenFileNameW
""",
    "advapi32": """LIBRARY ADVAPI32.dll
EXPORTS
RegCreateKeyExW
RegSetValueExW
RegOpenKeyExW
RegQueryValueExW
RegCloseKey
RegDeleteTreeW
""",
    "shell32": """LIBRARY SHELL32.dll
EXPORTS
CommandLineToArgvW
ShellExecuteW
""",
}

MANIFEST = '''<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <assemblyIdentity version="1.0.2.0" processorArchitecture="amd64" name="RiichiCity.Stove.PrivateRoom.Patch" type="win32"/>
  <description>마작일번가 STOVE 개인실 패치</description>
  <trustInfo xmlns="urn:schemas-microsoft-com:asm.v3">
    <security><requestedPrivileges><requestedExecutionLevel level="asInvoker" uiAccess="false"/></requestedPrivileges></security>
  </trustInfo>
  <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
    <application>
      <supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}"/>
      <supportedOS Id="{4f476546-937d-4f3d-8f5f-31f18b040db8}"/>
    </application>
  </compatibility>
</assembly>
'''


def run(*args):
    print("+", " ".join(map(str, args)))
    subprocess.run(list(map(str, args)), cwd=ROOT, check=True)


def pad4(data: bytes) -> bytes:
    return data + b"\0" * ((-len(data)) % 4)


def res_record(rtype: int, rname: int, payload: bytes, lang: int = 0x0412, memflags: int = 0x1030) -> bytes:
    header = struct.pack("<HH", 0xFFFF, rtype) + struct.pack("<HH", 0xFFFF, rname)
    header += struct.pack("<IHHII", 0, memflags, lang, 0, 0)
    assert 8 + len(header) == 32
    return struct.pack("<II", len(payload), 32) + header + pad4(payload)


def make_res(path: Path) -> None:
    out = bytearray(res_record(0, 0, b"", 0))

    key = "VS_VERSION_INFO".encode("utf-16le") + b"\0\0"
    fixed = struct.pack(
        "<13I",
        0xFEEF04BD,
        0x00010000,
        0x00010000,
        0x00020000,
        0x00010000,
        0x00020000,
        0x3F,
        0,
        0x00040004,
        1,
        0,
        0,
        0,
    )
    body = struct.pack("<HHH", 0, 52, 0) + key
    body = pad4(body) + fixed
    body = struct.pack("<H", len(body)) + body[2:]
    out += res_record(16, 1, body)
    out += res_record(24, 1, MANIFEST.encode("utf-8"))
    path.write_bytes(out)


def main() -> None:
    clang = shutil.which("clang") or shutil.which("clang.exe")
    lld = shutil.which("lld-link") or shutil.which("lld-link.exe")
    if not clang or not lld:
        raise SystemExit("clang 및 lld-link가 PATH에 필요합니다. LLVM을 설치한 뒤 다시 실행하세요.")

    DIST.mkdir(exist_ok=True)
    temp = []
    try:
        for name, body in DEFS.items():
            definition = ROOT / f"{name}.def"
            definition.write_text(body, encoding="ascii")
            dummy = ROOT / f"{name}_dummy.dll"
            implib = ROOT / f"{name}.lib"
            temp += [definition, dummy, implib]
            run(
                lld,
                "/dll",
                f"/def:{definition.name}",
                f"/out:{dummy.name}",
                f"/implib:{implib.name}",
                "/noentry",
                "/machine:x64",
                "/timestamp:0",
            )

        obj = ROOT / "main.obj"
        res = ROOT / "app.res"
        temp += [obj, res]
        make_res(res)

        run(
            clang,
            "--target=x86_64-pc-windows-msvc",
            "-c",
            str(SRC.relative_to(ROOT)),
            "-o",
            obj.name,
            "-ffreestanding",
            "-fno-builtin",
            "-fno-stack-protector",
            "-mno-stack-arg-probe",
            "-Oz",
        )
        run(
            lld,
            obj.name,
            res.name,
            "kernel32.lib",
            "user32.lib",
            "comdlg32.lib",
            "advapi32.lib",
            "shell32.lib",
            "/subsystem:windows",
            "/entry:entry",
            "/nodefaultlib",
            f"/out:{OUT}",
            "/machine:x64",
            "/timestamp:0",
            "/opt:ref",
            "/opt:icf",
            "/stack:1048576,65536",
            "/manifest:no",
        )
        print("완료:", OUT)
    finally:
        for path in temp:
            try:
                path.unlink()
            except FileNotFoundError:
                pass


if __name__ == "__main__":
    main()
