Observer Pattern
==
## What is?
- 어떤 객체의 상태가 바뀌었을 때, 그 객체에 의존하는 다른 객체들에게 **자동으로 알림**이 가도록 하는 디자인 패턴

## 핵심 개념
- Subject (Observable): 상태를 가지고 있고, 구독자(observer)를 관리
- Observer: subject가 변화하면 자동으로 알림을 받는 객체

## 구조 다이어그램
```
Subject
 ├── attach(observer)
 ├── detach(observer)
 └── notify()

Observer (interface)
 └── update()
```

## Where to use?
- UI 프레임워크: 데이터 바뀌면 화면 자동 업데이트
- 이벤트 시스템: 유저 알림, 알람 시스템
- MVC 패턴의 View 업데이트

## Questions
| 질문       | 답변 요약                                                |
| -------- | ---------------------------------------------------- |
| 왜 유용한가요? | 객체들 간 **느슨한 결합(loose coupling)** 덕분에 유연한 시스템 구성 가능   |
| 단점은?     | 옵저버 수가 많을수록 성능 이슈 생길 수 있음                            |
| 실무 예시?   | React useEffect, Node.js EventEmitter, 게임 내 알림 시스템 등 |

## Ideas
- Youtube Channel: 새 영상 올라오면 구독자에게 알림
- 주식 앱: 가격 바뀌면 관심 종목에 알림
- 축구 경기 스코어 - 바뀌면 팬들에게 업데이트