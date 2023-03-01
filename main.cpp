
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
private:
public:
    virtual double area() {
        return 0;
    }
};

class Rectangle: public Shape {
private:
    double width, height;
public:
    Rectangle(double width, double height): width(width), height(height) { }
    double area() {
        return (width * height);
    }
};

class Circle: public Shape {
private:
    double radius;
public:
    Circle(double radius): radius(radius) { }
    double area() {
        return 3.14 * radius * radius;
    }
};

double operator+(Shape &s1, Shape &s2) {
    return s1.area() + s2.area();
}

double operator+(double area, Shape &s) {
    return area + s.area();
}

int main() {
    Rectangle shape1(10, 10);
    Rectangle shape2(5, 10);
    Circle shape3(5);

    // adding shape objects together returns the sum of their areas
    double totalArea = shape1 + shape2 + shape3;
    cout << "The total area is " << totalArea << endl;

    return 0;
}
