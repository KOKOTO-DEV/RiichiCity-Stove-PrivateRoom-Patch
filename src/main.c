/*
 * RiichiCity-Stove-PrivateRoom-Patch
 * SPDX-License-Identifier: MIT
 *
 * This source contains only the patcher/handler implementation.
 * It does not include original game files, extracted assets, analysis dumps,
 * authentication tokens, or STOVE account data.
 */

#define UNICODE 1
#define _UNICODE 1

/* RiichiCity-Stove-PrivateRoom-Patch 1.0.2
   Native Win32, CRT-free. Distribution target: Windows x64.
*/

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned short WCHAR;
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned long long ULONG_PTR;
typedef long long LONG_PTR;
typedef unsigned long long SIZE_T;
typedef long long LONGLONG;
typedef ULONG_PTR UINT_PTR;
typedef LONG_PTR LPARAM;
typedef ULONG_PTR WPARAM;
typedef void *HANDLE;
typedef HANDLE HINSTANCE;
typedef HANDLE HWND;
typedef HANDLE HKEY;
typedef HANDLE HLOCAL;
typedef const WCHAR *LPCWSTR;
typedef WCHAR *LPWSTR;
typedef const void *LPCVOID;
typedef void *LPVOID;
typedef BYTE *LPBYTE;
typedef DWORD *LPDWORD;
typedef LONG LSTATUS;
typedef int BOOL;
typedef struct { DWORD dwLowDateTime; DWORD dwHighDateTime; } FILETIME;
typedef struct { LONGLONG QuadPart; } LARGE_INTEGER;

typedef struct {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[260];
    WCHAR cAlternateFileName[14];
} WIN32_FIND_DATAW;

typedef struct {
    DWORD dwSize;
    DWORD cntUsage;
    DWORD th32ProcessID;
    ULONG_PTR th32DefaultHeapID;
    DWORD th32ModuleID;
    DWORD cntThreads;
    DWORD th32ParentProcessID;
    LONG pcPriClassBase;
    DWORD dwFlags;
    WCHAR szExeFile[260];
} PROCESSENTRY32W;

