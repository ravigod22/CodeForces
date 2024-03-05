#include <bits/stdc++.h>
using namespace std;
const long long ite = 1e6;

void solve() {
    long long a, b;
    cin >> a >> b;
    long long max_e = max(a, b);
    for (long long i = 0; i <= ite; ++i) {
        long long tmp = a + b + ((i * (i + 1)) / 2);
        if (tmp % 2 == 0 && tmp >= 2 * max_e) {
            cout << i << "\n";
            break;
        }
    }
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
