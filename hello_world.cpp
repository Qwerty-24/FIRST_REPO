#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    for (int i = 1; i < n; ++i){
        int idx = i-1; int x = arr[i];
        while (idx >= 0 && x < arr[idx]){
            arr[idx+1] = arr[idx];
            --idx;
        }
        arr[idx+1] = x;
    }
    for (int x : arr){
        cout << x << " ";
    }
    return 0;
}