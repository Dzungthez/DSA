#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int na; cin >> na;
    int *a = new int[na];
    for (int i = 0; i <na; i++) {
        cin >> a[i];
    }
    int nb; cin >> nb;
    int *b = new int[nb];
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
    int dp[na+1][nb+1];
    for (int i = 0; i <= na; i++) {
        for (int j = 0; j <= nb; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i <= na; i++) {
        for (int j = 0; j <= nb; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[na][nb];
    return 0;
}