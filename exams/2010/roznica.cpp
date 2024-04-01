#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int abs_d = abs(d);
    bool found = false;
    pair<int, int> result;

    int j = 0;

    for (int i = 0; i < n - 1; i++) {
        j = max(i + 1, j);
        while (j < n && a[j] - a[i] < abs_d) {
            j++;
        }
        if (j < n && a[j] - a[i] == abs_d) {
            result = make_pair(a[j], a[i]);
            if (d < 0) {
                swap(result.first, result.second);
            }
            found = true;
            break;
        }
    }

    if (found) {
        cout << result.first << " " << result.second << "\n";
    } else {
        cout << "NIE\n";
    }

    return 0;
}
