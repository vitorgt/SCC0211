#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, m = 0, maxi = 0;
    vector<int> queries;
    vector<int> c{1, 5, 10, 25, 50};
    while (cin >> n) {
        queries.push_back(n);
        maxi = max(maxi, n);
    }
    vector<unsigned long long> ways(maxi + 1, 0);
    ways[0] = 1;
    for (int cc = 0; cc < 5; cc++) {
        for (int i = c[cc]; i <= maxi; i++) {
            ways[i] += ways[i - c[cc]];
        }
    }
    for (int q : queries) {
        if (ways[q] == 1) cout << "There is only 1 way";
        else cout << "There are " << ways[q] << " ways";
        cout << " to produce " << q << " cents change.\n";
    }
    return 0;
}
