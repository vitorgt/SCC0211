#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cout << fixed << setprecision(2);

    int n = 0, k = 0, m = 0, val = 0;
    long long sum = 0;
    char c = 0;
    string buffer = "";
    unordered_map<char, int> mp;
    cin >> n;
    while (n--) {
        cin >> k;
        while (k--) {
            cin >> c >> val;
            mp[c] = val;
        }
        cin >> m;
        getline(cin, buffer);
        while (m--) {
            getline(cin, buffer);
            for (char c : buffer) {
                sum += mp[c];
            }
        }
        cout << sum / 100.0 << "$\n";
        mp.clear();
        sum = 0;
    }
    return 0;
}
