Process
=
## What is?
- **Software Development Process** is a structured approach used to **design, build, test, and maintain software systems.**
    - **Steps** you follow from idea to development
    - **Team roles** and how they coolaborate
    - **Tools & workflows** used throughout development

## Common Stages of a Development Lifecycle
| Stages | Explanation 
| --------- | ----------- 
| 1. `Requirements gahering` | Understand what needs to be built
| 2. `Design` | Create architectural and technical plans
| 3. `Implementation` (coding) | Build the software
| 4. `Testing` | Verify the software works correctly
| 5. `Deployment` | Release the product to users
| 6. `Maintenance` | Fix bugs and make improvements over time

## 1. Waterfall Mdel
- A **linear and sequential** model - each phase must be completed before the next starts
- Flow:
    ```
    Requirements → Design → Implementation → Testing → Deployment → Maintenance
    ```
    - Pros ✅
        - Simple and easy to manage
        - Good documentation
        - Suitable for fixed-scope projects
    - Cons ❌
        - Rigid — hard to adapt to change.
        - Late delivery of working software.
        - No real feedback until the end.
- Used in: Government contracts, legacy enterprise systems.

## 2. Agile Model
- **Interative and incremental** - build small parts, get feedback quickly, and imporve continuously
- Agile Cycle:
    ```
    Plan → Build → Test → Review → Repeat (in short sprints)
    ```
    - Pros ✅
        - Responds quickly to changes.
        - Customer collaboration is encouraged.
        - Delivers working software early and often.
        - TDD, CI/CD, automative
    - Cons ❌
        - Requires a disciplined, collaborative team.
        - Can be hard to scale in large organizations without structure.

