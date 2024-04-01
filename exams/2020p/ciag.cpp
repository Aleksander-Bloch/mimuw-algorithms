#include <bits/stdc++.h>

using namespace std;

int n, m;
std::set<int> nums;
std::multiset<int> max_dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nums.insert(0);
    nums.insert(n);
    max_dist.insert(n);

    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        if (nums.find(a) == nums.end()) {
            auto ret = nums.insert(a);
            int left = *(--ret.first);
            int right = *(++(++ret.first));
            max_dist.erase(max_dist.lower_bound(right - left));
            max_dist.insert(a - left);
            max_dist.insert(right - a);
        }
        int ans = *(--max_dist.end());
        cout << ans << "\n";
    }

    return 0;
}
