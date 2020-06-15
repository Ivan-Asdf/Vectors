#include <iostream>

using namespace std;

class Element {
};

class Point : public Element {
public:
    //Point();
    Point(double x, double y, double z);
    double getX() const;
    double getY() const;
    double getZ() const;

    bool operator==(Point other);
    friend ostream& operator<<(ostream& out, const Point& p);

protected:
    double x, y, z;
};

#include <exception>

class VectorLengthException : public exception {
};

class Vector : public Point {
public:
    Vector(double x, double y, double z);
    Vector(Point p1, Point p2);

    friend ostream& operator<<(ostream& out, const Vector& v);

    double length() const;
    Vector unitVector() const;
    bool isZeroVector() const;
    bool isParallel(const Vector& other) const;
    bool isPerpendicular(const Vector& other) const;

    friend Vector operator+(const Vector& v1, const Vector& v2);
    friend Vector operator-(const Vector& v1, const Vector& v2);
    Vector& operator*(const double scalar);
    friend Vector operator^(const Vector& v1, const Vector& v2);
};
