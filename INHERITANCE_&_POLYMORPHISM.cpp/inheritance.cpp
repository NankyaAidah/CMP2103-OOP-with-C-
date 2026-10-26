#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
protected:
    string name;
    int age;

public:
    void setPersonDetails(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayPersonDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class inheriting from Person
class Student : public Person
{
protected:
    int studentID;
    string course;

public:
    void setStudentDetails(int id, string c)
    {
        studentID = id;
        course = c;
    }

    void displayStudentDetails()
    {
        displayPersonDetails();

        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};

// Derived class inheriting from Student
class Graduate : public Student
{
private:
    string classification;

public:
    void setClassification(string cl)
    {
        classification = cl;
    }

    void displayGraduateDetails()
    {
        displayStudentDetails();

        cout << "Degree Classification: "
             << classification << endl;
    }
};

int main()
{
    // Create an object of Person
    Person p;

    p.setPersonDetails("John", 25);

    cout << "PERSON DETAILS" << endl;
    p.displayPersonDetails();

    cout << "\n----------------------\n";

    // Create an object of Student
    Student s;

    s.setPersonDetails("Mary", 22);
    s.setStudentDetails(101, "Electrical Engineering");

    cout << "STUDENT DETAILS" << endl;
    s.displayStudentDetails();

    cout << "\n----------------------\n";

    // Create an object of Graduate
    Graduate g;

    g.setPersonDetails("David", 24);
    g.setStudentDetails(102, "Computer Engineering");
    g.setClassification("First Class");

    cout << "GRADUATE DETAILS" << endl;
    g.displayGraduateDetails();

    return 0;
}