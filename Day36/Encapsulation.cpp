#include <iostream>
using namespace std;

// Encapsulation Example: Student Class
class Student {
private:
    // Private Data Members (hidden from outside)
    string name;
    int age;
    float marks;

public:
    // Setter Functions (to modify private data safely)
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        if (a > 0) age = a;
        else cout << "Invalid Age!" << endl;
    }

    void setMarks(float m) {
        if (m >= 0 && m <= 100) marks = m;
        else cout << "Invalid Marks!" << endl;
    }

    // Getter Functions (to access private data)
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    float getMarks() {
        return marks;
    }

    // Display Function
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1;

    // Setting values using setters (cannot access directly)
    s1.setName("John");
    s1.setAge(20);
    s1.setMarks(85.5);

    // Displaying values using getters and display function
    cout << "Student Info (Using Getters):" << endl;
    cout << "Name: " << s1.getName() << endl;
    cout << "Age: " << s1.getAge() << endl;
    cout << "Marks: " << s1.getMarks() << endl;

    cout << "\nStudent Info (Using Display Function):" << endl;
    s1.display();

    return 0;
}
