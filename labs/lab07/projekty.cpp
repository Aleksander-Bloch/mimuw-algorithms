// Topological sort based on:
// https://cp-algorithms.com/graph/topological-sort.html#implementation

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(int n) {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    int num_programmers[n];
    for (int i = 0; i < n; i++) {
        cin >> num_programmers[i];
    }

    for (int i = 0; i < n; i++) {
        adj.emplace_back();
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }

    topological_sort(n);
    for (int i = 0; i < n; i++) {
        for (int v : adj[ans[i]]) {
            num_programmers[v] = max(num_programmers[ans[i]], num_programmers[v]);
        }
    }

    sort(num_programmers, num_programmers + n);
    cout << num_programmers[k - 1] << "\n";

    return 0;
}
