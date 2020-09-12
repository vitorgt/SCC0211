#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, m = 0, in = 0, sum = 0;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        sum = n + m - 2;
        vector<vector<int>> change(n + m, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> in;
                if (i + j == sum - i - j) continue;
                // mid path => indiffent
                change[min(i + j, sum - i - j)][in]++;
            }
        }
        sum = 0;
        for (auto c : change) sum += min(c[0], c[1]);
        cout << sum << "\n";
    }
    return 0;
}
