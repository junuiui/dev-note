Version Control
=
## What is?
- **Version Control System**은 source code에 **history**를 기록하고, 이전 상태로 되돌리거나, 여러 명이 동시에 작업할 수 있도록 도와주는 시스템

## 종류
| 종류                  | 설명                  | 예시                 |
| ------------------- | ------------------- | ------------------ |
| Local VCS           | 내 컴퓨터에서만 버전 관리      | RCS, SCCS          |
| Centralized VCS     | 중앙 서버가 모든 변경 이력을 가짐 | SVN, CVS           |
| **Distributed VCS** | 각 개발자가 전체 히스토리를 가짐  | **``Git``**, Mercurial |

## 기본 개념 요약
| 개념             | 설명                                     |
| -------------- | -------------------------------------- |
| **Repository** | 프로젝트가 저장되는 공간 (로컬 또는 GitHub 같은 원격 저장소) |
| **Commit**     | 변경 사항을 저장한 스냅샷 (설명 메시지 포함)             |
| **Branch**     | 독립적인 작업 흐름 (기능 개발, 버그 수정 등)            |
| **Merge**      | 브랜치를 병합                                |
| **Clone**      | 원격 저장소 복사                              |
| **Pull**       | 원격 저장소에서 최신 내용 가져오기                    |
| **Push**       | 내 변경 내용을 원격 저장소에 올리기                   |

## 명령어
1. 레포지토리 초기화
    - `git init`

2. 상태 확인
    - `git status`

3. 파일 추가 (스테이지)
    - `git add file.cpp`

4. 커밋 (저장)
    - `git commit -m "메시지 작성"`

5. 브랜치 생성 및 이동
    - `git branch feature/login`
    - `git checkout feature/login`
    - `git checkout -b feature/login`

6. 병합
    - `git checkout main`
    - `git merge feature/login`

7. 원격 저장소 연결 & 푸시
    - `git remote add origin https://github.com/yourname/project.git`
    - `git push -u origin main`

## GitHub Flow
    main (production) branch → 
    create feature branch → 
    commit → 
    push → 
    Pull Request (PR) → 
    Code Review → 
    Merge

- main 브랜치는 항상 배포 가능한 상태여야 함
- 기능은 항상 별도 브랜치에서 개발
- Example
    ```
    # 새 프로젝트 시작
    git init

    # 작업 중
    vim main.cpp
    git add main.cpp
    git commit -m "Add main function"

    # 브랜치 만들어서 기능 추가
    git checkout -b feature/logger
    vim logger.cpp
    git add logger.cpp
    git commit -m "Add logger"

    # main 브랜치로 돌아가서 병합
    git checkout main
    git merge feature/logger
    ```

## Git Conflict 해결
- 언제 발생하나?
    - 두 브랜치가 같은 파일의 같은 줄을 수정한 경우, Git이 어떤 걸 선택해야 할지 몰라서 "conflict"가 발생함
- Example
    ```
    # A가 main 브랜치에서 파일을 이렇게 바꿈
    int x = 10;

    # B가 feature 브랜치에서 파일을 이렇게 바꿈
    int x = 99;

    # 이제 feature 브랜치를 main에 merge하면...
    ```

- Git은 충돌 메시지를 보여주고 이렇게 파일을 표시함
    ```
    <<<<<<< HEAD
    int x = 10;
    =======
    int x = 99;
    >>>>>>> feature
    ```
- 해결 방법
    1. 충돌 파일 열기
    2. 수동으로 원하는 쪽 선택 (또는 새로 작성)
    3. 저장 후 다음 실행:
        - `git add conflicted_file.cpp`
        - `git commit`

## Rebase vs Merge
| Feature     | `git merge`        | `git rebase`         |
| ----------- | ------------------ | -------------------- |
| Merge 방식    | **병합 커밋** 추가됨      | **히스토리를 재작성**함       |
| 로그          | 브랜치 히스토리 남아 있음     | 선형(linear) 히스토리로 깔끔함 |
| Conflict 처리 | 한 번에               | 여러 커밋마다 conflict 가능  |
| 사용 시점       | 협업 후 PR 병합 시 주로 사용 | 개인 브랜치 정리할 때 사용      |

- 간단 요약:
    - `merge`: 팀 협업 시 안전하고 흔히 쓰임
        - `git merge main`
    - `rebase`: 내 커밋 히스토리 깔끔하게 정리할 때
        - `git rebase main`


## git stash (임시 저장)
- When to use?
    - 작업 도중인데 브랜치를 바꿔야 할 때, 변경 사항을 잠깐 숨겨둠
    ```
    # 현재 변경사항 저장
    git stash

    # 다시 꺼내기
    git stash pop

    # 목록 보기
    git stash list
    ```
- Example)
    ```
    git stash
    git checkout main
    # 뭔가 함
    git checkout feature
    git stash pop  # 다시 작업 이어서
    ```

## git log, blame, revert
- `git log`
    - 커밋 히스토리 보기
    - `git log --oneline`
- `git blame`
    - 각 줄이 누가 언제 작성했는지 확인
    - `git blame file.cpp`
- `git revert`
    - 기존 커밋을 되졸리는 새 커밋 생성
    - `git revert <commit_id>`

## GitHub Pull Request (PR) & Process of Reviewing
- 일반적인 협업 흐름
    - `feature/login` 브랜치 생성
    - 작업 → `git push origin feature/login`
    - GitHub에서 PR(Pull Request) 생성
    - 팀원이 리뷰 (코멘트, 수정 요청)
    - Merge (보통 `main`으로)
- 보통 PR 안에는:
    - 무엇을 수정했는지 설명
    - 이유나 맥락
    - 리뷰어가 볼 포인트

## GitHub Actions (CI/CD 자동화)
- GitHub에 코드 Push 하면 자동으로
    1. 빌드
    2. 테스트
    3. 배포
- 예시 workflow (.github/workflows/main.yml)
    ```
    name: C++ Build & Test

    on: [push]

    jobs:
    build:
        runs-on: ubuntu-latest
        steps:
        - uses: actions/checkout@v3
        - name: Install dependencies
            run: sudo apt install g++
        - name: Build
            run: g++ -o main main.cpp
        - name: Run Tests
            run: ./main
    ```


