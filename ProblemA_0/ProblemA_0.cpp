#include <bits/stdc++.h>
using namespace std;

int cnt_divisor(int n){
    int cnt = 0;
    for(int i = 1; i <= sqrt(n); ++i){
        if (n % i == 0){
            cnt++;
            if(i != n/i) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    while(t--){
        int n; 
        cin >> n;
        int k = 3, i = 2;
        vector <int> v;
        while(k && i <= n){
            if (n % i == 0){
                v.push_back(i);
                n /= i;
                i++;
                k--;
            }
            else{
                i++;
            }
        }
        if (k == 0){
            cout << "YES\n";
            for (int x : v){
                cout << x << " ";
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
}