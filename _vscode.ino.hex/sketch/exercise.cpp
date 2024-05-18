#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\exercise.cpp"
#include<bits/stdc++.h>
using namespace std;
class fruit
{
protected:
    string name;
    string color;
    public:
    fruit(string name,string color)
    {
        this->name=name;
        this->color=color;
    }
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};
class apple:public fruit
{
private:
    string taste;
    public:
    apple(string color="red",string name="Apple",string taste="sweet"):fruit(name,color)
    {
        this->taste=taste;
    }
    string getTaste()
    {
        return taste;
    }
};
class banana:public fruit
{
private:
    string taste;
    public:
    banana(string name="banana",string color="yellow",string taste="salty"):fruit(name,color)
    {
        this->taste=taste;
    }
    string getTaste()
    {
        return taste;
    }
};
int main()
{
	apple a{ "red" };
	banana b{};

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

	return 0;
}
