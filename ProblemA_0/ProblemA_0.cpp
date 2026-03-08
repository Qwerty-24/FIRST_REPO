#include <bits/stdc++.h>
using namespace std;

// int cnt_divisor(int n){
//     int cnt = 0;
//     for(int i = 1; i <= sqrt(n); ++i){
//         if (n % i == 0){
//             cnt++;
//             if(i != n/i) cnt++;
//         }
//     }
//     return cnt;
// }

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

        int tmp = n;
        while(k && i <= sqrt(tmp)){
            if (tmp % i == 0){
                v.push_back(i);
                tmp /= i;
                k--;
                if (k == 1){
                    int a3 = n;
                    for (int x : v){
                        a3 /= x; 
                    }
                    if (a3 * v[0] * v[1] == n && a3 != v[0] && a3 != v[1]){
                        v.push_back(a3);
                        k--;
                        // break;
                    }
                }
            }
            i++;
        }

        if (k == 0){
            cout << "YES\n";
            for (int i = 0; i < v.size()-1; ++i){
                cout << v[i] << " ";
                n /= v[i];
            }
            cout << n << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
}