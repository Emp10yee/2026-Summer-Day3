#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        int a[5][105];
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
 
        int all = 1 << n;
 
        vector<int> f(all, -1000000000);
        f[0] = 0;
 
        for (int j = 0; j < m; j++) {
            vector<int> best(all, 0);
 
            for (int r = 0; r < n; r++) {
                for (int mask = 0; mask < all; mask++) {
                    int sum = 0;
 
                    for (int i = 0; i < n; i++) {
                        if (mask & (1 << i)) {
                            sum += a[(i + r) % n][j];
                        }
                    }
 
                    best[mask] = max(best[mask], sum);
                }
            }
 
            vector<int> nf(all, -1000000000);
 
            for (int mask = 0; mask < all; mask++) {
                int sub = mask;
 
                while (1) {
                    nf[mask] = max(nf[mask],
                                   f[mask ^ sub] + best[sub]);
 
                    if (sub == 0)
                        break;
 
                    sub = (sub - 1) & mask;
                }
            }
 
            f = nf;
        }
 
        cout << f[all - 1] << '\n';
    }
 
    return 0;
}
