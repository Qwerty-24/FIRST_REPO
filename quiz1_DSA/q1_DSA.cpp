#include <iostream>
#include <stack>
#include <string>
using namespace std;
using ll = long long;

string reverse_s(string s){
    stack<char> st;
    int n = s.length();
    string res = "";
    for(char x : s){
        st.push(x);
    }
    while(n--){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; getline(cin, s);
    cout << reverse_s(s) << endl;
    return 0;
}