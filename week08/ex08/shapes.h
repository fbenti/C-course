#ifndef SHPAES_H_
#define SHPAES_H_

class Shape {
public:
    virtual double area(void) = 0;
    virtual double perimeter(void) = 0;
    virtual double height(void) = 0; 
    virtual double width(void) = 0;
    virtual void rotate(void) = 0;
};

class Rectangle: public Shape {
private:
    double h;
    double w;
public:
    Rectangle(double x, double y);
    double area(void);
    double perimeter(void);
    double height(void);
    double width(void);
    void rotate(void);
};

class Square: public Rectangle {
private:
    double length;
public:
    Square(double x);
    double area(void);
    double perimeter(void);
    double height(void);
    double width(void);
};

class Circle: public Shape {
private: 
    double radius;
public:
    Circle(double x);
    double area(void);
    double perimeter(void);
    double height(void);
    double width(void);
    void rotate(void);
};


#endif /* SHAPES_H_*/