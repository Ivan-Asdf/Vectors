#include <iostream>

#include "geometry.h"

using namespace std;

int main() {
    Point p(1, 2, 3);
    Point p1(1, 2, 3);
    Point p2(1, 3, 5);

    Vector v(1, 1, 0);
    Vector v1(2, 2, 0);
    cout << v << endl;
    cout << v1 << endl;
    cout << v.unitVector() << endl;
    cout << v1.unitVector() << endl;
    cout << "Is parallel: " << v.isParallel(v1) << endl;
    cout << "Is perpendicular: " << v.isPerpendicular(v1) << endl;

    Vector v2(1, 1, 0);
    Vector v3(1, -1, 0);
    cout << v2 << endl;
    cout << v3 << endl;
    cout << "Is perpendicular: " << v2.isPerpendicular(v3) << endl;

    cout << v2 + v3 << endl;
    cout << v2 - v3 << endl;
    cout << v3 * 1.5 << endl;
}


