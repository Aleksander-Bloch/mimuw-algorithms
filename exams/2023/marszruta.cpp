#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;

vector<bool> visited2;
vector<int> path2;

void dfs(int source) {
    visited[source] = true;
    path.push_back(source);

    for (auto v : adj[source]) {
        if (!visited[v]) {
            dfs(v);
            path.push_back(source);
        }
    }
}

void dfs2(int source) {
    visited2[source] = true;
    path2.push_back(source);

    if (source == n - 1) {
        path.pop_back();
        for (auto v : path2) {
            path.push_back(v);
        }
    }

    for (auto v : adj[source]) {
        if (!visited2[v]) {
            dfs2(v);
        }
    }

    path2.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n);
    visited.resize(n);
    visited2.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    dfs(0);
    dfs2(0);
    cout << path.size() << "\n";
    for (auto v : path) {
        cout << v + 1 << " ";
    }
    cout << "\n";

    return 0;
}