typedef struct {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    BYTE *lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOW;

typedef struct {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION;

typedef UINT_PTR (*LPOFNHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
typedef struct {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpstrFilter;
    LPWSTR lpstrCustomFilter;
    DWORD nMaxCustFilter;
    DWORD nFilterIndex;
    LPWSTR lpstrFile;
    DWORD nMaxFile;
    LPWSTR lpstrFileTitle;
    DWORD nMaxFileTitle;
    LPCWSTR lpstrInitialDir;
    LPCWSTR lpstrTitle;
    DWORD Flags;
    WORD nFileOffset;
    WORD nFileExtension;
    LPCWSTR lpstrDefExt;
    LPARAM lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
    LPVOID pvReserved;
    DWORD dwReserved;
    DWORD FlagsEx;
} OPENFILENAMEW;

typedef BOOL (*WNDENUMPROC)(HWND, LPARAM);

#define WINAPI __stdcall
#define TRUE 1
#define FALSE 0
#define NULLPTR ((void*)0)
#define MAX_PATH_CHARS 2048
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define INVALID_FILE_ATTRIBUTES 0xFFFFFFFFUL
#define FILE_ATTRIBUTE_DIRECTORY 0x00000010UL
#define GENERIC_READ 0x80000000UL
#define GENERIC_WRITE 0x40000000UL
#define FILE_SHARE_READ 0x00000001UL
#define FILE_SHARE_WRITE 0x00000002UL
#define FILE_SHARE_DELETE 0x00000004UL
#define CREATE_ALWAYS 2UL
#define OPEN_EXISTING 3UL
#define FILE_ATTRIBUTE_NORMAL 0x00000080UL
#define MOVEFILE_REPLACE_EXISTING 0x00000001UL
#define MOVEFILE_WRITE_THROUGH 0x00000008UL
#define HEAP_ZERO_MEMORY 0x00000008UL
#define TH32CS_SNAPPROCESS 0x00000002UL
#define CP_ACP 0UL
#define CP_UTF8 65001UL
#define KEY_READ 0x20019UL
#define KEY_WRITE 0x20006UL
#define REG_SZ 1UL
#define REG_OPTION_NON_VOLATILE 0UL
#define ERROR_SUCCESS 0L
#define MB_OK 0x00000000UL
#define MB_OKCANCEL 0x00000001UL
#define MB_YESNO 0x00000004UL
#define MB_YESNOCANCEL 0x00000003UL
#define MB_ICONERROR 0x00000010UL
#define MB_ICONQUESTION 0x00000020UL
#define MB_ICONINFORMATION 0x00000040UL
#define MB_ICONWARNING 0x00000030UL
#define MB_SETFOREGROUND 0x00010000UL
#define IDOK 1
#define IDCANCEL 2
#define IDYES 6
#define IDNO 7
#define OFN_READONLY 0x00000001UL
#define OFN_NOCHANGEDIR 0x00000008UL
#define OFN_PATHMUSTEXIST 0x00000800UL
#define OFN_FILEMUSTEXIST 0x00001000UL
#define SW_HIDE 0
#define SW_RESTORE 9
#define CREATE_NO_WINDOW 0x08000000UL

#define HKEY_CLASSES_ROOT ((HKEY)(ULONG_PTR)0x80000000UL)
#define HKEY_CURRENT_USER ((HKEY)(ULONG_PTR)0x80000001UL)

__declspec(dllimport) void WINAPI ExitProcess(UINT);
__declspec(dllimport) DWORD WINAPI GetModuleFileNameW(HINSTANCE, LPWSTR, DWORD);
__declspec(dllimport) DWORD WINAPI GetEnvironmentVariableW(LPCWSTR, LPWSTR, DWORD);
__declspec(dllimport) DWORD WINAPI GetFileAttributesW(LPCWSTR);
__declspec(dllimport) BOOL WINAPI CreateDirectoryW(LPCWSTR, LPVOID);
__declspec(dllimport) HANDLE WINAPI CreateFileW(LPCWSTR, DWORD, DWORD, LPVOID, DWORD, DWORD, HANDLE);
__declspec(dllimport) BOOL WINAPI GetFileSizeEx(HANDLE, LARGE_INTEGER*);
__declspec(dllimport) BOOL WINAPI ReadFile(HANDLE, LPVOID, DWORD, LPDWORD, LPVOID);
__declspec(dllimport) BOOL WINAPI WriteFile(HANDLE, LPCVOID, DWORD, LPDWORD, LPVOID);
__declspec(dllimport) BOOL WINAPI CloseHandle(HANDLE);
__declspec(dllimport) BOOL WINAPI CopyFileW(LPCWSTR, LPCWSTR, BOOL);
__declspec(dllimport) BOOL WINAPI MoveFileExW(LPCWSTR, LPCWSTR, DWORD);
__declspec(dllimport) BOOL WINAPI DeleteFileW(LPCWSTR);
__declspec(dllimport) HANDLE WINAPI FindFirstFileW(LPCWSTR, WIN32_FIND_DATAW*);
__declspec(dllimport) BOOL WINAPI FindNextFileW(HANDLE, WIN32_FIND_DATAW*);
__declspec(dllimport) BOOL WINAPI FindClose(HANDLE);
__declspec(dllimport) HANDLE WINAPI GetProcessHeap(void);
__declspec(dllimport) LPVOID WINAPI HeapAlloc(HANDLE, DWORD, SIZE_T);
__declspec(dllimport) BOOL WINAPI HeapFree(HANDLE, DWORD, LPVOID);
__declspec(dllimport) HANDLE WINAPI CreateToolhelp32Snapshot(DWORD, DWORD);
__declspec(dllimport) BOOL WINAPI Process32FirstW(HANDLE, PROCESSENTRY32W*);
__declspec(dllimport) BOOL WINAPI Process32NextW(HANDLE, PROCESSENTRY32W*);
__declspec(dllimport) DWORD WINAPI GetCurrentProcessId(void);
__declspec(dllimport) int WINAPI MultiByteToWideChar(UINT, DWORD, const char*, int, LPWSTR, int);
__declspec(dllimport) LPWSTR WINAPI GetCommandLineW(void);
__declspec(dllimport) HLOCAL WINAPI LocalFree(HLOCAL);
__declspec(dllimport) void WINAPI Sleep(DWORD);
__declspec(dllimport) BOOL WINAPI CreateProcessW(LPCWSTR, LPWSTR, LPVOID, LPVOID, BOOL, DWORD, LPVOID, LPCWSTR, STARTUPINFOW*, PROCESS_INFORMATION*);

__declspec(dllimport) int WINAPI MessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT);
__declspec(dllimport) BOOL WINAPI EnumWindows(WNDENUMPROC, LPARAM);
__declspec(dllimport) DWORD WINAPI GetWindowThreadProcessId(HWND, LPDWORD);
__declspec(dllimport) BOOL WINAPI IsWindowVisible(HWND);
__declspec(dllimport) BOOL WINAPI ShowWindowAsync(HWND, int);
__declspec(dllimport) BOOL WINAPI SetForegroundWindow(HWND);

__declspec(dllimport) BOOL WINAPI GetOpenFileNameW(OPENFILENAMEW*);

__declspec(dllimport) LSTATUS WINAPI RegCreateKeyExW(HKEY,LPCWSTR,DWORD,LPWSTR,DWORD,DWORD,LPVOID,HKEY*,LPDWORD);
__declspec(dllimport) LSTATUS WINAPI RegSetValueExW(HKEY,LPCWSTR,DWORD,DWORD,const BYTE*,DWORD);
__declspec(dllimport) LSTATUS WINAPI RegOpenKeyExW(HKEY,LPCWSTR,DWORD,DWORD,HKEY*);
__declspec(dllimport) LSTATUS WINAPI RegQueryValueExW(HKEY,LPCWSTR,LPDWORD,LPDWORD,LPBYTE,LPDWORD);
__declspec(dllimport) LSTATUS WINAPI RegCloseKey(HKEY);
__declspec(dllimport) LSTATUS WINAPI RegDeleteTreeW(HKEY,LPCWSTR);

__declspec(dllimport) LPWSTR* WINAPI CommandLineToArgvW(LPCWSTR, int*);
__declspec(dllimport) HINSTANCE WINAPI ShellExecuteW(HWND,LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR,int);

void *memcpy(void *dst, const void *src, SIZE_T n) { BYTE *d=(BYTE*)dst; const BYTE *s=(const BYTE*)src; SIZE_T i; for(i=0;i<n;i++) d[i]=s[i]; return dst; }
void *memset(void *dst, int v, SIZE_T n) { BYTE *d=(BYTE*)dst; SIZE_T i; for(i=0;i<n;i++) d[i]=(BYTE)v; return dst; }
int memcmp(const void *a,const void *b,SIZE_T n){const BYTE*x=(const BYTE*)a,*y=(const BYTE*)b;SIZE_T i;for(i=0;i<n;i++){if(x[i]!=y[i])return x[i]<y[i]?-1:1;}return 0;}

static const WCHAR TITLE[] = L"마작일번가 STOVE 개인실 패치 1.0.2";
static const WCHAR APPDIR_NAME[] = L"RiichiCityStovePrivateRoomPatch";
static const WCHAR APP_EXE_NAME[] = L"RiichiCity-Stove-PrivateRoom-Patch-1.0.2.exe";
static const WCHAR PREV_EXE_NAME[] = L"RiichiCity-Stove-PrivateRoom-Patch-1.0.1.exe";
static const WCHAR PREV2_EXE_NAME[] = L"RiichiCity-Stove-PrivateRoom-Patch-1.0.0.exe";
static const WCHAR STATE_NAME[] = L"game_root.dat";
static const WCHAR BACKUP_DIR_NAME[] = L"backup";
static const WCHAR HALL_REL[] = L"Mahjong-JP_Data\\_Data\\Mahjong\\Base\\lua_uiview_hall";
static const WCHAR HELPER_REL[] = L"Mahjong-JP_Data\\_Data\\Mahjong\\Base\\lua_helper";
static const WCHAR GAME_EXE[] = L"Mahjong-JP.exe";
static const WCHAR STOVE_EXE[] = L"STOVE.exe";

static SIZE_T wlen(const WCHAR *s){SIZE_T n=0;if(!s)return 0;while(s[n])n++;return n;}
static SIZE_T alen(const char *s){SIZE_T n=0;if(!s)return 0;while(s[n])n++;return n;}
static WCHAR lower_ascii_w(WCHAR c){if(c>='A'&&c<='Z')return (WCHAR)(c+32);return c;}
static int weq_ci(const WCHAR*a,const WCHAR*b){SIZE_T i=0;if(!a||!b)return 0;while(a[i]&&b[i]){if(lower_ascii_w(a[i])!=lower_ascii_w(b[i]))return 0;i++;}return a[i]==0&&b[i]==0;}
static int wpref_ci(const WCHAR*s,const WCHAR*p){SIZE_T i=0;if(!s||!p)return 0;while(p[i]){if(!s[i]||lower_ascii_w(s[i])!=lower_ascii_w(p[i]))return 0;i++;}return 1;}
static int wcontains_ci(const WCHAR*s,const WCHAR*needle){SIZE_T i,j,n=wlen(s),m=wlen(needle);if(m==0)return 1;if(m>n)return 0;for(i=0;i+m<=n;i++){for(j=0;j<m;j++)if(lower_ascii_w(s[i+j])!=lower_ascii_w(needle[j]))break;if(j==m)return 1;}return 0;}
static int wcopy(WCHAR*out,SIZE_T cap,const WCHAR*s){SIZE_T n=wlen(s),i;if(n+1>cap)return 0;for(i=0;i<=n;i++)out[i]=s[i];return 1;}
static int wcat(WCHAR*out,SIZE_T cap,const WCHAR*s){SIZE_T n=wlen(out),m=wlen(s),i;if(n+m+1>cap)return 0;for(i=0;i<=m;i++)out[n+i]=s[i];return 1;}
static int join_path(WCHAR*out,SIZE_T cap,const WCHAR*a,const WCHAR*b){if(!wcopy(out,cap,a))return 0;SIZE_T n=wlen(out);if(n&&out[n-1]!='\\'&&out[n-1]!='/'){if(!wcat(out,cap,L"\\"))return 0;}return wcat(out,cap,b);}
static void strip_trailing_slash(WCHAR*s){SIZE_T n=wlen(s);while(n>3&&(s[n-1]=='\\'||s[n-1]=='/')){s[n-1]=0;n--;}}
static int file_exists(const WCHAR*p){DWORD a=GetFileAttributesW(p);return a!=INVALID_FILE_ATTRIBUTES&&!(a&FILE_ATTRIBUTE_DIRECTORY);}
static int dir_exists(const WCHAR*p){DWORD a=GetFileAttributesW(p);return a!=INVALID_FILE_ATTRIBUTES&&(a&FILE_ATTRIBUTE_DIRECTORY);}

static int ensure_dir_chain(const WCHAR *path){
    WCHAR *tmp=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));
    SIZE_T i,n;if(!tmp)return 0;if(!wcopy(tmp,MAX_PATH_CHARS,path)){HeapFree(GetProcessHeap(),0,tmp);return 0;}strip_trailing_slash(tmp);n=wlen(tmp);
    for(i=3;i<n;i++){if(tmp[i]=='\\'||tmp[i]=='/'){WCHAR c=tmp[i];tmp[i]=0;if(!dir_exists(tmp))CreateDirectoryW(tmp,NULLPTR);tmp[i]=c;}}
    if(!dir_exists(tmp))CreateDirectoryW(tmp,NULLPTR);
    i=dir_exists(tmp);HeapFree(GetProcessHeap(),0,tmp);return (int)i;
}

