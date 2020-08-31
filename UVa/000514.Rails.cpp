#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, c = 1;
    while (cin >> n && n != 0) {
        while (cin >> c && c != 0) {
            stack<int> marshaling;
            queue<int> throwing;
            throwing.push(c);
            for (int i = 1; i < n && cin >> c && c != 0; i++) {
                throwing.push(c);
            }
            for (int i = 1; i <= n; i++) {
                marshaling.push(i);
                while (!marshaling.empty() &&
                       marshaling.top() == throwing.front()) {
                    throwing.pop();
                    marshaling.pop();
                }
            }
            if (marshaling.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        cout << endl;
    }
    return 0;
}
