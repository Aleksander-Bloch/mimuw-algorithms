#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // singletons
    long long result = n;
    vector<long long> pref_ones_counter(n + 1, 0);
    vector<long long> suf_threes_counter(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pref_ones_counter[i] = pref_ones_counter[i - 1];
        if (a[i - 1] == 1) {
            pref_ones_counter[i]++;
        }
        suf_threes_counter[i] = suf_threes_counter[i - 1];
        if (a[n - i] == 3) {
            suf_threes_counter[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            result += suf_threes_counter[n - 1 - i];
        }
        else if (a[i] == 2) {
            // 1 2
            result += pref_ones_counter[i];
            // 2 3
            result += suf_threes_counter[n - 1 - i];
            // 1 2 3
            result += pref_ones_counter[i] * suf_threes_counter[n - 1 - i];
        }
    }

    cout << result << "\n";

    return 0;
}