static void show_error(const WCHAR *msg){MessageBoxW(NULLPTR,msg,TITLE,MB_OK|MB_ICONERROR|MB_SETFOREGROUND);}
static void show_info(const WCHAR *msg){MessageBoxW(NULLPTR,msg,TITLE,MB_OK|MB_ICONINFORMATION|MB_SETFOREGROUND);}

static int get_env_path(const WCHAR*name,WCHAR*out,SIZE_T cap){DWORD n=GetEnvironmentVariableW(name,out,(DWORD)cap);return n>0&&n<cap;}
static int get_app_root(WCHAR*out,SIZE_T cap){WCHAR *base=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!base)return 0;if(get_env_path(L"LOCALAPPDATA",base,MAX_PATH_CHARS))ok=join_path(out,cap,base,APPDIR_NAME);HeapFree(GetProcessHeap(),0,base);return ok;}
static int get_installed_exe(WCHAR*out,SIZE_T cap){WCHAR *root=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!root)return 0;if(get_app_root(root,MAX_PATH_CHARS))ok=join_path(out,cap,root,APP_EXE_NAME);HeapFree(GetProcessHeap(),0,root);return ok;}
static int get_state_path(WCHAR*out,SIZE_T cap){WCHAR *root=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!root)return 0;if(get_app_root(root,MAX_PATH_CHARS))ok=join_path(out,cap,root,STATE_NAME);HeapFree(GetProcessHeap(),0,root);return ok;}
static int get_mailbox_dir(WCHAR*out,SIZE_T cap){WCHAR *u=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!u)return 0;if(get_env_path(L"USERPROFILE",u,MAX_PATH_CHARS))ok=join_path(out,cap,u,L"AppData\\LocalLow\\HappyWoods\\RiichiCity");HeapFree(GetProcessHeap(),0,u);return ok;}
static int get_mailbox(WCHAR*out,SIZE_T cap){WCHAR *d=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!d)return 0;if(get_mailbox_dir(d,MAX_PATH_CHARS))ok=join_path(out,cap,d,L"hwdl_room.txt");HeapFree(GetProcessHeap(),0,d);return ok;}

static int process_running_pid(const WCHAR *exe,DWORD *pidOut){
    HANDLE snap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);PROCESSENTRY32W pe;if(snap==INVALID_HANDLE_VALUE)return 0;memset(&pe,0,sizeof(pe));pe.dwSize=sizeof(pe);
    if(Process32FirstW(snap,&pe)){do{if(weq_ci(pe.szExeFile,exe)){if(pidOut)*pidOut=pe.th32ProcessID;CloseHandle(snap);return 1;}}while(Process32NextW(snap,&pe));}
    CloseHandle(snap);return 0;
}

static DWORD g_target_pid=0;static HWND g_target_hwnd=NULLPTR;
static BOOL WINAPI enum_windows_cb(HWND h,LPARAM lp){DWORD pid=0;(void)lp;GetWindowThreadProcessId(h,&pid);if(pid==g_target_pid&&IsWindowVisible(h)){g_target_hwnd=h;return FALSE;}return TRUE;}
static void foreground_pid(DWORD pid){if(!pid)return;g_target_pid=pid;g_target_hwnd=NULLPTR;EnumWindows(enum_windows_cb,0);if(g_target_hwnd){ShowWindowAsync(g_target_hwnd,SW_RESTORE);SetForegroundWindow(g_target_hwnd);}}
static void foreground_game(void){DWORD pid=0;if(process_running_pid(GAME_EXE,&pid))foreground_pid(pid);}

