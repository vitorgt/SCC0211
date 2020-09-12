#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, in = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<bool> seen(n + 1, false);
        n *= 2;
        while (n--) {
            cin >> in;
            if (!seen[in]) {
                cout << in << " ";
                seen[in] = true;
            }
        }
        cout << "\n";
    }
    return 0;
}
