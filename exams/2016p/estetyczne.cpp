#include <bits/stdc++.h>

using namespace std;

int n;
std::vector<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());
    int ans = 1;
    int current = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] - s[i - 1] <= 1) {
            current++;
        } else {
            ans = max(ans, current);
            current = 1;
        }
    }

    ans = max(ans, current);
    cout << ans << "\n";

    return 0;
}
