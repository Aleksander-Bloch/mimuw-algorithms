#include <iostream>

using namespace std;

const int MODULUS = 1'000'000'000;

void update(int v, int tl, int tr, int pos, int new_val, int *t) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val, t);
        else
            update(v*2+1, tm+1, tr, pos, new_val, t);
        t[v] = (t[v*2] + t[v*2+1]) % MODULUS;
    }
}

int sum(int v, int tl, int tr, int l, int r, int *t) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return (sum(v*2, tl, tm, l, min(r, tm), t)
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r, t)) % MODULUS;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int segtree[k][4 * n];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4 * n; j++) {
            segtree[i][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        update(1, 0, n - 1, a[i] - 1, 1, segtree[0]);
        for (int j = 1; j < k; j++) {
            int valid_inv = sum(1, 0, n - 1, 0, a[i] - 2, segtree[j - 1]);
            update(1, 0, n - 1, a[i] - 1, valid_inv, segtree[j]);
        }
    }

    int res = sum(1, 0, n - 1, 0, n - 1, segtree[k - 1]);
    cout << res << "\n";

    return 0;
}
