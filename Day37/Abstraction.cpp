#include <iostream>
using namespace std;

// Abstraction using Class
class Car {
private:
    int speed;
public:
    void setSpeed(int s) { if (s > 0) speed = s; }
    void displaySpeed() { cout << "Car Speed: " << speed << " km/h" << endl; }
};

// Abstraction using Abstract Class
class Shape {
public:
    virtual void draw() = 0; // Pure Virtual Function
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle" << endl; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Drawing Square" << endl; }
};

int main() {
    Car c;
    c.setSpeed(120);
    c.displaySpeed();

    Shape* s;
    Circle circ;
    Square sq;

    s = &circ; s->draw();
    s = &sq; s->draw();

    return 0;
}
