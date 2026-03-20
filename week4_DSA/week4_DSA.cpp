// #include <iostream>
// using namespace std;

// class Point {
// public:
//     int dx;
//     int dy

//     Node(int value, int value) : dx(value), dy(value) {}
// };

// int main(){
//     Point A, B, C, D;
//     cin >> A->dx >> A->dy >> B->
//     delta = 
// }

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

const double EPS = 1e-9;

bool isZero(double value) {
    return fabs(value) < EPS;
}

double determinant(double a1, double a2, double b1, double b2) {
    return a1 * b2 - a2 * b1;
}

int findIntersection(Point A, Point B, Point C, Point D, Point &P) {
    double delta = determinant(A.x - B.x, A.y - B.y, C.x - D.x, C.y - D.y);

    if (isZero(delta)) {
        double check = determinant(B.x - A.x, B.y - A.y, C.x - A.x, C.y - A.y);

        if (isZero(check)) {
            return 1; 
        } else {
            return 0; 
        }
    }

    double t1 = A.x * B.y - A.y * B.x;
    double t2 = C.x * D.y - C.y * D.x;

    P.x = (t1 * (C.x - D.x) - (A.x - B.x) * t2) / delta;
    P.y = (t1 * (C.y - D.y) - (A.y - B.y) * t2) / delta;

    return 2;
}

int main() {
    Point A, B, C, D, P;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    int result = findIntersection(A, B, C, D, P);

    if (result == 0) {
        cout << "No";
    } 
    else if (result == 1) {
        cout << "Many";
    } 
    else {
        cout << fixed << setprecision(2);
        cout << P.x << " " << P.y;
    }

    return 0;
}