#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\overload_output.cpp"
#include <iostream>
#include <string>
using namespace std;
class Person 
{
public:
    Person(string name, int age) : name_(name), age_(age) {}

    // Overload the << operator for the Person class
   /*  friend std::ostream& operator<<(std::ostream& os, const Person& person) 
    {
        os << "Name: " << person.name_ << ", Age: " << person.age_;
        return os;
    } */
    friend ostream& operator<<(ostream& os, Person person) 
    {
        os << "Name: " << person.name_ << ", Age: " << person.age_;
        return os;
    }
    /* ostream& operator<<(ostream& os)
    {
        os << "Name: " << name_ << ", Age: " << age_;
        return os;
    } */

private:
    string name_;
    int age_;
};

int main() 
{
    Person person("Alice", 30);
    cout << person << endl; // Output: Name: Alice, Age: 30
    return 0;
}
