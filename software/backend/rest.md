REST API
==
## What is?
- REST는 REpresentational State Transfer
    - API를 일정한 규칙에 따라 설계하는 방식
- 쉽게 말하면:
    - 웹에서 데이터를 주고받는 데 있어, 이런 방식으로 주소를 짜고, 요청을 구분해서 만들자 는 약속

## REST API 기본구조
    HTTP Method + URL + (Body or Params)

| HTTP 메서드 | 의미     | 예시                   |
| -------- | ------ | -------------------- |
| `GET`    | 데이터 조회 | `/get`, `/users/1` |
| `POST`   | 데이터 생성 | `/posts` (새 글 작성)    |
| `PUT`    | 데이터 수정 | `/put/1` (1번 글 수정) |
| `DELETE` | 데이터 삭제 | `/delete/1` (1번 글 삭제) |

예시)

| 기능      | Method | URL        | 설명           |
| ------- | ------ | ---------- | ------------ |
| 전체 글 조회 | GET    | `/get`   | 모든 글 가져오기    |
| 특정 글 조회 | GET    | `/get/1` | id=1번 글 가져오기 |
| 새 글 작성  | POST   | `/posts`   | 글 내용 전송해서 생성 |
| 글 수정    | PUT    | `/put/1` | id=1번 글 수정   |
| 글 삭제    | DELETE | `/delete/1` | id=1번 글 삭제   |

## REST API의 핵심 원칙
1. 자원(Resource) 중심
    - 예: `/posts`, `/users`, `/products`
2. HTTP Method로 행동 표현
    - `GET`, `POST`, `PUT`, `DELETE`를 활용해 "무엇을 할지" 표현
3. URL에는 동사 X, 명사 O
    - X: `/getUser`, `/createPost`
    - O: `/users`, `/posts`
4. Stateless (무상태성)
    - 서버는 요청마다 독립적으로 처리해야 함 (세션 기억 안 함 -> 보통 토큰 사용)

## 정리: REST API를 왜 쓰나?
| 이유                  | 설명                                     |
| ------------------- | -------------------------------------- |
| 규칙이 명확            | 개발자들이 쉽게 이해하고 협업 가능                    |
| URL만 보고도 기능 파악 가능 | `/posts/1` → 1번 글 관련 처리구나!             |
| 확장성 좋음            | 다른 플랫폼(iOS, Android)도 쉽게 연결 가능         |
| 표준화되어 있음          | 많은 프레임워크/도구에서 지원함 (Swagger, Postman 등) |

## RESTful
- X
    ```
    GET /getAllUsers
    POST /createNewUser
    ```

- O
    ```
    GET /users
    POST /users
    ```

## GET - 데이터 조회
- 특징
    - 서버에서 데이터를 가져올 때 사용
    - 요청 body가 없음
    - 주소창, 즐겨찾기 등에 쓰일 수 있음 (cache 가능)
- 예시
    ```
    GET /users
    GET /posts/1
    ```
- 사용 상황
    - 게시글 목록 보기
    - 특정 사용자 정보 가져오기
    - 검색어로 결과 조회

## POST - 데이터 생성
- 특징
    - 서버에 새로운 데이터를 보낼 때 사용
    - 요청 body에 데이터 포함
    - 매번 새로운 리소스 생성 (글 작성, 회원가입 등)
- 예시
    ```
    POST /users
    Body: {
    "name": "Jun",
    "email": "jun@example.com"
    }
    ```
- 사용 상황
    - 회원가입
    - 댓글작성
    - 결제요청

## PUT - 데이터 전체 수정
- 특징
    - 기존 데이터를 덮어쓰기 할 때 사용
    - 전체 필드를 보내야 함 (없으면 삭제)
    - 자주 PATCH 와 비교됨 (부분 수정)
- 예시
    ```
    PUT /users/1
    Body: {
    "name": "Jun",
    "email": "jun@newmail.com"
    }
    ```
- 사용 상황
    - 사용자 정보 전체 업데이트
    - 게시글 전체 수정
    - 설정 초기화

## DELETE - 데이터 삭제
- 특징
    - 서버에서 자원을 제거
    - 일반적으로 body는 없음 (가끔 예외)
    - 삭제 성공 시 `204 No Content` 반환하기도 함
- 예시
    ```
    DELETE /users/1
    ```
- 사용 상황
    - 회원 탈퇴
    - 게시글 삭제
    - 찜 목록에서 상품 제거

## PUT vs PATCH
| 메서드     | 의미      | 예시                                  |
| ------- | ------- | ----------------------------------- |
| `PUT`   | 전체 덮어쓰기 | `{ "name": "Jun", "email": "abc" }` |
| `PATCH` | 부분 수정만  | `{ "email": "abc" }`                |

## Summary
| Method | 기능    | Body 사용 | CRUD 역할 | 대표 예시   |
| ------ | ----- | ------- | ------- | ------- |
| GET    | 조회    | ❌       | Read    | 목록 보기   |
| POST   | 생성    | ✅       | Create  | 회원가입    |
| PUT    | 전체 수정 | ✅       | Update  | 회원정보 수정 |
| DELETE | 삭제    | ❌       | Delete  | 탈퇴      |

