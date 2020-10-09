#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, a = 0, b = 0, ans = 0;
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        ans = max(ans, min(a / i, b / (n - i)));
    }
    cout << ans << "\n";
    return 0;
}
