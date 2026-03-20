#include <iostream>

void write(int x) {
    std::cout << x << std::endl;
}

void fie(int n) {
    write(n);
}

void foo() {
    int n = 5;
    write(n);
}

int main() {
    int n = 10;

    fie(n);
    foo();
}