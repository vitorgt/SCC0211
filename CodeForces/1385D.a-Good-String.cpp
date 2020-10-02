#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int changeCount(string s, char c) {
    if (s.size() == 1) return s[0] != c;
    int mid = s.size() / 2;
    string a = s.substr(0, mid);
    string b = s.substr(mid);
    int ccl = changeCount(a, c + 1);
    int ccr = changeCount(b, c + 1);
    ccl += mid - count(b.begin(), b.end(), c);
    ccr += mid - count(a.begin(), a.end(), c);
    return min(ccl, ccr);
}

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0;
    string buffer = "";
    cin >> t;
    while (t--) {
        cin >> n >> buffer;
        cout << changeCount(buffer, 'a') << "\n";
    }
    return 0;
}