struct Buffer{BYTE*data;SIZE_T len;};
#define STATE_MAGIC 0x31525052UL /* RPR1 */
struct PatchState {
    DWORD magic;
    DWORD version;
    unsigned long long hallPatchedHash;
    unsigned long long helperPatchedHash;
    WCHAR gameRoot[MAX_PATH_CHARS];
};
static unsigned long long fnv1a64(const BYTE*d,SIZE_T n){unsigned long long h=1469598103934665603ULL;SIZE_T i;for(i=0;i<n;i++){h^=d[i];h*=1099511628211ULL;}return h;}
static void free_buffer(struct Buffer*b){if(b&&b->data){HeapFree(GetProcessHeap(),0,b->data);b->data=NULLPTR;b->len=0;}}
static int read_file(const WCHAR *path,struct Buffer*out){
    HANDLE h;LARGE_INTEGER sz;DWORD got=0;BYTE*buf;if(!out)return 0;out->data=NULLPTR;out->len=0;h=CreateFileW(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,NULLPTR,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULLPTR);if(h==INVALID_HANDLE_VALUE)return 0;
    if(!GetFileSizeEx(h,&sz)||sz.QuadPart<0||sz.QuadPart>64*1024*1024){CloseHandle(h);return 0;}buf=(BYTE*)HeapAlloc(GetProcessHeap(),0,(SIZE_T)sz.QuadPart+2);if(!buf){CloseHandle(h);return 0;}if(sz.QuadPart>0&&!ReadFile(h,buf,(DWORD)sz.QuadPart,&got,NULLPTR)){HeapFree(GetProcessHeap(),0,buf);CloseHandle(h);return 0;}CloseHandle(h);if((LONGLONG)got!=sz.QuadPart){HeapFree(GetProcessHeap(),0,buf);return 0;}buf[got]=0;buf[got+1]=0;out->data=buf;out->len=got;return 1;
}
static int write_file(const WCHAR *path,const void*data,SIZE_T len){HANDLE h;DWORD wrote=0;h=CreateFileW(path,GENERIC_WRITE,0,NULLPTR,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULLPTR);if(h==INVALID_HANDLE_VALUE)return 0;if(len&&!WriteFile(h,data,(DWORD)len,&wrote,NULLPTR)){CloseHandle(h);return 0;}CloseHandle(h);return wrote==(DWORD)len;}

static SIZE_T find_bytes_from(const BYTE*d,SIZE_T n,const char*needle,SIZE_T start){SIZE_T m=alen(needle),i;if(m==0)return start<=n?start:(SIZE_T)-1;if(m>n||start>n-m)return (SIZE_T)-1;for(i=start;i+m<=n;i++)if(memcmp(d+i,needle,m)==0)return i;return (SIZE_T)-1;}
static int starts_ascii(const BYTE*d,SIZE_T n,SIZE_T pos,const char*s){SIZE_T m=alen(s);return pos+m<=n&&memcmp(d+pos,s,m)==0;}

static int patch_hall(const struct Buffer*in,struct Buffer*out){
    const char *mainfn="function M:OnShow(is_from_login,aim_type,trigger_rank_guide)";
    const char *check="        if not CommonHelper.CheckClipborad() then";
    const char *flow="        CommonHelper.GameFlowLog(\"homepage3_visit\")";
    const char *n1="        local h=CommonHelper.CheckClipborad";
    const char *n2="        self.timerTable:Append(h,1,-1)";
    SIZE_T on,cp,lineStart,prevLf,c1s,c1e,c1l,fp,lf,c2s,c2e,c2l,i;BYTE*b;
    out->data=NULLPTR;out->len=0;on=find_bytes_from(in->data,in->len,mainfn,0);if(on==(SIZE_T)-1)return 0;cp=find_bytes_from(in->data,in->len,check,on);if(cp==(SIZE_T)-1)return 0;
    lineStart=cp;while(lineStart>0&&in->data[lineStart-1]!='\n')lineStart--;if(lineStart==0)return 0;prevLf=lineStart-1;c1e=prevLf;if(c1e>0&&in->data[c1e-1]=='\r')c1e--;c1s=c1e;while(c1s>0&&in->data[c1s-1]!='\n')c1s--;c1l=c1e-c1s;if(!starts_ascii(in->data,in->len,c1s,"        --")||alen(n1)>c1l)return 0;
    fp=find_bytes_from(in->data,in->len,flow,cp);if(fp==(SIZE_T)-1)return 0;lf=fp;while(lf<in->len&&in->data[lf]!='\n')lf++;if(lf>=in->len)return 0;c2s=lf+1;c2e=c2s;while(c2e<in->len&&in->data[c2e]!='\n')c2e++;if(c2e>=in->len)return 0;if(c2e>c2s&&in->data[c2e-1]=='\r')c2e--;c2l=c2e-c2s;if(!starts_ascii(in->data,in->len,c2s,"        --")||alen(n2)>c2l)return 0;
    b=(BYTE*)HeapAlloc(GetProcessHeap(),0,in->len);if(!b)return 0;memcpy(b,in->data,in->len);for(i=0;i<c1l;i++)b[c1s+i]=' ';memcpy(b+c1s,n1,alen(n1));for(i=0;i<c2l;i++)b[c2s+i]=' ';memcpy(b+c2s,n2,alen(n2));out->data=b;out->len=in->len;return 1;
}

static int patch_helper(const struct Buffer*in,struct Buffer*out){
    const char *startN="function M.CheckClipborad()";const char *nextN="function M.CheckDeepLink()";
    const char *required1="GetTextFromClipborad";const char *required2="CopyTextToClipboard";
    const char *newCode=
"function M.CheckClipborad()\n"
"    if csharp.Application.isMobilePlatform then return end\n"
"    local p=csharp.Application.persistentDataPath..\"/hwdl_room.txt\"\n"
"    if not System.IO.File.Exists(p) then return end\n"
"    local id=System.IO.File.ReadAllText(p)\n"
"    System.IO.File.Delete(p)\n"
"    if id==nil or id==\"\" then return end\n"
"    if string.match(id,\"^%d%d%d%d%d%d$\") then\n"
"        GameModules.ModelMgr:GetModel(EModelType.FriendRoom):enterFriendMatch(id)\n"
"        return true\n"
"    end\n"
"end\n\n\n";
    SIZE_T s,e,region,i;BYTE*b;out->data=NULLPTR;out->len=0;s=find_bytes_from(in->data,in->len,startN,0);if(s==(SIZE_T)-1)return 0;e=find_bytes_from(in->data,in->len,nextN,s);if(e==(SIZE_T)-1||e<=s)return 0;region=e-s;
    if(find_bytes_from(in->data,e,required1,s)==(SIZE_T)-1||find_bytes_from(in->data,e,required2,s)==(SIZE_T)-1)return 0;if(find_bytes_from(in->data,e,"hwdl_room.txt",s)!=(SIZE_T)-1)return 0;if(alen(newCode)>region)return 0;
    b=(BYTE*)HeapAlloc(GetProcessHeap(),0,in->len);if(!b)return 0;memcpy(b,in->data,in->len);for(i=0;i<region;i++)b[s+i]=' ';memcpy(b+s,newCode,alen(newCode));out->data=b;out->len=in->len;return 1;
}

static int utf8_to_wide(const BYTE*src,SIZE_T len,WCHAR*out,SIZE_T cap){int n;if(!src||!out||cap<2)return 0;n=MultiByteToWideChar(CP_UTF8,0,(const char*)src,(int)len,out,(int)(cap-1));if(n<=0)n=MultiByteToWideChar(CP_ACP,0,(const char*)src,(int)len,out,(int)(cap-1));if(n<=0)return 0;out[n]=0;return 1;}

