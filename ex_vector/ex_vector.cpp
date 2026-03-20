#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

int main(){
    vector <int> v; // khai bao
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x); // them vao
    }
    for (int x : v) { //duyet = for each
        cout << x << " ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); ++i){ // duyet = chi so
        cout << v[i] << " ";
    }
    for (auto it = v.begin(); it != v.end; ++it){ // duyet = interator
        cout << *it << " ";
    }

    sort(v.begin(), v.end()); //sap xep
}