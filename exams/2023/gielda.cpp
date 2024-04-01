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

    long long stock_index = 0;

    int start = 0;
    int end = 0;
    while (end < n) {
        while (end < n - 1 && a[end + 1] > a[end]) {
            end++;
        }
        stock_index += a[end] - a[start];
        start = end + 1;
        end = start;
    }

    cout << stock_index << "\n";

    return 0;
}
