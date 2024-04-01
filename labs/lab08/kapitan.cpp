// Dijkstra algorithm implementation based on: https://cp-algorithms.com/graph/dijkstra_sparse.html

#include <bits/stdc++.h>

using namespace std;

typedef struct Island {
    int id, x, y;
} Island;

typedef struct Edge {
    int to, len;
} Edge;

bool sort_by_x_asc(const Island &a, const Island &b) {
    return a.x < b.x;
}

bool sort_by_y_asc(const Island &a, const Island &b) {
    return a.y < b.y;
}

const int INF = INT_MAX;
vector<vector<Edge>> adj;

void dijkstra(int s, vector<int> &d) {
    size_t n = adj.size();
    d.assign(n, INF);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.to;
            int len = edge.len;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Island> islands(n);

    for (int i = 0; i < n; i++) {
        islands[i].id = i;
        cin >> islands[i].x;
        cin >> islands[i].y;
    }

    adj.resize(n);

    // sort by the x coordinate, to find x-neighbours.
    sort(islands.begin(), islands.end(), sort_by_x_asc);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            adj[islands[i].id].push_back({islands[i-1].id, islands[i].x - islands[i-1].x});
        }
        if (i < n - 1) {
            adj[islands[i].id].push_back({islands[i+1].id, islands[i+1].x - islands[i].x});
        }
    }

    // do the same for y-neighbours
    sort(islands.begin(), islands.end(), sort_by_y_asc);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            adj[islands[i].id].push_back({islands[i-1].id, islands[i].y - islands[i-1].y});
        }
        if (i < n - 1) {
            adj[islands[i].id].push_back({islands[i+1].id, islands[i+1].y - islands[i].y});
        }
    }

    vector<int> d;
    dijkstra(0, d);
    cout << d[n-1] << "\n";

    return 0;
}
