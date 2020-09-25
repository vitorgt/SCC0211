#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n = 0;
unordered_map<int, set<string>> ans;
bool vis[20][20];

void visit(int ati, int atj, string a, vector<vector<char>>& m) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            int nxi = ati + i, nxj = atj + j;
            if (nxi >= 0 && nxi < n && nxj >= 0 && nxj < n) {
                if (m[nxi][nxj] > a.back() && !vis[nxi][nxj]) {
                    a += m[nxi][nxj];
                    vis[nxi][nxj] = 1;
                    if (a.size() > 2) ans[a.size()].insert(a);
                    visit(nxi, nxj, a, m);
                    vis[nxi][nxj] = 0;
                    a.pop_back();
                }
            }
        }
    }
}

int main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0;
    char in = 0;
    string a = "";
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<char>> m(n, vector<char>(n, 0));
        memset(vis, 0, sizeof(vis));
        ans.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> in;
                m[i][j] = in;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a = "";
                a += m[i][j];
                vis[i][j] = 1;
                visit(i, j, a, m);
                vis[i][j] = 0;
            }
        }
        n = n * n;
        for (int i = 3; i <= n; i++) {
            for (auto a : ans[i]) {
                cout << a << "\n";
            }
            ans[i].clear();
        }
        if (t > 0) cout << "\n";
    }
    return 0;
}
