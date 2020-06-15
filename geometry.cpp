#include <iostream>
#include <cmath>

#include "geometry.h"

using namespace std;

//Point::Point() : x(0), y(0), z(0) {}
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}
double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

bool Point::operator==(Point other) {
    if(x == other.x && y == other.y && z == other.z)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& out, const Point& p) {
    return out << "Point: " << " x: " << p.x << " y: " << p.y << " z: " << p.z;
}

Vector::Vector(double x, double y, double z) : Point(x, y, z) {}
Vector::Vector(Point p1, Point p2) : Point(p2.getX() - p1.getX(), p2.getY() - p1.getY(), p2.getZ() - p1.getZ()) {}

ostream& operator<<(ostream& out, const Vector& v) {
    return out << "Vector: " << " x: " << v.x << " y: " << v.y << " z: " << v.z;
}

double Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::unitVector() const {
    double len = length(); 
    if (len == 0)
        throw VectorLengthException();
    return Vector(x / len, y / len, z / len);
}

bool Vector::isZeroVector() const {
    if (x == 0 && y == 0 && z == 0)
        return true;
    else
        return false;
}

bool Vector::isParallel(const Vector& other) const {
    // If both vectors have the same component equal to zero then the logic required
    // in the task doesnt work, even though it should
    // Vectors {1, 1, 0} and {2, 2, 0} are parallel
    if (unitVector() == other.unitVector())
        return true;
    else
        return false;
}

bool Vector::isPerpendicular(const Vector& other) const {
    if (x * other.x + y * other.y + z * other.z == 0)
        return true;
    else
        return false;
}

Vector operator+(const Vector& v1, const Vector& v2) {
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector operator-(const Vector& v1, const Vector& v2) {
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector& Vector::operator*(const double scalar) {
    x*=scalar;
    y*=scalar;
    z*=scalar;
    return *this;
}

Vector operator^(const Vector& v1, const Vector& v2) {
}
