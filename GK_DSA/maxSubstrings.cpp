#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int a[1000] = {0}, res = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i){
        if ((a[int(s[i])]) == 0){
            a[int(s[i])]++;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}