#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5 + 5;
vector<pair<int,int>> segments;

bool f(int x, vector<int>& a) {
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = (a[i] <= x && 0 < a[i] ? 1 : 0) + prefix[i - 1];
    }
    for (int i = 0; i < m; ++i) {
        int l = segments[i].first;
        int r = segments[i].second;
        int longitud = ((r - l + 1) / 2) + 1;
        if (prefix[r] - prefix[l - 1] >= longitud) {
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        segments.emplace_back(l, r);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int pos;
        cin >> pos;
        a[pos] = i;
    }
    int lo = 1;
    int hi = q;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid, a)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    int result = (f(lo, a) ? lo : -1);
    cout << result << "\n";
    segments.clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}

