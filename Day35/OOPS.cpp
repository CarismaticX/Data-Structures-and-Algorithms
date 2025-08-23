#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    // Member function to display detailsS
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Setter function
    void setAge(int a) {
        age = a;
    }

    // Getter function
    int getAge() {
        return age;
    }
};

int main() {
    // Creating object and calling methods
    Person p1("John", 25);
    p1.display();

    // Using setter to change age
    p1.setAge(30);
    cout << "Updated Age: " << p1.getAge() << endl;

    return 0;
}
