/*
    Factory pattern is one of the most used design patterns. 
    This type of design pattern comes under creational pattern as this pattern provides 
    one of the best ways to create an object.
    In Factory pattern, we create object without exposing the creation logic to the client 
    and refer to newly created object using a common interface.
*/
#include <iostream>
#include <memory>
using namespace std;

enum ShapeType {
    RECTANGLE,
    SQUARE,
    CIRCLE
};

class Shape {
public:
    virtual void draw()=0;
};

class Rect: public Shape {
public:
    void draw() override {
        cout << "Rectangle::draw() method" << endl;
    }
};

class Square: public Shape {
public:
    void draw() override {
        cout << "Square::draw() method" << endl;
    }
};

class Circle: public Shape {
public:
    void draw() override {
        cout << "Circle::draw() method" << endl;
    }
};

class ShapeFactory {
public:
    Shape *getShape(ShapeType type) {
        switch(type) {
            case RECTANGLE:
                return new Rect();
            case SQUARE:
                return new Square();
            case CIRCLE:
                return new Circle();
        }
        return nullptr;
    }
};

int main() {
    ShapeFactory *sf = new ShapeFactory();
    Shape *shape1 = sf->getShape(RECTANGLE);
    shape1->draw();
    Shape *shape2 = sf->getShape(SQUARE);
    shape2->draw();
    Shape *shape3 = sf->getShape(CIRCLE);
    shape3->draw();
}