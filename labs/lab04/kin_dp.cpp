#include <iostream>
#include <vector>

using namespace std;

const int MODULUS = 1'000'000'000;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[k][n] = {0};

    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < k; i++) {
        for (int j = n - 1 - i; j >= 0; j--) {
            for (int k = j + 1; k < n; k++) {
                dp[i][j] += (dp[i - 1][k] * (a[j] > a[k]));
                dp[i][j] %= MODULUS;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n - k + 1; i++) {
        res += dp[k - 1][i];
        res %= MODULUS;
    }

    cout << res << "\n";

    return 0;
}
