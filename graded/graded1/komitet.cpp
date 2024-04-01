#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MODULUS = 1'000'000'007;
constexpr int MAX_N = 500'000;

struct partial_answer {
    int min_com = MAX_N + 1;
    int num_ways = 0;
};

partial_answer combine(partial_answer a, partial_answer b) {
    if (a.min_com < b.min_com) {
        return a;
    }
    if (b.min_com < a.min_com) {
        return b;
    }
    return partial_answer {a.min_com, (a.num_ways + b.num_ways) % MODULUS};
}

partial_answer query(int v, int tl, int tr, int l, int r, partial_answer *t) {
    if (l > r) {
        return partial_answer {};
    }
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm), t), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r, t));
}

void update(int v, int tl, int tr, int pos, partial_answer &new_val, partial_answer *t) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, new_val, t);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val, t);
        }
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l;
    cin >> n >> k >> l;
    int ranks[n];
    for (int i = 0; i < n; i++) {
        cin >> ranks[i];
    }
    sort(ranks, ranks + n);
    
    partial_answer dp[4 * n];
    partial_answer initial {1, 1};
    update(1, 0, n - 1, 0, initial, dp);
    for (int i = 1; i < n; i++) {
        int mostDistant = lower_bound(ranks, ranks + i, ranks[i] - k) - ranks;
        if (mostDistant == 0) {
            update(1, 0, n - 1, i, initial, dp);
            continue;
        }
        int start = lower_bound(ranks, ranks + mostDistant, ranks[mostDistant - 1] - k) - ranks;
        if (ranks[i] - ranks[start] < l) {
            continue;
        }
        int end = upper_bound(ranks + start, ranks + i, ranks[i] - l) - ranks - 1;
        partial_answer new_val = query(1, 0, n - 1, start, end, dp);
        new_val.min_com += 1;
        update(1, 0, n - 1, i, new_val, dp);
    }
    int startResult = lower_bound(ranks, ranks + n, ranks[n - 1] - k) - ranks;
    partial_answer answer = query(1, 0, n - 1, startResult, n - 1, dp);
    cout << answer.min_com << " " << answer.num_ways << "\n";

    return 0;
}
