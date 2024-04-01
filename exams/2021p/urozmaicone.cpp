#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 10'000;
const int MODULUS = 1'000'000'000;

int n, result;
std::vector<int> a, partial_results, results_by_number;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    result = 0;
    partial_results.resize(n, 0);
    results_by_number.resize(MAX_VALUE + 1, 0);

    for (int i = 0; i < n; i++) {
        partial_results[i] = (result - results_by_number[a[i]] + 1 + MODULUS) % MODULUS;
        result = (result + partial_results[i]) % MODULUS;
        results_by_number[a[i]] = (results_by_number[a[i]] + partial_results[i]) % MODULUS;
    }

    cout << result << "\n";

    return 0;
}
