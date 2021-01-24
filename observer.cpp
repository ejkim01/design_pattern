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

class NewAgency; 

class Observer 
{ 
protected:
    NewAgency* subject;
public:
    virtual ~Observer() = default;
    virtual void Update() = 0;
};

class NewAgency // Subject
{ 
public: 
    virtual ~NewAgency() = default;

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
            o->Update();
        }
    }
private:
    std::vector<Observer *> observers; 
    int state;
};

class CnnNews: public Observer {
public:
    CnnNews(NewAgency *subject) {
        this->subject = subject;
        this->subject->Attach(this);
    }

    void Update() {
        cout << "CnnNews is notified: " << subject->getState() << endl;
    }
};

class FoxNews: public Observer {
public:
    FoxNews(NewAgency *subject) {
        this->subject = subject;
        this->subject->Attach(this);
    }

    void Update() {
        cout << "FoxNews is notified: " << subject->getState() << endl;
    }
};

int main()
{ 
    NewAgency *s = new NewAgency();
    CnnNews bn(s);
    FoxNews fn(s);

    s->setState(15);
}