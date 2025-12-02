#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int legendre(int n, int p){
    int ans = 0;
    for(int i = p; i <= n; i *= p){
        ans += n/i;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << legendre(n, 5);
}