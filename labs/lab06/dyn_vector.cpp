#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> seq;
    int m; cin >> m;
    int w = 0;
    for (int i = 0; i < m; i++) {
        char op;
        int j, x, k;
        cin >> op;
        if (op == 'i') {
            cin >> j >> x >> k;
            j = (j + w) % (int) (seq.size() + 1);
            seq.insert(seq.begin() + j, k, x);
        } else if (op == 'g') {
            cin >> j;
            j = (j + w) % (int) seq.size();
            w = seq[j];
            cout << w << "\n";
        }
    }

    return 0;
}
