/*
    Observer pattern is used when there is one-to-many relationship between objects 
    such as if one object is modified, its depenedent objects are to be notified automatically. 
    Observer pattern falls under behavioral pattern category.

    Observer pattern uses three actor classes. 
    Subject, Observer and Client. Subject is an object having methods to attach and detach observers 
    to a client object. We have created an abstract class Observer and a concrete class Subject 
    that is extending class Observer.
*/

#include <iostream>
#include <vector>
using namespace std;

class Subject; 

class Observer 
{ 
protected:
    Subject* subject;
public:
    virtual ~Observer() = default;
    virtual void Update() = 0;
};

class Subject 
{ 
public: 
    virtual ~Subject() = default;

    int getState() {
        return state;
    }

    void setState(int state) {
        this->state = state;
        Notify();
    }
    void Attach(Observer *o) { observers.push_back(o); }
    //void Detach(Observer& o)
    //{
    //    observers.erase(std::remove(observers.begin(), observers.end(), &o));
    //}
    void Notify()
    {
        for (auto* o : observers) {
            o->Update(*this);
        }
    }
private:
    std::vector<Observer *> observers; 
    int state;
};

class BinaryObserver: public Observer {
public:
    BinaryObserver(Subject *subject) {
        this->subject = subject;
        this->subject->Attach(this);
    }

    void Update() {
        cout << "Binary string: " << subject->getState() << endl;
    }
};


int main()
{ 
    ClockTimer timer; 

    DigitalClock digitalClock(timer); 
    AnalogClock analogClock(timer); 

    timer.SetTime(14, 41, 36);
}