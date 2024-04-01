#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<bool> bit;

vector<vector<int>> adj;
vector<int> spots;
vector<bool> visited;

void dfs(int source) {
    visited[source] = true;
    for (auto v : adj[source]) {
        if (!visited[v]) {
            if (bit[v]) {
                visited[v] = true;
                spots.push_back(v);
            } else {
                dfs(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    bit.resize(n);
    adj.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        if (b == 1) {
            bit[i] = true;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    dfs(0);
    sort(spots.begin(), spots.end());
    for (auto v : spots) {
        cout << v + 1 << "\n";
    }

    return 0;
}
