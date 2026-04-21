#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> path;

void dfs(int u) {
    path.push_back(u);

    if (u == n - 1) {
        for (int x : path) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        for (int v : adj[u]) {
            dfs(v);
        }
    }
    path.pop_back();
}

int main() {
    cin >> n >> m;
    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(0);

    return 0;
}