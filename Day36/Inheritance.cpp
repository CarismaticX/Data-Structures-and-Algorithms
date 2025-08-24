#include <iostream>
using namespace std;

// ---------- Single Inheritance ----------
class Animal {
public:
    void eat() { cout << "Animal is eating\n"; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Dog is barking\n"; }
};

// ---------- Multiple Inheritance ----------
class Engine {
public:
    void start() { cout << "Engine started\n"; }
};

class Wheels {
public:
    void roll() { cout << "Wheels rolling\n"; }
};

class Car : public Engine, public Wheels {};

// ---------- Multilevel Inheritance ----------
class LivingBeing {
public:
    void breathe() { cout << "Breathing\n"; }
};

class Mammal : public LivingBeing {
public:
    void walk() { cout << "Mammal is walking\n"; }
};

class Human : public Mammal {
public:
    void speak() { cout << "Human is speaking\n"; }
};

// ---------- Hierarchical Inheritance ----------
class Shape {
public:
    void area() { cout << "Calculating area\n"; }
};

class Circle : public Shape {};
class Square : public Shape {};

// ---------- Hybrid Inheritance (Diamond Problem Solution) ----------
class A {
public:
    void display() { cout << "Class A function\n"; }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    cout << "=== Single Inheritance ===\n";
    Dog d;
    d.eat();
    d.bark();

    cout << "\n=== Multiple Inheritance ===\n";
    Car c;
    c.start();
    c.roll();

    cout << "\n=== Multilevel Inheritance ===\n";
    Human h;
    h.breathe();
    h.walk();
    h.speak();

    cout << "\n=== Hierarchical Inheritance ===\n";
    Circle cir;
    Square sq;
    cir.area();
    sq.area();

    cout << "\n=== Hybrid (Virtual) Inheritance ===\n";
    D obj;
    obj.display();

    return 0;
}
