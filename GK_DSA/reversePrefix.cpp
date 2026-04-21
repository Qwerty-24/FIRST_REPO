#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s = "", res = "";
    char ch;
    getline(cin, s);
    cin >> ch;
    int n = s.length();
    int idx = -1; 
    for (int i = 0; i < n; ++i){
        if (s[i] == ch){
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        // reverse(s.begin(), s.end());
        res = s;
    } 
    else {
        string tmp = s.substr(0, idx);
        reverse(tmp.begin(), tmp.end());
        res = ch + tmp + s.substr(idx+1);
    }
    cout << res << endl;
    return 0;
}