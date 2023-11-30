#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int v, e;
map<pi, int> mp;
int cnt;
void inp() {
    cin >> v >> e; // v dinh, e canh
    while(e--) {
        int a, b; cin >> a >> b;
        pi tmp = make_pair(a, b);
        pi tmp2 = make_pair(b, a);
        if (mp[tmp]++ || mp[tmp2]++) cnt++;
    }
}

int main() { 
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    inp();
    cout << cnt;
    
    return 0;
}