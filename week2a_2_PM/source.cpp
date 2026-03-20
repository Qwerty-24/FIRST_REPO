#include <iostream>

inline int square(int n) {
    return n * n;
}

int main() {
    // Avoid compiler calc value
    int a, b;
    std::cin >> a >> b;

    // Deadcode removal
    int c = 10;

    // Subexpression factorisation
    int x = (a + b) * (a + b);
    int y = (a + b) + c;

    // In-line expansion
    int z = square(a);

    return x + y + z;
}