static int validate_game_root(const WCHAR*root){WCHAR*p=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!p)return 0;if(join_path(p,MAX_PATH_CHARS,root,GAME_EXE)&&file_exists(p)&&join_path(p,MAX_PATH_CHARS,root,HALL_REL)&&file_exists(p)&&join_path(p,MAX_PATH_CHARS,root,HELPER_REL)&&file_exists(p))ok=1;HeapFree(GetProcessHeap(),0,p);return ok;}

static SIZE_T find_ascii_range(const BYTE*d,SIZE_T n,const char*needle,SIZE_T start,SIZE_T end){SIZE_T m=alen(needle),i;if(end>n)end=n;if(m==0||start>=end||m>end-start)return (SIZE_T)-1;for(i=start;i+m<=end;i++)if(memcmp(d+i,needle,m)==0)return i;return (SIZE_T)-1;}
static int detect_candidate_from_line(const BYTE*d,SIZE_T ls,SIZE_T le,WCHAR*out,SIZE_T cap){
    SIZE_T a,b,m;
    a=find_ascii_range(d,le,"gameId=RIICHICITY_IND",ls,le);if(a!=(SIZE_T)-1){a=find_ascii_range(d,le,"installPath=",ls,le);if(a!=(SIZE_T)-1){a+=alen("installPath=");b=find_ascii_range(d,le," driveModel=",a,le);if(b==(SIZE_T)-1)b=le;while(b>a&&(d[b-1]=='\r'||d[b-1]==' '))b--;if(utf8_to_wide(d+a,b-a,out,cap)&&validate_game_root(out))return 1;}}
    m=find_ascii_range(d,le,"game manifest : ",ls,le);if(m!=(SIZE_T)-1){a=m+alen("game manifest : ");b=find_ascii_range(d,le,"\\combinedata_manifest\\GameManifest_RIICHICITY_IND.upf",a,le);if(b!=(SIZE_T)-1&&utf8_to_wide(d+a,b-a,out,cap)&&validate_game_root(out))return 1;}
    m=find_ascii_range(d,le,"Game Launched exe_path: ",ls,le);if(m!=(SIZE_T)-1){a=m+alen("Game Launched exe_path: ");b=find_ascii_range(d,le,"\\Mahjong-JP.exe",a,le);if(b!=(SIZE_T)-1&&utf8_to_wide(d+a,b-a,out,cap)&&validate_game_root(out))return 1;}
    return 0;
}

static int detect_game_from_stove(WCHAR*out,SIZE_T cap){
    WCHAR *local=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));WCHAR *dir=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));WCHAR *pattern=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));WCHAR *path=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));HANDLE ff;WIN32_FIND_DATAW fd;int found=0;
    if(!local||!dir||!pattern||!path)goto done;if(!get_env_path(L"LOCALAPPDATA",local,MAX_PATH_CHARS))goto done;if(!join_path(dir,MAX_PATH_CHARS,local,L"STOVE\\Logs\\StoveLauncher"))goto done;if(!join_path(pattern,MAX_PATH_CHARS,dir,L"*.log"))goto done;ff=FindFirstFileW(pattern,&fd);if(ff==INVALID_HANDLE_VALUE)goto done;
    do{if(!(fd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)){struct Buffer b={0};SIZE_T ls=0,i;if(join_path(path,MAX_PATH_CHARS,dir,fd.cFileName)&&read_file(path,&b)){for(i=0;i<=b.len;i++){if(i==b.len||b.data[i]=='\n'){if(i>ls&&detect_candidate_from_line(b.data,ls,i,out,cap)){found=1;free_buffer(&b);break;}ls=i+1;}}free_buffer(&b);}if(found)break;}}while(FindNextFileW(ff,&fd));FindClose(ff);
 done:if(local)HeapFree(GetProcessHeap(),0,local);if(dir)HeapFree(GetProcessHeap(),0,dir);if(pattern)HeapFree(GetProcessHeap(),0,pattern);if(path)HeapFree(GetProcessHeap(),0,path);return found;
}

static int select_game_root(WCHAR*out,SIZE_T cap){
    OPENFILENAMEW ofn;WCHAR *file=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));SIZE_T n,i;if(!file)return 0;wcopy(file,MAX_PATH_CHARS,L"Mahjong-JP.exe");memset(&ofn,0,sizeof(ofn));ofn.lStructSize=sizeof(ofn);ofn.lpstrFilter=L"Mahjong-JP.exe\0Mahjong-JP.exe\0모든 파일\0*.*\0\0";ofn.lpstrFile=file;ofn.nMaxFile=MAX_PATH_CHARS;ofn.lpstrTitle=L"마작일번가 설치 폴더를 선택해 주세요";ofn.Flags=OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_NOCHANGEDIR;
    if(!GetOpenFileNameW(&ofn)){HeapFree(GetProcessHeap(),0,file);return 0;}n=wlen(file);i=n;while(i>0&&file[i-1]!='\\'&&file[i-1]!='/')i--;if(i==0){HeapFree(GetProcessHeap(),0,file);return 0;}file[i-1]=0;if(validate_game_root(file)&&wcopy(out,cap,file)){HeapFree(GetProcessHeap(),0,file);return 1;}HeapFree(GetProcessHeap(),0,file);show_error(L"선택한 위치가 올바른 마작일번가 설치 폴더가 아닙니다.");return 0;
}

static int detect_game_root(WCHAR*out,SIZE_T cap){if(detect_game_from_stove(out,cap))return 1;return select_game_root(out,cap);}

static int existing_foreign_hwdl(const WCHAR *installedExe){
    HKEY k=NULLPTR;DWORD type=0,cb=0;LSTATUS s;WCHAR *buf;int foreign=0;s=RegOpenKeyExW(HKEY_CURRENT_USER,L"Software\\Classes\\hwdl\\shell\\open\\command",0,KEY_READ,&k);if(s!=ERROR_SUCCESS)return 0;s=RegQueryValueExW(k,NULLPTR,NULLPTR,&type,NULLPTR,&cb);if(s==ERROR_SUCCESS&&type==REG_SZ&&cb>2&&cb<32768){buf=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,cb+2);if(buf){if(RegQueryValueExW(k,NULLPTR,NULLPTR,&type,(LPBYTE)buf,&cb)==ERROR_SUCCESS){if(!wcontains_ci(buf,installedExe)&&!wcontains_ci(buf,APP_EXE_NAME)&&!wcontains_ci(buf,PREV_EXE_NAME)&&!wcontains_ci(buf,PREV2_EXE_NAME))foreign=1;}HeapFree(GetProcessHeap(),0,buf);}}RegCloseKey(k);return foreign;
}

