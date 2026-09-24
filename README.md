# RiichiCity-Stove-PrivateRoom-Patch

마작일번가 STOVE PC판에서 공식 개인실 링크의 `room_id`를 실행 중인 게임에 전달하기 위한 **비공식 Windows 패치**입니다.

> 이 프로젝트는 마작일번가 운영사 및 STOVE와 관련이 없는 비공식 프로젝트입니다.  
> 로그인 인증을 우회하거나 계정 정보를 수집하지 않습니다.

## 지원 환경

- Windows 10 / Windows 11 64-bit
- 마작일번가 STOVE PC판
- 현재 소스 버전: **1.0.2**

## 동작 방식

공식 개인실 링크가 호출하는 다음 형식의 URI를 Windows 사용자 프로토콜로 등록합니다.

```text
hwdl://mainlink/path1?room_id=123456
```

처리 흐름은 다음과 같습니다.

```text
개인실 링크
  -> 6자리 room_id를 로컬 mailbox에 저장
  -> 마작일번가 실행 중: 기존 게임 창을 앞으로 표시
  -> 마작일번가 미실행 + STOVE 실행 중: 기존 STOVE 창을 앞으로 표시
  -> 둘 다 미실행: STOVE 로그인 화면을 한 번 요청
  -> 이후 로그인/게임 실행은 STOVE를 통한 직접 게임 실행 과정에 맡김
  -> 마작일번가 로그인 후 로비에 진입하면 room_id를 읽음
  -> mailbox 파일 삭제
  -> 게임의 기존 개인실 입장 기능 호출
```

패치는 STOVE 로그인 완료를 감시하거나 게임 실행 파일을 직접 시작하지 않습니다. STOVE가 이미 실행 중이면 추가 실행 요청도 보내지 않습니다.

## 변경 범위

설치 시 로컬에서 다음 게임 파일만 수정합니다.

```text
Mahjong-JP_Data\_Data\Mahjong\Base\lua_uiview_hall
Mahjong-JP_Data\_Data\Mahjong\Base\lua_helper
```

Windows 사용자 범위에는 다음 항목을 사용합니다.

```text
HKCU\Software\Classes\hwdl
%LOCALAPPDATA%\RiichiCityStovePrivateRoomPatch
%USERPROFILE%\AppData\LocalLow\HappyWoods\RiichiCity\hwdl_room.txt
```

게임 서버 프로토콜, 플레이 규칙, 계정/인증 데이터, 저장 데이터, `GameAssembly.dll`은 수정하지 않습니다.

## 개인정보 및 인증 정보

이 프로젝트는 다음 정보를 읽거나 저장하지 않습니다.

- STOVE 계정 ID/비밀번호
- `member_no`
- `auth_code`
- UUID
- 로그인/세션 토큰

STOVE 로그는 **마작일번가 설치 경로 자동 탐지**에 필요한 경로 문자열만 로컬에서 확인합니다. 찾지 못하면 사용자가 직접 `Mahjong-JP.exe`를 선택할 수 있습니다.

## 설치

GitHub Releases에서 배포 EXE를 내려받아 실행합니다.

설치 프로그램은 게임이 실행 중이면 설치를 진행하지 않으며, 수정 전 원본 파일을 사용자 로컬에 백업합니다.

## 제거

설치된 상태에서 같은 패처 EXE를 다시 실행하면 제거 여부를 확인합니다. 제거 시 설치 당시 백업한 원본 파일로 복구합니다.

게임 업데이트 등으로 대상 파일이 설치 이후 변경된 경우에는 안전을 위해 백업으로 강제 덮어쓰지 않고 STOVE의 게임 파일 검사를 안내합니다.

## 소스 빌드

### 요구 사항

- Python 3
- LLVM `clang`
- `lld-link`

빌드:

```powershell
python build.py
```

결과물:

```text
dist\RiichiCity-Stove-PrivateRoom-Patch-1.0.2.exe
```

공개 소스에는 배포용 아이콘 원본 데이터가 포함되어 있지 않습니다. 따라서 소스에서 직접 빌드한 EXE는 Release의 아이콘과 다를 수 있지만 기능은 동일합니다.

## 저장소에 포함하지 않는 것

이 저장소에는 다음 항목을 포함하지 않습니다.

- 마작일번가 원본 게임 파일
- 계정/인증/세션 정보
- 배포용 제3자 이미지 리소스

`src/main.c`에는 설치 대상 확인 및 패치 적용에 필요한 최소한의 식별 문자열만 포함됩니다.

## 주의사항

- 게임 업데이트로 내부 구조가 바뀌면 패치 적용이 거부될 수 있습니다.
- 설치가 거부되는 경우 임의로 다른 위치를 수정하지 않고 STOVE에서 게임 파일 검사를 먼저 진행하는 것을 권장합니다.
- 이 프로그램은 공식 지원 도구가 아닙니다. 사용 전 중요한 데이터는 별도로 백업하세요.

## 라이선스

이 저장소에서 작성한 패처 소스 코드는 [MIT License](LICENSE)로 배포합니다.

마작일번가/Riichi City 및 STOVE의 명칭, 상표, 게임 데이터와 기타 제3자 자산에 대한 권리는 각 권리자에게 있습니다. MIT License는 그러한 제3자 자산에 대한 권리를 부여하지 않습니다.
