#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c = 0, L = 0, m = 0, car = 0, i = 0;
    string buf = "";
    cin >> c;
    while (c--) {
        cin >> L >> m;
        L *= 100;
        queue<int> l, r;
        while (m--) {
            cin >> car >> buf;
            if (buf[0] == 'l')
                l.push(car);
            else
                r.push(car);
        }
        for (i = 0; !l.empty() || !r.empty(); i++) {
            car = 0;
            if (i % 2) {  // ferry on right
                while (!r.empty() && car + r.front() <= L) {
                    car += r.front();
                    r.pop();
                }
            } else {  // ferry on left
                while (!l.empty() && car + l.front() <= L) {
                    car += l.front();
                    l.pop();
                }
            }
        }
        cout << i << endl;
    }
    return 0;
}