static int register_protocol(const WCHAR*installedExe){
    HKEY k=NULLPTR;DWORD disp=0;WCHAR *cmd=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));WCHAR *icon=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!cmd||!icon)goto done;
    if(RegCreateKeyExW(HKEY_CURRENT_USER,L"Software\\Classes\\hwdl",0,NULLPTR,REG_OPTION_NON_VOLATILE,KEY_WRITE,NULLPTR,&k,&disp)!=ERROR_SUCCESS)goto done;
    {const WCHAR*d=L"URL:마작일번가 STOVE 개인실";const WCHAR*e=L"";if(RegSetValueExW(k,NULLPTR,0,REG_SZ,(const BYTE*)d,(DWORD)((wlen(d)+1)*sizeof(WCHAR)))!=ERROR_SUCCESS){RegCloseKey(k);k=NULLPTR;goto done;}if(RegSetValueExW(k,L"URL Protocol",0,REG_SZ,(const BYTE*)e,sizeof(WCHAR))!=ERROR_SUCCESS){RegCloseKey(k);k=NULLPTR;goto done;}RegCloseKey(k);k=NULLPTR;}
    if(RegCreateKeyExW(HKEY_CURRENT_USER,L"Software\\Classes\\hwdl\\DefaultIcon",0,NULLPTR,REG_OPTION_NON_VOLATILE,KEY_WRITE,NULLPTR,&k,&disp)!=ERROR_SUCCESS)goto done;wcopy(icon,MAX_PATH_CHARS,L"\"");wcat(icon,MAX_PATH_CHARS,installedExe);wcat(icon,MAX_PATH_CHARS,L"\",0");if(RegSetValueExW(k,NULLPTR,0,REG_SZ,(const BYTE*)icon,(DWORD)((wlen(icon)+1)*sizeof(WCHAR)))!=ERROR_SUCCESS){RegCloseKey(k);k=NULLPTR;goto done;}RegCloseKey(k);k=NULLPTR;
    if(RegCreateKeyExW(HKEY_CURRENT_USER,L"Software\\Classes\\hwdl\\shell\\open\\command",0,NULLPTR,REG_OPTION_NON_VOLATILE,KEY_WRITE,NULLPTR,&k,&disp)!=ERROR_SUCCESS)goto done;wcopy(cmd,MAX_PATH_CHARS,L"\"");wcat(cmd,MAX_PATH_CHARS,installedExe);wcat(cmd,MAX_PATH_CHARS,L"\" --hwdl \"%1\"");if(RegSetValueExW(k,NULLPTR,0,REG_SZ,(const BYTE*)cmd,(DWORD)((wlen(cmd)+1)*sizeof(WCHAR)))!=ERROR_SUCCESS){RegCloseKey(k);k=NULLPTR;goto done;}RegCloseKey(k);k=NULLPTR;ok=1;
 done:if(k)RegCloseKey(k);if(cmd)HeapFree(GetProcessHeap(),0,cmd);if(icon)HeapFree(GetProcessHeap(),0,icon);return ok;
}

static int write_state(const WCHAR*root,unsigned long long hallHash,unsigned long long helperHash){
    WCHAR*p=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));struct PatchState st;int ok=0;if(!p)return 0;memset(&st,0,sizeof(st));st.magic=STATE_MAGIC;st.version=1;st.hallPatchedHash=hallHash;st.helperPatchedHash=helperHash;if(!wcopy(st.gameRoot,MAX_PATH_CHARS,root)){HeapFree(GetProcessHeap(),0,p);return 0;}if(get_state_path(p,MAX_PATH_CHARS))ok=write_file(p,&st,sizeof(st));HeapFree(GetProcessHeap(),0,p);return ok;
}
static int read_state(struct PatchState*out){WCHAR*p=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));struct Buffer b={0};int ok=0;if(!p||!out)return 0;memset(out,0,sizeof(*out));if(get_state_path(p,MAX_PATH_CHARS)&&read_file(p,&b)&&b.len==sizeof(*out)){memcpy(out,b.data,sizeof(*out));if(out->magic==STATE_MAGIC&&out->version==1&&out->gameRoot[0])ok=1;}free_buffer(&b);HeapFree(GetProcessHeap(),0,p);return ok;}


static int open_stove_uri(const WCHAR *uri){
    HINSTANCE r;
    if(!uri||!uri[0])return 0;
    r=ShellExecuteW(NULLPTR,L"open",uri,NULLPTR,NULLPTR,SW_RESTORE);
    return (LONG_PTR)r>32;
}

/*
 * STOVE must own the authentication/bootstrap path.
 * Never start Mahjong-JP.exe directly: the game-side STOVE SDK expects the
 * launcher session and per-game IPC/bootstrap to have been prepared first.
 */
static int show_stove_if_needed(void){
    DWORD pid=0;

    /*
     * 1.0.2 deliberately stops at the STOVE launcher.
     * - If the game is already running, only bring that existing window forward.
     * - If STOVE is already running, do not issue another sgup launch request;
     *   only bring the existing launcher window forward.
     * - If STOVE is not running, launch the normal STOVE login flow once.
     *
     * Login, authentication, game launch and bootstrap remain entirely owned by
     * STOVE.  The queued room id stays in the mailbox until the game reaches
     * the lobby and consumes it.
     */
    if(process_running_pid(GAME_EXE,&pid)){
        foreground_pid(pid);
        return 1;
    }

    if(process_running_pid(STOVE_EXE,&pid)){
        foreground_pid(pid);
        return 1;
    }

    return open_stove_uri(L"sgup://util/login");
}

static int apply_target(const WCHAR*target,const BYTE*data,SIZE_T len){WCHAR*tmp=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));int ok=0;if(!tmp)return 0;if(wcopy(tmp,MAX_PATH_CHARS,target)&&wcat(tmp,MAX_PATH_CHARS,L".private-room.tmp")&&write_file(tmp,data,len)){if(MoveFileExW(tmp,target,MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH))ok=1;else DeleteFileW(tmp);}HeapFree(GetProcessHeap(),0,tmp);return ok;}

