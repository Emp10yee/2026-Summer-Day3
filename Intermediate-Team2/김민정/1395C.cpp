#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    int a[205], b[205];
 
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    for (int i = 0; i < m; i++)
        cin >> b[i];
 
    for (int ans = 0; ans < 512; ans++) {
        bool ok = true;
 
        for (int i = 0; i < n; i++) {
            bool can = false;
 
            for (int j = 0; j < m; j++) {
                int x = a[i] & b[j];
 
                if ((x | ans) == ans) {
                    can = true;
                    break;
                }
            }
 
            if (!can) {
                ok = false;
                break;
            }
        }
 
        if (ok) {
            cout << ans << '\n';
            break;
        }
    }
 
    return 0;
}
