#include <iostream>
#include <memory>
using namespace std;

// Strategy Interface
class SpellChecker {
public:
    virtual void checkSpelling() = 0;
    virtual ~SpellChecker() = default;
};

// Concrete Strategies
class EnglishSpellChecker : public SpellChecker {
public:
    void checkSpelling() override {
        cout << "Checking spelling in English...\n";
    }
};

class KoreanSpellChecker : public SpellChecker {
public:
    void checkSpelling() override {
        cout << "Checking spelling in Korean...\n";
    }
};

// Context
class TextEditor {
private:
    unique_ptr<SpellChecker> checker;

public:
    void setSpellChecker(unique_ptr<SpellChecker> newChecker) {
        checker = move(newChecker);
    }

    void performSpellCheck() {
        if (checker)
            checker->checkSpelling();
        else
            cout << "No spell checker set.\n";
    }
};

int main() {
    TextEditor editor;

    editor.setSpellChecker(make_unique<EnglishSpellChecker>());
    editor.performSpellCheck();  // English

    editor.setSpellChecker(make_unique<KoreanSpellChecker>());
    editor.performSpellCheck();  // Korean

    return 0;
}