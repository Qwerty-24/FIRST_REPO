#include <bits/stdc++.h>
using namespace std;

int count_division(int n){
    int a[3];
    int cnt_div = 0;
    for (int i = 1; i <= sqrt(n); ++i){
        if (n % i == 0){
            cnt_div++;
            if (i! == n/i){
                cnt_div++;
            }
        }
    }
    return cnt_div
}

int main(){

}