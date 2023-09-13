#include <bits/stdc++.h>

using namespace std;

int combinatorics(int n) {
    return (n*(n-1))/2;
}

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    int *a = new int[n];
    unordered_map <int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int sum = 0;
    for (auto x : mp) {
        if (x.second > 1) {
            sum += combinatorics(x.second);
        }
    }
    cout << sum;
    delete a;
    return 0;
}