#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, m = 0, c = 0, i = 0, j = 0, hit = 0;
    char d = 0;
    cin >> n >> m >> c;
    vector<vector<char>> cross(n, vector<char>(m, '.'));
    for (int k = 0; k < c; k++) {
        cin >> i >> j >> d;
        cross[i][j] = d;
    }
    return 0;
}
