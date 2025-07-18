#include <iostream>
#include <vector>

using namespace std;

// Receiver
class Light {
public:
    void on() { cout << "Light is on\n"; }
    void off() { cout << "Light is off\n"; }
};

// Command Interface
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

// ConcreteCommand
class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override { light->on(); }
    void undo() override { light->off(); }
};

class LightOffCommand : public Command {
    Light* light;
public:
    LightOffCommand(Light* l) : light(l) {}
    void execute() override { light->off(); }
    void undo() override { light->on(); }
};

// Invoker
class RemoteControl {
    Command* command;
public:
    void setCommand(Command* cmd) { command = cmd; }
    void pressButton() { command->execute(); }
    void pressUndo() { command->undo(); }
};

// Main
int main() {
    Light light;
    LightOnCommand on(&light);
    LightOffCommand off(&light);

    RemoteControl remote;
    remote.setCommand(&on);
    remote.pressButton();     // Light is ON
    remote.pressUndo();       // Light is OFF

    remote.setCommand(&off);
    remote.pressButton();     // Light is OFF
    remote.pressUndo();       // Light is ON

    return 0;
}