#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

set<vector<int>> ans;
vector<int> nums, sum;

void bfbt(int base, int at, int sumat) {
    if (sumat == base) {
        ans.insert(sum);
        return;
    }
    for (int i = at; i < nums.size(); i++) {
        sum.push_back(nums[i]);
        bfbt(base, i + 1, sumat + nums[i]);
        sum.pop_back();
    }
}

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, in = 0;
    while (cin >> t >> n && t && n) {
        ans.clear();
        nums.clear();
        sum.clear();
        cout << "Sums of " << t << ":\n";
        while (n-- && cin >> in) nums.push_back(in);
        sort(nums.rbegin(), nums.rend());
        bfbt(t, 0, 0);
        if (ans.size()) {
            auto i = ans.begin()->begin();
            for (auto a = ans.rbegin(); a != ans.rend(); a = next(a)) {
                for (i = a->begin(); i != a->end() - 1; i = next(i)) {
                    cout << *i << "+";
                }
                cout << *i << "\n";
            }
        } else cout << "NONE\n";
    }
    return 0;
}
