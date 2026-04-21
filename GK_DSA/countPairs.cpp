#include <iostream>
using namespace std;

int main(){
    int n, tar, res = 0;
    cin >> n >> tar;
    int a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j){
            if (a[i] + a[j] < tar){
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}