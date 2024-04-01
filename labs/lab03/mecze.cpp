#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    int rozmiar_druzyny = n / 2;
    vector<bitset<64>> etykiety(n);

    for (int i = 0; i < m; i++) {
        int zawodnik;
        for (int j = 0; j < rozmiar_druzyny; j++) {
            cin >> zawodnik;
            etykiety[zawodnik - 1] |= (1LL << i);
        }
        for (int j = 0; j < rozmiar_druzyny; j++) {
            cin >> zawodnik;
        }
    }

    unordered_set<bitset<64>> etykiety_bez_powtorzen;

    for (auto etykieta : etykiety) {
        etykiety_bez_powtorzen.insert(etykieta);
    }

    if (etykiety_bez_powtorzen.size() == n) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }

    return 0;
}