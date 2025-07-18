Command
==
## What is?
- 요청(명령)을 객체로 캡슐화해서, 요청을 큐에 저장하거나, 실행/취소(undo)하거나, log를 남기기 쉽게 만들어준다.
    

## 구조
```
Client -> Invoker -> Command -> Receiver
```

- Client: 어떤 명령을 실행할지 결정하고, Command 객체를 생성
- Invoker: 명령을 실행하는 버튼/트리거 같은 존재
- Command (인터페이스): execute(), undo() 등의 메서드 정의
- ConcreteCommand: 실제 명령 구현. Receiver 객체에게 요청 위임
- Receiver: 실제 작업을 수행하는 클래스 (예: Light, TV 등)

## 인터뷰 관점 핵심 포인트
| 질문                       | 포인트                                         |
| ------------------------ | ------------------------------------------- |
| **왜 Command를 쓰는가?**      | 실행 시점 분리, undo/redo, 큐잉, 로깅 가능하게 하기 위해      |
| **함수 포인터, 람다 대신 왜 객체로?** | 상태 저장, undo 지원, 다양한 확장이 쉬움                  |
| **어떤 곳에 쓰일 수 있나?**       | GUI 버튼, CLI 명령, 매크로 시스템, 큐 기반 게임 시스템, 리모컨 등 |

## 코드 분석 
from [command.cpp](command.cpp)
```
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};
```
- 모든 명령은 execute()와 undo() 구현을 부장
- 이 인터페이스 덕분에 다형성으로 처리 가능

```
class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override { light->on(); }
    void undo() override { light->off(); }
};
```
- 이 명령은 실제로 Receiver(Light 객체)에게 on/off 명령을 전달하는 전달자 역할
- 중요한 점: 명령은 실행을 직접 하지 않고 Receiver에게 위임함

```
class RemoteControl {
    Command* command;
public:
    void setCommand(Command* cmd) { command = cmd; }
    void pressButton() { command->execute(); }
    void pressUndo() { command->undo(); }
};
```
- 이게 Invoker — 누가 명령을 어떻게 실행하는지 몰라도 됨
- 명령을 누가 실행할지는 Command 객체에 맡기면 됨

🔄 확장: 매크로 커맨드 (복수 명령 묶기)
```
class MacroCommand : public Command {
    vector<Command*> commands;
public:
    MacroCommand(vector<Command*> cmds) : commands(cmds) {}
    void execute() override {
        for (auto cmd : commands) cmd->execute();
    }
    void undo() override {
        for (auto it = commands.rbegin(); it != commands.rend(); ++it)
            (*it)->undo();
    }
};
```

- 이런 식으로 여러 명령을 하나로 묶을 수도 있어. 실제 앱이나 게임에서 아주 유용함!

## 실제 사용 사례
| 사례          | 설명                            |
| ----------- | ----------------------------- |
| 리모컨         | 각 버튼이 특정 명령 객체 실행             |
| GUI 버튼      | 클릭 시 실행될 커맨드 연결 (Undo 지원도 포함) |
| 게임 명령 기록    | 키 입력을 명령으로 저장 후 리플레이/Undo 가능  |
| 큐 기반 시스템    | 커맨드를 큐에 저장해 순차 처리             |
| 데이터베이스 트랜잭션 | rollback 기능 구현에 사용            |