static int install_patch(void){
    WCHAR *root=NULLPTR,*hall=NULLPTR,*helper=NULLPTR,*appRoot=NULLPTR,*backupDir=NULLPTR,*bh=NULLPTR,*bp=NULLPTR,*self=NULLPTR,*installed=NULLPTR;struct Buffer ho={0},he={0},hp={0},hep={0};DWORD pid=0;int ok=0;
    if(process_running_pid(GAME_EXE,&pid)){show_error(L"마작일번가가 실행 중입니다. 게임을 완전히 종료한 뒤 다시 설치해 주세요.");return 0;}
    root=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));hall=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));helper=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));appRoot=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));backupDir=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));bh=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));bp=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));self=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));installed=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));
    if(!root||!hall||!helper||!appRoot||!backupDir||!bh||!bp||!self||!installed)goto done;
    if(!detect_game_root(root,MAX_PATH_CHARS))goto done;if(!join_path(hall,MAX_PATH_CHARS,root,HALL_REL)||!join_path(helper,MAX_PATH_CHARS,root,HELPER_REL))goto done;if(!get_app_root(appRoot,MAX_PATH_CHARS)||!get_installed_exe(installed,MAX_PATH_CHARS))goto done;
    if(existing_foreign_hwdl(installed)){show_error(L"다른 프로그램이 이미 hwdl:// 연결을 사용하고 있습니다. 기존 설정을 보호하기 위해 설치를 중단합니다.");goto done;}
    if(!read_file(hall,&ho)||!read_file(helper,&he)){show_error(L"게임 파일을 읽을 수 없습니다. 설치 폴더 권한을 확인해 주세요.");goto done;}
    if(!patch_hall(&ho,&hp)||!patch_helper(&he,&hep)){show_error(L"현재 게임 파일이 이 패치가 지원하는 순정 상태와 일치하지 않습니다. STOVE에서 게임 파일을 복구한 뒤 다시 시도해 주세요.");goto done;}
    if(!ensure_dir_chain(appRoot))goto done;if(!join_path(backupDir,MAX_PATH_CHARS,appRoot,BACKUP_DIR_NAME)||!ensure_dir_chain(backupDir))goto done;if(!join_path(bh,MAX_PATH_CHARS,backupDir,L"lua_uiview_hall.original")||!join_path(bp,MAX_PATH_CHARS,backupDir,L"lua_helper.original"))goto done;
    if(!CopyFileW(hall,bh,FALSE)||!CopyFileW(helper,bp,FALSE)){show_error(L"원본 게임 파일 백업에 실패했습니다.");goto done;}
    if(!apply_target(hall,hp.data,hp.len)||!apply_target(helper,hep.data,hep.len)){CopyFileW(bh,hall,FALSE);CopyFileW(bp,helper,FALSE);show_error(L"게임 파일 패치 적용에 실패했습니다. 원본 파일로 복구했습니다.\n\n쓰기 권한이 없다면 관리자 권한으로 다시 실행해 주세요.");goto done;}
    GetModuleFileNameW(NULLPTR,self,MAX_PATH_CHARS);if(!weq_ci(self,installed)&&!CopyFileW(self,installed,FALSE)){CopyFileW(bh,hall,FALSE);CopyFileW(bp,helper,FALSE);show_error(L"패치 실행 파일 설치에 실패했습니다. 게임 파일은 원래 상태로 복구했습니다.");goto done;}
    if(!register_protocol(installed)||!write_state(root,fnv1a64(hp.data,hp.len),fnv1a64(hep.data,hep.len))){WCHAR sp[MAX_PATH_CHARS];CopyFileW(bh,hall,FALSE);CopyFileW(bp,helper,FALSE);RegDeleteTreeW(HKEY_CURRENT_USER,L"Software\\Classes\\hwdl");if(get_state_path(sp,MAX_PATH_CHARS))DeleteFileW(sp);if(!weq_ci(self,installed))DeleteFileW(installed);show_error(L"Windows hwdl:// 연결 등록에 실패했습니다. 게임 파일은 원래 상태로 복구했습니다.");goto done;}
    show_info(L"설치가 완료되었습니다.\n\n개인실 링크를 열면 실행 중인 마작일번가로 바로 입장합니다. 게임이 꺼져 있으면 STOVE 런처만 열거나 이미 실행 중인 STOVE 창을 앞으로 표시합니다. 이후 로그인과 게임 실행은 STOVE에서 평소대로 진행해 주세요.");ok=1;
 done:free_buffer(&ho);free_buffer(&he);free_buffer(&hp);free_buffer(&hep);if(root)HeapFree(GetProcessHeap(),0,root);if(hall)HeapFree(GetProcessHeap(),0,hall);if(helper)HeapFree(GetProcessHeap(),0,helper);if(appRoot)HeapFree(GetProcessHeap(),0,appRoot);if(backupDir)HeapFree(GetProcessHeap(),0,backupDir);if(bh)HeapFree(GetProcessHeap(),0,bh);if(bp)HeapFree(GetProcessHeap(),0,bp);if(self)HeapFree(GetProcessHeap(),0,self);if(installed)HeapFree(GetProcessHeap(),0,installed);return ok;
}

static void schedule_cleanup(void){
    WCHAR *tmpdir=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));WCHAR *cmd=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));SIZE_T n=0;DWORD pid=GetCurrentProcessId();if(!tmpdir||!cmd)goto done;if(!get_env_path(L"TEMP",tmpdir,MAX_PATH_CHARS))goto done;
    {WCHAR num[16];int k=0;DWORD x=pid;WCHAR rev[16];if(x==0)rev[k++]='0';while(x&&k<15){rev[k++]=(WCHAR)('0'+x%10);x/=10;}for(int i=0;i<k;i++)num[i]=rev[k-1-i];num[k]=0;if(!join_path(cmd,MAX_PATH_CHARS,tmpdir,L"riichi_private_room_cleanup_")||!wcat(cmd,MAX_PATH_CHARS,num)||!wcat(cmd,MAX_PATH_CHARS,L".cmd"))goto done;}
    {const char*s="@echo off\r\nping 127.0.0.1 -n 2 >nul\r\nrmdir /s /q \"%LOCALAPPDATA%\\RiichiCityStovePrivateRoomPatch\"\r\ndel /f /q \"%~f0\"\r\n";n=alen(s);if(write_file(cmd,s,n))ShellExecuteW(NULLPTR,L"open",cmd,NULLPTR,NULLPTR,SW_HIDE);}
 done:if(tmpdir)HeapFree(GetProcessHeap(),0,tmpdir);if(cmd)HeapFree(GetProcessHeap(),0,cmd);
}

static int protocol_is_ours(void){
    HKEY k=NULLPTR;DWORD type=0,cb=0;LSTATUS r;WCHAR *buf;int ours=0;r=RegOpenKeyExW(HKEY_CURRENT_USER,L"Software\\Classes\\hwdl\\shell\\open\\command",0,KEY_READ,&k);if(r!=ERROR_SUCCESS)return 0;r=RegQueryValueExW(k,NULLPTR,NULLPTR,&type,NULLPTR,&cb);if(r==ERROR_SUCCESS&&type==REG_SZ&&cb>2&&cb<32768){buf=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,cb+2);if(buf){if(RegQueryValueExW(k,NULLPTR,NULLPTR,&type,(LPBYTE)buf,&cb)==ERROR_SUCCESS&&(wcontains_ci(buf,APP_EXE_NAME)||wcontains_ci(buf,PREV_EXE_NAME)||wcontains_ci(buf,PREV2_EXE_NAME)))ours=1;HeapFree(GetProcessHeap(),0,buf);}}RegCloseKey(k);return ours;
}

