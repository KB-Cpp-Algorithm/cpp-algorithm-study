KB Header for CLion 사용 안내

1. 개요
이 플러그인은 CLion에서 KB 스타일 헤더를 파일 상단에 삽입하고,
사용자가 값을 직접 수정한 뒤 저장하면 헤더를 자동 정렬해주는 도구입니다.

==================================================
2. 설치 방법

Windows / macOS 공통:
1. CLion 실행
2. Settings 또는 Preferences 열기
3. Plugins 선택
4. Installed 탭 오른쪽의 톱니바퀴 아이콘 클릭
5. Install Plugin from Disk... 선택
6. kb-header-clion-plugin-1.0.3 ZIP 파일 선택
7. IDE 재시작


==================================================
3. 사용 방법

1. C/C++ 파일 또는 원하는 파일을 엽니다.
2. 기본 단축키를 눌러 헤더를 삽입합니다.
   기본 단축키:
   - Windows: Ctrl+Alt+H
   - IOS : Command + Options + H (추정)
   또는 액션 검색에서 Insert KB Header 실행
3. 파일 상단에 KB 헤더가 삽입됩니다.
4. 사용자가 아래 항목을 직접 입력합니다.
   - Algorithm
   - Time Complexity
   - Space Complexity
   - Note
5. 저장하면 헤더가 자동 정렬됩니다.

자동 정렬 시 동작
- 오른쪽 끝의 */ 위치가 다시 맞춰집니다.
- KB 마크가 지정된 위치에 맞춰 정렬됩니다.
- 너무 긴 입력은 헤더가 깨지지 않도록 잘릴 수 있습니다.

==================================================
4. By 이름 변경 방법

기본적으로 By 항목은 설정한 이름을 우선 사용하고,
설정이 없으면 운영체제 사용자 이름을 사용합니다.

4-1. Windows에서 이름 변경
1. CLion 실행
2. File > Settings
3. 왼쪽 메뉴에서 Tools > KB Header
4. Display name for By 항목에 원하는 이름 입력
   예: Jun Jeong
5. Apply > OK

4-2. macOS에서 이름 변경
1. CLion 실행
2. CLion > Settings 또는 Preferences
3. 왼쪽 메뉴에서 Tools > KB Header
4. Display name for By 항목에 원하는 이름 입력
5. Apply > OK

설정 후 새로 헤더를 삽입하거나 저장 시 자동 정렬이 동작하면
By 값이 설정한 이름으로 반영됩니다.

예:
By               : Jun Jeong

==================================================
5. 단축키 변경 방법

기본 액션 이름
- Insert KB Header

5-1. Windows에서 단축키 변경
1. CLion 실행
2. File > Settings
3. Keymap 선택
4. 검색창에 Insert KB Header 입력
5. 해당 액션 우클릭
6. Add Keyboard Shortcut 선택
7. 원하는 단축키 입력
   예: Ctrl+Shift+H
8. OK > Apply > OK

5-2. macOS에서 단축키 변경
1. CLion 실행
2. CLion > Settings 또는 Preferences
3. Keymap 선택
4. 검색창에 Insert KB Header 입력
5. 해당 액션 우클릭
6. Add Keyboard Shortcut 선택
7. 원하는 단축키 입력
   예: Command+Shift+H
8. OK > Apply > OK


참고
- 기존 단축키와 충돌하면 CLion이 경고를 표시할 수 있습니다.
- 충돌 시 기존 단축키를 제거하거나 다른 조합을 선택하세요.


