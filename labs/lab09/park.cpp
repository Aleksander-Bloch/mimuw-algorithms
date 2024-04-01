#include <bits/stdc++.h>

using namespace std;

// Graph structures
vector<vector<int>> adj;
vector<int> dfs_path;
vector<int> level;
int diam_end1, diam_end2;
int max_dist;

// Query structures
vector<int> ans;
vector<vector<pair<int, int>>> query_by_vertex;

void find_diam_end1(int v, int prev) {
    level[v] = 1 + level[prev];
    if (level[v] > max_dist) {
        max_dist = level[v];
        diam_end1 = v;
    }

    for (size_t i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] != prev) {
            find_diam_end1(adj[v][i], v);
        }
    }
}

void find_diam_end2(int v, int prev) {
    level[v] = 1 + level[prev];
    if (level[v] > max_dist) {
        max_dist = level[v];
        diam_end2 = v;
    }

    for (size_t i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] != prev) {
            find_diam_end1(adj[v][i], v);
        }
    }
}

void clear() {
    for (size_t i = 0; i < level.size(); i++) {
        level[i] = 0;
    }
    max_dist = 0;
}

void answer_queries(int v, int prev) {
    dfs_path.push_back(v);

    for (auto query : query_by_vertex[v]) {
        if (query.second < dfs_path.size()) {
            ans[query.first] = dfs_path[dfs_path.size() - 1 - query.second];
        }
    }

    for (size_t i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] != prev) {
            answer_queries(adj[v][i], v);
        }
    }
    dfs_path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    adj.resize(n + 1);
    level.resize(n + 1);
    query_by_vertex.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        if (a != -1) {
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
        if (b != -1) {
            adj[i].push_back(b);
            adj[b].push_back(i);
        }
    }

    int m; cin >> m;

    ans.assign(m, -1);

    for (int i = 0; i < m; i++) {
        int a, d; cin >> a >> d;
        query_by_vertex[a].emplace_back(i, d);
    }

    find_diam_end1(1, 0);
    clear();
    find_diam_end2(diam_end1, 0);

    answer_queries(diam_end1, 0);
    answer_queries(diam_end2, 0);

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}
