#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int bfs(string s, string t, unordered_map<string, bool>& f) {
    int aux = 0;
    queue<pair<string, int>> q;
    q.push(make_pair(s, 1));
    while (!q.empty()) {
        auto at = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            string to = at.first;
            aux = to[i % 4] - '0';
            aux += (i < 4) ? 1 : -1;
            aux = (aux + 10) % 10;
            to[i % 4] = aux + '0';
            if (f[to]) continue;
            if (to == t) return at.second;
            f[to] = 1;
            q.push(make_pair(to, at.second + 1));
        }
    }
    return -1;
}

int main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, fs = 0, in = 0, i = 0;
    string s = "", t = "", temp = "";
    unordered_map<string, bool> f;
    cin >> n;
    while (n--) {
        s = "", t = "";
        f.clear();
        for (i = 4; i--;) {
            cin >> in;
            s += in + '0';
        }
        for (i = 4; i--;) {
            cin >> in;
            t += in + '0';
        }
        cin >> fs;
        while (fs--) {
            temp = "";
            for (i = 4; i--;) {
                cin >> in;
                temp += in + '0';
            }
            f[temp] = 1;
        }
        if (s == t) {
            cout << 0 << "\n";
            continue;
        }
        if (f[t]) {
            cout << -1 << "\n";
            continue;
        }
        cout << bfs(s, t, f) << "\n";
    }
    return 0;
}
