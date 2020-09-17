#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

const char aiw[10] = {'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
set<pair<int, int>> visLs;

bool visit(vector<vector<char>>& m, int ati, int atj, int ataiw) {
    if (ataiw == 10) return true;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            if (ati + i >= 0 && atj + j >= 0 && ati + i < m.size() &&
                atj + j < m[0].size()) {
                if (m[ati + i][atj + j] == aiw[ataiw]) {
                    if (aiw[ataiw] == 'L') {
                        auto at = make_pair(ati + i, atj + j);
                        if (visLs.count(at)) continue;
                        else {
                            visLs.insert(at);
                            if (visit(m, ati + i, atj + j, ataiw + 1)) {
                                return true;
                            }
                            visLs.erase(at);
                        }
                    } else {
                        if (visit(m, ati + i, atj + j, ataiw + 1)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool everyA(vector<vector<char>>& m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            if (m[i][j] == aiw[0]) {
                visLs.clear();
                if (visit(m, i, j, 1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, r = 0, c = 0;
    char in = 0;
    cin >> t;
    while (t--) {
        cin >> r >> c;
        vector<vector<char>> m(r, vector<char>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> in;
                m[i][j] = in;
            }
        }
        if (everyA(m)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
