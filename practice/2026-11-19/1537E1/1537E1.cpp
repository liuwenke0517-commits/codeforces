
#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 1;
    string s;
    cin >> s;
    string ans;
    s = '@' + s;
    for (int i = 2; i <= n; i++) {
        int id = i % cnt == 0 ? cnt : i % cnt;
        if (s[i] == s[id]) continue;
        else if (s[i] > s[id]) {
            break;
        } else {
            cnt = i;
        }
    }
    ans = s.substr(1, cnt);
    while (ans.size() < m) {
        ans = ans + ans;
    }
    while (ans.size() > m) {
        ans.pop_back();
    }
    cout << ans << '\n';
}


signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
}
