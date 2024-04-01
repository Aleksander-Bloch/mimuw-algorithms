#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 10;

int n;
std::vector<int> a;
std::vector<long long> pref_counters[MAX_VALUE + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= MAX_VALUE; i++) {
        pref_counters[i].resize(n + 1, 0);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= MAX_VALUE; j++) {
            pref_counters[j][i] = pref_counters[j][i - 1];
        }
        pref_counters[a[i - 1]][i]++;
    }

    long long result = 0;

    for (int k = 2; k < n; k++) {
        if (a[k] != 1) {
            for (int z = 1; z < (a[k] + 1) / 2; z++) {
                result += pref_counters[z][k] * pref_counters[a[k] - z][k];
            }
            if (a[k] % 2 == 0) {
                result += pref_counters[a[k] / 2][k] * (pref_counters[a[k] / 2][k] - 1) / 2;
            }
        }
    }

    cout << result << "\n";


    return 0;
}
