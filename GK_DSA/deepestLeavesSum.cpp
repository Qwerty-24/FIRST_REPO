#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<int> leftChild(n), rightChild(n);
    for (int i = 0; i < n; i++) {
        cin >> leftChild[i] >> rightChild[i];
    }

    // BFS
    queue<int> q;
    q.push(0); 

    int res = 0;

    while (!q.empty()) {
        int size = q.size();
        int sum = 0;

        for (int i = 0; i < size; i++) {
            int u = q.front();
            q.pop();

            if (leftChild[u] == -1 && rightChild[u] == -1) {
                sum += val[u];
            }

            if (leftChild[u] != -1) {
                q.push(leftChild[u]);
            }
            if (rightChild[u] != -1) {
                q.push(rightChild[u]);
            }
        }

        if (sum > 0) {
            res = sum;
        }
    }

    cout << res;
    return 0;
}