#include <iostream>
#include <vector>
#include <memory>

// Абстрактний клас (інтерфейс)
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// Реалізація для кола
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// Реалізація для прямокутника
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// Нова фігура (наприклад, трикутник) додається без зміни існуючого коду
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Circle>(5));
    shapes.push_back(std::make_shared<Rectangle>(4, 6));
    shapes.push_back(std::make_shared<Triangle>(3, 7));

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }

    return 0;
}
