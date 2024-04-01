#include <iostream>

using namespace std;

void update(int v, int tl, int tr, int l, int r, int new_val, int t[]) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        t[v] = new_val * (r - l + 1);
    } else {
        if (t[v] == tr - tl + 1 || t[v] == 0) {
            t[v * 2] = (t[v] + 1) / 2;
            t[v * 2 + 1] = t[v] / 2;
        }
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val, t);    
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val, t);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int segtree[4 * n] = {0};

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int toNum = (c == 'B') ? 1 : 0;
        update(1, 0, n - 1, a - 1, b - 1, toNum, segtree);
        int res = segtree[1];
        cout << res << "\n";
    }

    return 0;
}
