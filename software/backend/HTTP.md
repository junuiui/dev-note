HTTP
==
## What is?
- HyperText Transfer Protocol
    - 웹에서 데이터를 주고받기위한 약속 (protocol)

## HTTP 요청 구조 (Request)
- 요청은 크게 4가지로 구성

| 구성 요소        | 예시                                          | 설명                          |
| ------------ | ------------------------------------------- | --------------------------- |
| **Method**   | `GET`, `POST`, `PUT`, `DELETE`              | 어떤 행동을 할지 지정                |
| **URL (주소)** | `/login`, `/posts/123`                      | 어디에 요청할지 지정                 |
| **Headers**  | `Authorization: Bearer ...`                 | 추가 정보 (예: 인증 토큰)            |
| **Body**     | `{ "username": "jun", "password": "1234" }` | 보내는 데이터 (POST, PUT에서 주로 사용) |


- 예시
```
POST /login HTTP/1.1
Host: example.com
Content-Type: application/json
Authorization: Bearer abcd...

{
  "username": "jun",
  "password": "1234"
}
```

## HTTP 응답 구조 (Response)
- 서버가 요청을 받고 Response를 줘

| 구성 요소           | 예시                                               | 설명         |
| --------------- | ------------------------------------------------ | ---------- |
| **Status Code** | `200`, `404`, `500`                              | 처리 결과를 알려줌 |
| **Headers**     | `Content-Type: application/json`                 | 응답 정보      |
| **Body**        | `{ "message": "Login success", "token": "..." }` | 실제 데이터     |

## 응답 예시
```
HTTP/1.1 200 OK
Content-Type: application/json

{
  "message": "Login success",
  "token": "abcd1234..."
}
```

## 주요 Status Code
| 코드  | 의미           | 설명       |
| --- | ------------ | -------- |
| 200 | OK           | 성공       |
| 201 | Created      | 생성 완료    |
| 400 | Bad Request  | 잘못된 요청   |
| 401 | Unauthorized | 인증 실패    |
| 403 | Forbidden    | 접근 금지    |
| 404 | Not Found    | 존재하지 않음  |
| 500 | Server Error | 서버 내부 에러 |

## 흐름 정리: 프론트 ↔ 백엔드
```
[사용자] → 버튼 클릭
   ↓
[프론트] → HTTP 요청 (예: POST /login)
   ↓
[백엔드 서버] → 요청 처리 (DB 조회, 로직 수행)
   ↓
[백엔드] → HTTP 응답 (예: 200 OK + 토큰 전달)
   ↓
[프론트] → 응답을 받아 처리 (로그인 완료 화면으로 이동)
```

Go to [REST API](rest.md)
