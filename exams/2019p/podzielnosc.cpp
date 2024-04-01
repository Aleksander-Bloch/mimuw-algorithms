#include <bits/stdc++.h>

using namespace std;

const int MODULUS = 3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<long long> pref_rem_counters[MODULUS];
    for (auto &pref_rem_counter : pref_rem_counters) {
        pref_rem_counter.resize(n + 1, 0);
    }

    int sum_modulo = 0;

    for (int i = 1; i <= n; i++) {
        sum_modulo = (sum_modulo + x[i - 1]) % MODULUS;
        for (auto &pref_rem_counter : pref_rem_counters) {
            pref_rem_counter[i] = pref_rem_counter[i - 1];
        }
        pref_rem_counters[sum_modulo][i]++;
    }

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        long long result = 0;
        for (auto &pref_rem_counter : pref_rem_counters) {
            long long pref_count_by_modulus_in_range = pref_rem_counter[r] - pref_rem_counter[max(0, l - 2)];
            result += (pref_count_by_modulus_in_range) * (pref_count_by_modulus_in_range - 1) / 2;
        }
        if (l == 1) {
            result += pref_rem_counters[0][r] - pref_rem_counters[0][l - 1];
        }
        cout << result << "\n";
    }

    return 0;
}
