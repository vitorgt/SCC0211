#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, k = 0, t = 0, a = 0, b = 0;
    int A = 0, B = 0;  // accumutalors
    long long sum = 0;
    cin >> n >> k;
    priority_queue<int> booksAB, booksA, booksB;
    while (n--) {
        cin >> t >> a >> b;
        A += a;
        B += b;
        if (a && b) booksAB.push(-t);
        else if (a) booksA.push(-t);
        else if (b) booksB.push(-t);
    }
    if (A < k || B < k) {
        cout << -1 << "\n";
        return 0;
    }
    while (!booksA.empty() && !booksB.empty()) {
        booksAB.push(booksA.top() + booksB.top());
        booksA.pop();
        booksB.pop();
    }
    for (A = 0; A < k && !booksAB.empty(); A++) {
        sum -= booksAB.top();
        booksAB.pop();
    }
    cout << sum << "\n";
    return 0;
}
