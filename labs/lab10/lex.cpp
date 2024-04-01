#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
long long P = 26;
long long Q = 82595524;

vector<long long> suffix_hashes;
vector<long long> powers_modulo;

int sym_to_num(char c) {
    return c - 'a' + 1;
}

void precompute_powers() {
    powers_modulo.resize(n + 1);
    powers_modulo[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers_modulo[i] = (powers_modulo[i-1] * P) % Q;
    }
}

void calculate_suffix_hashes() {
    suffix_hashes.resize(n + 1);
    suffix_hashes[n] = 0;
    suffix_hashes[n-1] = sym_to_num(s[n-1]);
    for (int i = n-2; i >= 0; i--) {
        suffix_hashes[i] = (sym_to_num(s[i]) + (suffix_hashes[i+1] * P) % Q) % Q;
    }
}

long long calculate_subword_hash(int i, int j) {
    return (suffix_hashes[i] - (suffix_hashes[j+1] * powers_modulo[j-i+1]) % Q + Q) % Q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> s;

    precompute_powers();
    calculate_suffix_hashes();

    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int min_len = min(b-a+1, d-c+1);
        int low = 0, high = min_len-1;
        int prefix_last_index = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (calculate_subword_hash(a-1, a-1+mid) == calculate_subword_hash(c-1, c-1+mid)) {
                prefix_last_index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int comp_index1 = a+prefix_last_index;
        int comp_index2 = c+prefix_last_index;

        if (comp_index1 > b-1 and comp_index2 > d-1) {
            cout << "=\n";
        } else if (comp_index1 > b-1 and comp_index2 <= d-1) {
            cout << "<\n";
        } else if (comp_index1 <= b-1 and comp_index2 > d-1) {
            cout << ">\n";
        } else {
            if (s[comp_index1] < s[comp_index2]) {
                cout << "<\n";
            } else if (s[comp_index1] > s[comp_index2]) {
                cout << ">\n";
            }
        }

    }

    return 0;
}
