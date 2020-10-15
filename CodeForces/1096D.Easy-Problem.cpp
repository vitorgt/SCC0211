#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0;
    string word = "", hard = "hard";
    cin >> n;
    cin >> word;
    vector<int> w(n + 1, 0);
    vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        dp[i][0] = dp[i - 1][0];
        if (word[i - 1] == 'h') dp[i][0] += w[i];
        for (int j = 1; j < 4; j++) {
            dp[i][j] = dp[i - 1][j];
            if (word[i - 1] == hard[j])
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j] + w[i]);
        }
    }
    cout << dp[n][3] << "\n";
    return 0;
}
