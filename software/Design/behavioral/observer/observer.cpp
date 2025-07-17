#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // for std::remove
using namespace std;

// Forward declaration
class Observer;

// Subject
class WeatherStation {
    vector<Observer*> observers;
    float temperature = 0.0;
public:
    void attach(Observer* obs) {
        observers.push_back(obs);
    }

    void detach(Observer* obs) {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void setTemperature(float temp) {
        temperature = temp;
        notify();
    }

    float getTemperature() const { return temperature; }

    void notify();
};

// Observer interface
class Observer {
public:
    virtual void update(WeatherStation* station) = 0;
    virtual ~Observer() = default;
};

// Concrete Observer
class PhoneDisplay : public Observer {
    string owner;
public:
    PhoneDisplay(string owner) : owner(owner) {}
    void update(WeatherStation* station) override {
        cout << owner << "'s phone: Temp is " << station->getTemperature() << " deg\n";
    }
};

void WeatherStation::notify() {
    for (auto obs : observers) {
        obs->update(this);
    }
}

// main
int main() {
    WeatherStation station;

    PhoneDisplay pd1("Jun");
    PhoneDisplay pd2("Alex");

    station.attach(&pd1);
    station.attach(&pd2);

    station.setTemperature(25.0f);
    station.setTemperature(30.5f);

    station.detach(&pd2);
    station.setTemperature(20.0f);

    return 0;
}
