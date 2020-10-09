#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

bool eqs(const char *a, const char *b, int len) {
    // if (a == b) return true;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            break;
        } else if (i == len - 1) {
            return true;
        }
    }
    int mid = len / 2;
    if (len % 2 != 0) return false;
    // string a1 = a.substr(0, mid);
    // string a2 = a.substr(mid);
    // string b1 = b.substr(0, mid);
    // string b2 = b.substr(mid);
    return ((eqs(a, b, mid) && eqs(a + mid, b + mid, mid)) ||
            (eqs(a, b + mid, mid) && eqs(a + mid, b, mid)));
}

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string a = "", b = "";
    cin >> a >> b;
    if (a == "" || b == "" || a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }
    const char *ca = a.c_str(), *cb = b.c_str();
    if (eqs(ca, cb, a.size())) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
