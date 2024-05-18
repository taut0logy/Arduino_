#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\multiple_inheritance.cpp"
#include <iostream>

// Base class 1
class Shape 
{
public:
    virtual double area() const = 0;
};

// Base class 2
class Color 
{
public:
    virtual std::string color() const = 0;
};

// Derived class that inherits from both Shape and Color
class Rectangle : public Shape, public Color 
{
public:
    Rectangle(double width, double height, std::string color) : width_(width), height_(height), color_(color) {}

    double area() const override 
    {
        return width_ * height_;
    }

    std::string color() const override 
    {
        return color_;
    }

private:
    double width_;
    double height_;
    std::string color_;
};

int main() 
{
    Rectangle rectangle(5, 10, "red");
    std::cout << "Area: " << rectangle.area() << std::endl; // Output: Area: 50
    std::cout << "Color: " << rectangle.color() << std::endl; // Output: Color: red
    return 0;
}
