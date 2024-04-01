#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<long long> nums;

    int n; cin >> n;
    long long a; cin >> a;
    nums.insert(a);

    long long result = 0;

    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        if (nums.find(a) == nums.end()) {
            auto ret = nums.insert(a);
            if (ret.first == nums.begin()) {
                long long delta_adj = *(++nums.begin()) - *nums.begin();
                result += delta_adj * delta_adj;
            } else if (ret.first == --nums.end()) {
                long long delta_adj = *(--nums.end()) - *(--(--nums.end()));
                result += delta_adj * delta_adj;
            } else {
                auto left = --ret.first;
                auto right = ++(++ret.first);
                --ret.first;
                result += (*ret.first - *left) * (*ret.first - *left);
                result += (*right - *ret.first) * (*right - *ret.first);
                result -= (*right - *left) * (*right - *left);
            }
        }
        cout << result << "\n";
    }


    return 0;
}