- Used in: Most modern tech companies (including startups and big companies).

    ### Scrum (Agile framework)
    - **Team-focused Agile** with clearly defined roles and workflows
        | Key Concepts | . |
        ---------------| ----
        `sprint` | Time-boxed iteration (usually 2 weeks)
        `Roles` | Product Owner (defines priorities), Scrum Master (facilitates process), Development Team (builds the product)
        `Events` | Daily Standup, Sprint Planning, Sprint Review, Sprint Retrospective 
        `backlog` | 제품이나 프로젝트에서 해야 할 일(Task, Feature, Bug 등)을 정리해 놓은 우선순위가 있는 목록이야.
    - Helps teams ship small but valuable product features regularly

    ```
    Actions
    1. Sprint Planning: Pick work
    2. Daily Stand-ups: Track progress
    3. Sprint Review: Show work
    4. Retrospective: Improve process
    5. Repeat
    ```

    - What is Backlog?
        - Backlog는 제품이나 프로젝트에서 **해야 할 일(Task, Feature, Bug 등)**을 정리해 놓은 우선순위가 있는 목록이야.
            - 할 일 목록이지만, 아무 순서나 있는 게 아니고 가치/중요도 기준으로 정렬돼 있어.
            - 계속해서 추가되거나, 수정되거나, 삭제되기도 해.
            - 팀이 실제로 개발하기 전에 PO(Product Owner)가 꾸준히 관리해.
        
        - 종류
            1. `Product Backlog`
                ```
                전체 제품에서 해야 할 일 전부를 모아놓은 목록
                (기능, 요구사항, 버그, 기술적 부채 등 모두 포함)
                ```
                - 작성자: Product Owner
                - 항목들: 사용자 스토리, 버그 수정, 기술 개선 등
                - 항상 정렬되어 있음 (가장 중요한 작업이 맨 위)
                - `example`
                    ```
                    [1] 사용자 로그인 기능
                    [2] 비밀번호 재설정 기능
                    [3] 프로필 사진 업로드
                    [4] 메일 인증 기능
                    ...
                    ```
            2. `Sprint Backlog` 
                ```
                이번 sprint (1-2 weeks)동안 실제로 개발할 작업 목록
                ```
                - 작성자: 개발팀 (스프린트 플래닝에서 PO와 협의)
                - Product Backlog에서 상위 항목만 뽑아오는 느낌
                - 각 작업을 세부 작업 단위로 나누기도 해
                - `example`
                    ```
                    [스프린트 목표: 로그인 기능 완성]
                    [ ] 로그인 페이지 UI
                    [ ] API 연결
                    [ ] 에러 처리
                    [ ] 로그인 성공 시 라우팅
                    ```
            - 정리
                | 구분     | Product Backlog | Sprint Backlog  |
                | ------ | --------------- | --------------- |
                | 범위     | 전체 제품           | 이번 스프린트         |
                | 담당자    | Product Owner   | 개발팀             |
                | 유동성    | 계속 변할 수 있음      | 스프린트 중에는 거의 고정됨 |
                | 항목의 단위 | 사용자 스토리 또는 에픽   | 더 작은 Task 단위    |

            - 한줄 요약
                - `Product Backlog` = 모든 할 일의 "큰 지도"
                - `Sprint Backlog` = 이번 주간 할 일 "To-do 리스트"
                
    - Roles
        - Product Owner
            - 무엇을 개발할지 결정
            - Product Backlog 관리, 우선순위 정함
            - 고객이나 이해관계자들과 소통하면서 가치를 전달
                - 예) "이번 스프린트에선 로그인 기능이 가장 중요해요"
        - Scrum Master
            - 팀이 스크럼 원칙을 잘 지키도록 돕는 역할
            - 개발자들이 막히는 부분을 해결할 수 있도록 지원
            - 회의를 진행하고, 팀의 흐름을 유지시켜줌
                - 예) Build server 문제는 제가 IT팀과 이야기해서 해결해볼게요
        - Development Team (개발팀)
            - 실제로 software를 개발
            - Front/Backend, QA 등 다향한 역할이 포함됨
            - 자율적으로 일하며, 자신들이 어떻게 개발할지 스스로 정함
                - 예) 이번 기능은 A가 backend, B가 frontend를 맡아서 같이 작업
    
    - Srcub Ceremony (회의)
        1. Sprint Planning (스프린트 계획 회의)
            ```
            - 언제? 스프린트 시작 전에
            - 목적: 이번 스프린트에서 어떤 작업을 할지 정함
            ```
            - PO (Product Owner)가 backlog를 보여주고 우선순위를 설명
            - 개발팀이 이번 스프린트에 완료할 수 있는 작업량을 스스로 선택

        2. Daily Stand-up
            ```
            - 언제? 매일 (15분 내외)
            - 목적: 팀원들 간에 현재 상황 공유
            ```
            - 질문 3가지를 공유
                1. 어제 뭐했는가
                2. 오늘 뭘 할 예정인가
                3. 막히는게 있는가
            - 보고하는 회의가 아니라 서로를 동기화하는 회의
        
        3. Sprint Review
            ```
            언제? 스프린트가 끝났을 때
            목적: 이번 스프린트에서 만든 기능을 demo하고 feedback받기
            ```
            - 이해관계자들이 참여해서 직접 결과물을 봄
            - 피드백을 받아 다음 backlog에 반영
        
        4. Sprint Retrospective 
            ```
            언제? 리뷰 직후
            목적: 개발과정에 대해 돌아보고 개선점 찾기
            ```
            - 잘한점
            - 아쉬웠던 점
            - 다음 스프린트에 더 나아지기 위해 무엇을 바꿀까?
    
    - Artifacts
        | 산출물             | 설명                        |
        | --------------- | ------------------------- |
        | Product Backlog | 전체 작업 목록. PO가 관리, 우선순위 지정 |
        | Sprint Backlog  | 이번 스프린트 동안 할 작업들 목록       |
        | Increment       | 이번 스프린트에서 실제로 완성된 제품 기능들  |

## 3. DevOps & CI/CD (Modern Practice)
- `DevOps` combines **development** and **operations** to improve collaboration, automation, and deployment speed.

    ### CI/CD Cycle:
    - `CI` (COntinuous Integration)
        - Every code commit is ``tested`` automatically
    - `CD` (Continous Delivery/Deployment)
        - Software is automatically released to production or staging
    
    ### Tools
    - GitHub Actions, Jenkins, CircleCI
    - Docker, Kubernetes
    - AWS, GCP, Azure

    Goal: Fast, reliable, repeataable software delivery


# Summary
| Model     | Focus              | Use Case                         |
| --------- | ------------------ | -------------------------------- |
| Waterfall | Sequential phases  | Fixed-scope, low-change projects |
| Agile     | Iterative feedback | Modern development, startups     |
| Scrum     | Team sprints       | Feature-driven development teams |
| Kanban    | Flow + flexibility | Support/maintenance teams        |
| DevOps    | Automation & speed | Cloud-native, CI/CD pipelines    |