static int uninstall_patch(void){
    struct PatchState st;WCHAR *hall=NULLPTR,*helper=NULLPTR,*appRoot=NULLPTR,*backupDir=NULLPTR,*bh=NULLPTR,*bp=NULLPTR,*mail=NULLPTR;struct Buffer cur={0};DWORD pid=0;int ok=0,skipped=0;
    if(process_running_pid(GAME_EXE,&pid)){show_error(L"마작일번가가 실행 중입니다. 게임을 완전히 종료한 뒤 다시 제거해 주세요.");return 0;}
    if(!read_state(&st)){show_error(L"설치 정보를 찾을 수 없습니다.");return 0;}
    hall=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));helper=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));appRoot=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));backupDir=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));bh=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));bp=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));mail=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));
    if(!hall||!helper||!appRoot||!backupDir||!bh||!bp||!mail)goto done;if(!join_path(hall,MAX_PATH_CHARS,st.gameRoot,HALL_REL)||!join_path(helper,MAX_PATH_CHARS,st.gameRoot,HELPER_REL)||!get_app_root(appRoot,MAX_PATH_CHARS)||!join_path(backupDir,MAX_PATH_CHARS,appRoot,BACKUP_DIR_NAME)||!join_path(bh,MAX_PATH_CHARS,backupDir,L"lua_uiview_hall.original")||!join_path(bp,MAX_PATH_CHARS,backupDir,L"lua_helper.original"))goto done;
    if(!file_exists(bh)||!file_exists(bp)){show_error(L"원본 백업 파일을 찾을 수 없어 안전하게 제거할 수 없습니다.");goto done;}
    if(read_file(hall,&cur)){if(fnv1a64(cur.data,cur.len)==st.hallPatchedHash){if(!CopyFileW(bh,hall,FALSE)){free_buffer(&cur);show_error(L"lua_uiview_hall 원본 복구에 실패했습니다. 쓰기 권한을 확인해 주세요.");goto done;}}else skipped=1;free_buffer(&cur);}else skipped=1;
    if(read_file(helper,&cur)){if(fnv1a64(cur.data,cur.len)==st.helperPatchedHash){if(!CopyFileW(bp,helper,FALSE)){free_buffer(&cur);show_error(L"lua_helper 원본 복구에 실패했습니다. 쓰기 권한을 확인해 주세요.");goto done;}}else skipped=1;free_buffer(&cur);}else skipped=1;
    if(protocol_is_ours())RegDeleteTreeW(HKEY_CURRENT_USER,L"Software\\Classes\\hwdl");if(get_mailbox(mail,MAX_PATH_CHARS))DeleteFileW(mail);
    if(skipped)show_info(L"패치 등록은 제거했습니다.\n\n게임 업데이트 또는 외부 변경이 감지된 파일은 안전을 위해 이전 백업으로 덮어쓰지 않았습니다. 필요하면 STOVE에서 게임 파일 검사를 실행해 주세요.");else show_info(L"패치 제거가 완료되었습니다.\n\n게임 파일을 설치 전 원본 상태로 복구했습니다.");schedule_cleanup();ok=1;
 done:free_buffer(&cur);if(hall)HeapFree(GetProcessHeap(),0,hall);if(helper)HeapFree(GetProcessHeap(),0,helper);if(appRoot)HeapFree(GetProcessHeap(),0,appRoot);if(backupDir)HeapFree(GetProcessHeap(),0,backupDir);if(bh)HeapFree(GetProcessHeap(),0,bh);if(bp)HeapFree(GetProcessHeap(),0,bp);if(mail)HeapFree(GetProcessHeap(),0,mail);return ok;
}

static int parse_room_id(const WCHAR*uri,char out[7]){const WCHAR*p=L"hwdl://mainlink/path1?room_id=";SIZE_T i,n=wlen(p);if(!wpref_ci(uri,p))return 0;for(i=0;i<6;i++){WCHAR c=uri[n+i];if(c<'0'||c>'9')return 0;out[i]=(char)c;}out[6]=0;{WCHAR c=uri[n+6];if(c!=0&&c!='&'&&c!='#')return 0;}return 1;}
static void handle_hwdl(const WCHAR*uri){WCHAR *dir=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));WCHAR *box=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));WCHAR *tmp=(WCHAR*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,MAX_PATH_CHARS*sizeof(WCHAR));char id[7];DWORD pid=0;if(!dir||!box||!tmp)goto done;if(!parse_room_id(uri,id))goto done;if(!get_mailbox_dir(dir,MAX_PATH_CHARS)||!ensure_dir_chain(dir)||!join_path(box,MAX_PATH_CHARS,dir,L"hwdl_room.txt"))goto done;wcopy(tmp,MAX_PATH_CHARS,box);wcat(tmp,MAX_PATH_CHARS,L".tmp");if(write_file(tmp,id,6)){if(!MoveFileExW(tmp,box,MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH))DeleteFileW(tmp);else if(process_running_pid(GAME_EXE,&pid))foreground_game();else if(!show_stove_if_needed())show_error(L"STOVE 런처를 열지 못했습니다.\n\n개인실 번호는 보관되어 있습니다. STOVE와 마작일번가를 평소대로 실행하면 로비에 들어간 뒤 자동으로 처리됩니다.");}
 done:if(dir)HeapFree(GetProcessHeap(),0,dir);if(box)HeapFree(GetProcessHeap(),0,box);if(tmp)HeapFree(GetProcessHeap(),0,tmp);
}

void entry(void){
    int argc=0;LPWSTR*argv=CommandLineToArgvW(GetCommandLineW(),&argc);struct PatchState state;
    if(argv&&argc>=3&&weq_ci(argv[1],L"--hwdl")){handle_hwdl(argv[2]);LocalFree(argv);ExitProcess(0);}
    if(argv&&argc>=2&&weq_ci(argv[1],L"--uninstall")){uninstall_patch();LocalFree(argv);ExitProcess(0);}
    if(argv&&argc>=2&&weq_ci(argv[1],L"--install")){install_patch();LocalFree(argv);ExitProcess(0);}
    if(argv)LocalFree(argv);
    if(read_state(&state)){
        int r=MessageBoxW(NULLPTR,L"마작일번가 STOVE 개인실 패치가 이미 설치되어 있습니다.\n\n패치를 제거하시겠습니까?",TITLE,MB_YESNO|MB_ICONQUESTION|MB_SETFOREGROUND);if(r==IDYES)uninstall_patch();ExitProcess(0);
    }else{
        int r=MessageBoxW(NULLPTR,L"마작일번가 STOVE 개인실 패치 1.0.2를 설치하시겠습니까?\n\n개인실 링크를 열면 실행 중인 게임으로 바로 입장합니다. 게임이 꺼져 있으면 STOVE 런처만 열며, 이후 로그인과 마작일번가 실행은 STOVE에서 평소대로 진행하면 됩니다.",TITLE,MB_YESNO|MB_ICONQUESTION|MB_SETFOREGROUND);if(r==IDYES)install_patch();ExitProcess(0);
    }
}
