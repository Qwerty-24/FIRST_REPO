#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    for (int i = 0; i < n; ++i){
        int min = 1e9+7;
        int min_idx = n-1;
        for (int j = i+1; j < n-1; ++j){
            if (arr[j] < min){
                min = arr[j];
                min_idx = j;
            }
        }
        if (arr[min_idx] < arr[i]){
            swap(arr[min_idx], arr[i]);
        }
    }
    for (int x : arr){
        cout << x << " ";
    }
    return 0;
}