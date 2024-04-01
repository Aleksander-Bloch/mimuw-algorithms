#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 500'020;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<bool> bit_table(MAX_SIZE, false);
    int number_of_ones = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        while (bit_table[a]) {
            bit_table[a] = false;
            number_of_ones--;
            a++;
        }
        bit_table[a] = true;
        number_of_ones++;
        cout << number_of_ones << "\n";
    }



    return 0;
}
