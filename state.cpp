/*
    In State pattern a class behavior changes based on its state. 
    This type of design pattern comes under behavior pattern.

    In State pattern, we create objects which represent various states and a context object 
    whose behavior varies as its state object changes.
*/
class State;

class Context {
    State* state;
public:
    Context():state(nullptr) {}

    void setState(State* state) {
        this->state = state;
    }

    State* getState() {
        return state;
    }
};

class State {
public:
    virtual void doAction(Context* context)=0;
    virtual void printState()=0;
};

class StartState: public State {
public:
    void doAction(Context* context) override {
        cout << "Player is in start state" << endl;
        context->setState(this);
    }
    void printState() override {
        cout << "Start state" << endl;
    }
};

class StopState: public State {
public:
    void doAction(Context* context) override {
        cout << "Player is in stop state" << endl;
        context->setState(this);
    }
    void printState() override {
        cout << "Stop state" << endl;
    }
};

int main() {
    Context* context = new Context();
    
    StartState startState;
    startState.doAction(context);
    context->getState()->printState();

    StopState stopState;
    stopState.doAction(context);
    context->getState()->printState();

    return 0;
}