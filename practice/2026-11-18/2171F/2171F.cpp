#include<bits/stdc++.h>
#define int long long
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x) {
        p[x] = p[x] == x ? x : find(p[x]);
        return p[x];
    }
    void merge(int x, int y) {
        int X = find(x), Y = find(y);
        if (X == Y) return;
        p[X] = Y;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), L(n), R(n), loca(n);

    deque<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        loca[a[i]] = i;
        q.push_back(a[i]);
        L[i] = min(a[i], (i > 0 ? L[i - 1] : (int)1E18));
    }
    for (int i = n - 1; i >= 0; i--) {
        R[i] = max(a[i], (i < n - 1 ? R[i + 1] : (int)-1E18));
    }

    int ok = 0;
    DSU dsu(n);

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        int mx = i;
        while (q.size()) {
            auto x = q.back();
            q.pop_back();
            if (x == i) break;
            if (dsu.find(i) != dsu.find(x)) {
                ans.push_back({i + 1, x + 1});
            }
            dsu.merge(i, x);
            mx = max({mx, i, x});

        }
        if (mx > i) {

            q.push_back(mx);
        }
    }

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) ok++;
    }
    if (ok == 1) {
        cout << "YES" << '\n';
        for (auto &x : ans) cout << x.first << ' ' << x.second << '\n';
    } else {
        cout << "NO" << '\n';
    }

}


signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
