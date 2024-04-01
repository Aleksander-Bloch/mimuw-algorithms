#include <iostream>

using namespace std;

int min_dlugosc_matrycy(string tapeta) {
    int i = 0;
    while (i < tapeta.size() && tapeta[i] == '*') {
        i++;
    }
    
    if (i == tapeta.size() || i == tapeta.size() - 1) {
        return 1;
    }

    int min_odleglosc = INT32_MAX;
    char ostatnia_litera = tapeta[i];
    int indeks_ostatniej_litery = i;

    for (int j = i + 1; j < tapeta.size(); j++) {
        if (tapeta[j] != '*') {
            if (tapeta[j] != ostatnia_litera) {
                min_odleglosc = min(min_odleglosc, j - indeks_ostatniej_litery - 1);
                ostatnia_litera = tapeta[j];
                indeks_ostatniej_litery = j;
            } else {
                indeks_ostatniej_litery = j;
            }
        }
    }

    if (min_odleglosc == INT32_MAX) {
        return 1;
    }

    return tapeta.size() - min_odleglosc;
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tapeta;
    cin >> tapeta;

    cout << min_dlugosc_matrycy(tapeta) << "\n";

    return 0;
}