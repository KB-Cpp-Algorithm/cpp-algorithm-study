````markdown
# 🧩 KB Header Plugin

C/C++ 파일 상단에 **KB 스타일 헤더를 자동 삽입 및 정렬**해주는 플러그인입니다.

- VS Code / CLion 지원
- 헤더 삽입 + 저장 시 자동 정렬
- 협업 시 코드 가독성 향상

---

# 📥 다운로드

## 🔹 VS Code
- [KB Header VSIX 다운로드](./kb_header.vsix)

## 🔹 CLion
- [KB Header Plugin 다운로드](./kb-header-clion-plugin-1.0.3.zip)

---

# 🚀 주요 기능

- 파일 상단에 KB 헤더 자동 삽입
- 저장 시 헤더 자동 정렬
- KB 마크 및 포맷 유지
- 긴 문자열 자동 잘림 처리

자동 정렬 시 동작:
- 오른쪽 `*/` 위치 정렬
- KB 로고 위치 유지
- 포맷 깨짐 방지

---

# 🛠️ 설치 방법

## 🔹 VS Code

### 방법 1 (GUI)
1. VS Code 실행
2. 확장 프로그램 탭 이동
3. 우측 상단 `...` 클릭
4. `Install from VSIX...` 선택
5. `.vsix` 파일 선택
6. 설치 후 Reload

### 방법 2 (터미널)

```bash
code --install-extension kb_header.vsix
````

---

## 🔹 CLion

1. CLion 실행
2. Settings / Preferences
3. Plugins 이동
4. 톱니바퀴 클릭
5. `Install Plugin from Disk...`
6. `.zip` 파일 선택
7. IDE 재시작

---

# 💻 사용 방법

## 공통 사용 방법 (VS Code / CLion)

1. 파일 열기
2. 단축키 입력

```bash
Ctrl + Alt + H
```

또는

```bash
Insert KB Header
```

3. 파일 상단에 헤더 생성
4. 내용 수정
5. 저장 (Ctrl + S)

👉 저장 시 자동 정렬 적용

---

# ✏️ 헤더 입력 항목

* Algorithm
* Time Complexity
* Space Complexity
* Note

---

# 👤 By 이름 변경

## 🔹 VS Code

### 방법 1 (설정 UI)

1. `Ctrl + ,`
2. `kb header display name` 검색
3. 원하는 이름 입력

### 방법 2 (settings.json)

```json
{
  "kbHeader.displayName": "Jun Jeong"
}
```

---

## 🔹 CLion

### Windows

1. Settings
2. Tools → KB Header
3. Display name 입력
4. Apply → OK

### macOS

1. Preferences
2. Tools → KB Header
3. Display name 입력

---

# ⌨️ 단축키 변경

## 🔹 VS Code

### UI

1. `Ctrl + K, Ctrl + S`
2. "KB Header" 검색
3. 단축키 수정

### JSON

```json
[
  {
    "key": "ctrl+shift+h",
    "command": "kbHeader.insertHeader",
    "when": "editorTextFocus"
  }
]
```

---

## 🔹 CLion

1. Settings / Preferences
2. Keymap
3. "Insert KB Header" 검색
4. 단축키 설정

---

# ⚠️ 문제 해결

## 1. 새 버전 적용 안 될 때

* 기존 플러그인 제거
* IDE 완전 종료
* 재설치 후 Reload

## 2. 자동 정렬 안 될 때

* 파일 저장 가능한 상태인지 확인
* 플러그인 정상 설치 여부 확인

## 3. By 이름 이상할 때

* displayName 설정 확인

---

# 💡 목적

* 코드 표준화
* 가독성 향상
* 협업 시 코드 이해도 증가

---
