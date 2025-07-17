#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Component
class OrganizationUnit {
public:
    virtual void showInfo(int depth = 0) = 0;
    virtual ~OrganizationUnit() = default;
};

// Leaf
class Employee : public OrganizationUnit {
    string name;

public:
    Employee(string name) : name(name) {}
    void showInfo(int depth = 0) override {
        cout << string(depth * 2, ' ') << "- Employee: " << name << endl;
    }
};

// Composite
class Department : public OrganizationUnit {
    string name;
    vector<unique_ptr<OrganizationUnit>> members;
public:
    Department(string name) : name(name) {}

    void addMember(unique_ptr<OrganizationUnit> member) {
        members.push_back(move(member));
    }

    void showInfo(int depth = 0) override {
        cout << string(depth * 2, ' ') << "+ Department: " << name << endl;
        for (auto& m : members)
            m->showInfo(depth + 1);
    }
};

int main() {
    auto company = make_unique<Department>("Acme Corp");

    auto devDept = make_unique<Department>("Development");
    devDept->addMember(make_unique<Employee>("Mitchell Alexandro"));
    devDept->addMember(make_unique<Employee>("Kai Water"));

    auto hrDept = make_unique<Department>("HR");
    hrDept->addMember(make_unique<Employee>("Ken Hwang"));

    company->addMember(move(devDept));
    company->addMember(move(hrDept));

    company->showInfo();

    return 0;
}