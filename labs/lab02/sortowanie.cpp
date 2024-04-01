#include <iostream>
#include <vector>

using namespace std;

constexpr uint32_t MOD = 1'000'000'000;

int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint16_t n;
    cin >> n;
    vector<uint16_t> s(n);

    for (uint16_t i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<uint32_t>> L(n, vector<uint32_t>(n, 0));
    vector<vector<uint32_t>> R(n, vector<uint32_t>(n, 0));

    for (uint16_t i = 0; i < n; i++) {
        L[i][i] = R[i][i] = 1;
    }

    for (uint16_t i = 0; i < n - 1; i++) {
        L[i][i + 1] = R[i][i + 1] = (s[i] < s[i + 1]);
    }

    for (uint16_t i = 2; i < n; i++) {
        for (uint16_t j = 0; j < n - i; j++) {
            L[j][i + j] += ((s[j] < s[j + 1]) * L[j + 1][i + j]) % MOD;
            L[j][i + j] += ((s[j] < s[i + j]) * R[j + 1][i + j]) % MOD;
            L[j][i + j] %= MOD;

            R[j][i + j] += ((s[i + j] > s[j]) * L[j][i + j - 1]) % MOD;
            R[j][i + j] += ((s[i + j] > s[i + j - 1]) * R[j][i + j - 1]) % MOD;
            R[j][i + j] %= MOD;
        }
    }

    uint32_t odp = (n > 1) ? (L[0][n - 1] + R[0][n - 1]) % MOD : 1;
    cout << odp << "\n";

    return 0;
}