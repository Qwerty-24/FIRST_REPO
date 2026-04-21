#include <iostream>
using namespace std;

int main()
{
    int *p;

    cout << "p (uninitialized): " << p << endl;

    {
        int x = 5;
        p = &x;
        cout << "&x: " << &x << ", *p: " << *p << endl;
    }

    {
        int y = 100;
        cout << "address y: " << &y << endl;
    }

    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
}
