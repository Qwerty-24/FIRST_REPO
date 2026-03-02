#include <iostream>
using namespace std;

int interpolation_search(int *a, int n, int x){
    int m, l = 0, h = n-1;
    while ((a[h] != a[l]) && (x >= a[l]) && (x <= a[h])){
        m = l + (x - a[l]) * ((h - l)/ (a[h] - a[l]))
        if (x < a[m]) h = m-1;
        else if (x > a[m]) l = m+1;
        else return m;
    }
    if (x == a[l]) return 1;
    else return -1;
}

int main(){
    int *a, n;
    cin >> n;;
    a = new int[n];
    for (int i=0; i<n; ++i){
        cin >> a[i]
    }
    
}