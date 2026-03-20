#include <iostream>

int x = 10;

int main() {
    std::cout << x << std::endl;

    int x = 20;
    {
        std::cout << x << std::endl;

        int x = 30;
        std::cout << x << std::endl;
    }
    // std::cout << x << std::endl;
    return 0;
}