#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cout << fixed << setprecision(6);

    int k = 0, n = 0, m = 0, s = 0;
    int K = 0, N = 0, M = 0;
    double sum = 0;
    cin >> k;
    K = k;
    while (k--) {
        cout << "Case " << K - k << ":";
        cin >> n;
        N = n;
        unordered_map<int, int> sm;
        unordered_set<int> uniques;
        vector<unordered_set<int>> ms(n);
        while (n--) {
            cin >> m;
            while (m--) {
                cin >> s;
                ms[n].insert(s);
            }
            for (auto it = ms[n].begin(); it != ms[n].end();
                 it = next(it)) {
                sm[*it]++;
            }
        }
        for (auto it = sm.begin(); it != sm.end(); it = next(it)) {
            if (it->second == 1) {
                uniques.insert(it->first);
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            sum = 0;
            for (auto it = uniques.begin(); it != uniques.end();
                 it = next(it)) {
                sum += ms[i].count(*it);
            }
            cout << " " << (sum / uniques.size()) * 100 << "%";
        }
        cout << "\n";
    }
    return 0;
}
