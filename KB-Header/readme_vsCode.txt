KB Header Inserter 사용 안내 (VS Code용)

1. 개요
이 확장은 VS Code에서 KB 스타일 헤더를 파일 상단에 삽입하고,
사용자가 값을 직접 수정한 뒤 저장(Ctrl+S)하면 헤더를 자동 정렬해주는 도구입니다.

==================================================
2. VSIX 설치 방법

방법 1) VS Code 화면에서 설치
1. VS Code를 실행합니다.
2. 왼쪽 사이드바에서 "확장 프로그램" 아이콘을 클릭합니다.
3. 확장 프로그램 화면 오른쪽 위의 "..." 메뉴를 클릭합니다.
4. "Install from VSIX..." 를 선택합니다.
5. 받은 .vsix 파일을 선택합니다.
6. 설치가 끝나면 "Reload" 또는 "다시 로드"를 눌러 VS Code를 새로고침하거나 재실행합니다.

방법 2) 터미널에서 설치
터미널에서 아래 명령을 실행합니다.

Windows / Ubuntu / Linux 공통:
code --install-extension kb_header.vsix

설치 후 VS Code를 다시 로드하거나 재실행해 주세요.

참고
- code 명령이 동작하지 않으면 VS Code에서
  Ctrl+Shift+P
  -> Shell Command: Install 'code' command in PATH
  를 실행한 뒤 다시 시도하세요.

==================================================
3. 사용 방법

1. 새 파일 또는 기존 파일을 엽니다.
2. 기본 단축키 Ctrl+Alt+H 를 누릅니다.
   또는
   F1 -> KB Header: Insert Header
   를 실행합니다.
3. 파일 상단에 KB 헤더가 삽입됩니다.
4. 입력 후 Ctrl+S 로 저장하면 헤더가 자동 정렬됩니다.

자동 정렬 시 동작
- 오른쪽 끝의 */ 위치가 다시 맞춰집니다.
- KB 마크가 깨지지 않도록 고정됩니다.
- 너무 긴 입력은 헤더가 깨지지 않도록 잘릴 수 있습니다.

==================================================
4. By 이름 변경 방법

기본적으로 By 항목은 설정한 이름을 우선 사용하고,
설정이 없으면 운영체제 사용자 이름을 사용합니다.

이름 변경 방법 1) 설정 화면에서 변경
1. VS Code에서 Ctrl+, 를 누릅니다.
2. 검색창에 kb header display name 을 입력합니다.
3. "Kb Header: Display Name" 항목에 원하는 이름을 입력합니다.
   예: Jun Jeong

이름 변경 방법 2) settings.json 에서 변경
1. Ctrl+Shift+P 를 누릅니다.
2. Preferences: Open User Settings (JSON) 를 실행합니다.
3. 아래 내용을 추가합니다.

{
  "kbHeader.displayName": "Jun Jeong"
}

저장하면 이후 생성되는 헤더의 By 값이 변경됩니다.

==================================================
5. 단축키 변경 방법

기본 단축키
- Ctrl+Alt+H

방법 1) 키보드 단축키 화면에서 변경
1. Ctrl+K, Ctrl+S 를 누릅니다.
2. 검색창에 KB Header 를 입력합니다.
3. KB Header: Insert Header 항목을 찾습니다.
4. 연필 아이콘을 클릭합니다.
5. 원하는 단축키를 입력하고 Enter 를 누릅니다.

예시
- Ctrl+Shift+H
- Alt+H

방법 2) keybindings.json 에서 변경
1. Ctrl+Shift+P 를 누릅니다.
2. Preferences: Open Keyboard Shortcuts (JSON) 를 실행합니다.
3. 아래 예시를 추가합니다.

[
  {
    "key": "ctrl+shift+h",
    "command": "kbHeader.insertHeader",
    "when": "editorTextFocus"
  }
]

이미 다른 항목이 있으면 배열 안에 쉼표로 이어서 추가하면 됩니다.

==================================================
6. 추천 설정 예시

settings.json 예시

{
  "kbHeader.displayName": "Jun Jeong"
}

keybindings.json 예시

[
  {
    "key": "ctrl+shift+h",
    "command": "kbHeader.insertHeader",
    "when": "editorTextFocus"
  }
]

==================================================
7. 문제 해결

1) 새 버전을 설치했는데 예전처럼 동작하는 경우
- 기존 KB Header 관련 확장을 제거합니다.
- VS Code를 완전히 종료합니다.
- 새 .vsix를 다시 설치합니다.
- Reload Window 를 실행합니다.

2) Ctrl+S 저장 시 정렬이 안 되는 경우
- 현재 파일이 저장 가능한 상태인지 확인합니다.
- 확장이 정상 설치되었는지 확인합니다.
- 명령 팔레트(F1)에서 KB Header 명령이 보이는지 확인합니다.

3) By에 원하지 않는 운영체제 계정명이 나오는 경우
- settings.json 에 kbHeader.displayName 을 설정하세요.
