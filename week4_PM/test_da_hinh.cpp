#include <iostream>
using namespace std;

float nhan2(float x){
    return (float)x*2;
}

int nhan2(int x){
    return x*2;
}
int main(){
    cout << nhan2(36) << endl;
    cout << nhan2(36.1) << endl;
    return 0;
}
