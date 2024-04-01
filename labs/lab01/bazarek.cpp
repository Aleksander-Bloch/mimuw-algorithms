#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<ll> licz_sumy_sufiksowe(vector<int> &liczby) {
    vector<ll> sumy_sufiksowe(liczby.size() + 1, 0);
    for (int i = 1; i <= liczby.size(); i++) {
        sumy_sufiksowe[i] = sumy_sufiksowe[i - 1] + liczby[liczby.size() - i];
    }
    return sumy_sufiksowe;
}

void wczytaj_wg_parzystosci(vector<int> &liczby, vector<int> &nparz, vector<int> &parz) {
    for (auto x: liczby) {
        if (x % 2) {
            nparz.push_back(x);
        } else {
            parz.push_back(x);
        }
    }
}

vector<int> licz_nparz_od_tylu(vector<int> &liczby) {
    vector<int> ile_nparz(liczby.size() + 1, 0);

    for (int i = 1; i <= liczby.size(); i++) {
        ile_nparz[i] = ile_nparz[i - 1] + (liczby[liczby.size() - i] % 2);
    }

    return ile_nparz;
}

vector<ll> licz_maks_nparz_ceny(vector<ll> &suma_i_najwiekszych_cen, vector<int> &nparz_ceny,
                   vector<int> &parz_ceny, vector<int> &ile_nparz_w_sufiksie ) {
    
    vector<ll> maks_nparz_ceny(suma_i_najwiekszych_cen);

    for (int i = 1; i < maks_nparz_ceny.size(); i++) {
        if (maks_nparz_ceny[i] % 2 == 0) {
            ll maks = -1;

            int min1_index = nparz_ceny.size() - ile_nparz_w_sufiksie[i];
            int maks1_index = parz_ceny.size() - (i - ile_nparz_w_sufiksie[i]) - 1;

            if (min1_index < nparz_ceny.size() && maks1_index >= 0) {
                int min_wybrana_nparz = nparz_ceny[min1_index];
                int maks_niewybrana_parz = parz_ceny[maks1_index];
                maks = maks_nparz_ceny[i] - min_wybrana_nparz + maks_niewybrana_parz;
            }


            int min2_index = parz_ceny.size() - (i - ile_nparz_w_sufiksie[i]);
            int maks2_index = nparz_ceny.size() - ile_nparz_w_sufiksie[i] - 1;

            if (min2_index < parz_ceny.size() && maks2_index >= 0) {
                int min_wybrana_parz = parz_ceny[min2_index];
                int maks_niewybrana_nparz = nparz_ceny[maks2_index];
                maks = max(maks, maks_nparz_ceny[i] - min_wybrana_parz + maks_niewybrana_nparz);
            }

            maks_nparz_ceny[i] = maks;
        }
    }

    return maks_nparz_ceny;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> ceny(n);
    for (int i = 0; i < n; i++) {
        cin >> ceny[i];
    }
    cin >> m;
    
    vector<ll> suma_i_najwiekszych_cen = licz_sumy_sufiksowe(ceny);
    vector<int> nparz_ceny, parz_ceny;
    wczytaj_wg_parzystosci(ceny, nparz_ceny, parz_ceny);
    vector<int> ile_nparz_w_sufiksie = licz_nparz_od_tylu(ceny);

    vector<ll> maks_nparz_ceny = licz_maks_nparz_ceny(suma_i_najwiekszych_cen, nparz_ceny, 
                                                      parz_ceny, ile_nparz_w_sufiksie);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        cout << maks_nparz_ceny[k] << "\n";
    }
    
    return 0;
}