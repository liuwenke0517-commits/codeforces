#include <bits/stdc++.h>
using namespace std;

string canon(const string& s) {
    if (s.size() % 2 == 1) return s;
    int h = s.size() / 2;
    string l = canon(s.substr(0, h));
    string r = canon(s.substr(h));
    if (l > r) swap(l, r);
    return l + r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << (canon(a) == canon(b) ? "YES" : "NO") << "\n";
    return 0;
}
