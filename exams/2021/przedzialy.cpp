#include <bits/stdc++.h>

using namespace std;

int n, m;
std::set<int> max_set;
std::set<int> min_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == '+') {
            if (l == 1) {
                max_set.insert(r);
            } else {
                min_set.insert(l);
            }
        } else {
            // c == '-'
            if (l == 1) {
                max_set.erase(r);
            } else {
                min_set.erase(l);
            }
        }

        int max_right = 0;
        int min_left = n + 1;
        if (!max_set.empty()) {
            max_right = *(--max_set.end());
        }
        if (!min_set.empty()) {
            min_left = *(min_set.begin());
        }

        int ans = max(0, min_left - max_right - 1);

        cout << ans << "\n";
    }

    return 0;
}
