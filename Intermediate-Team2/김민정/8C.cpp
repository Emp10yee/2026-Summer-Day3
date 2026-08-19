#include <bits/stdc++.h>
using namespace std;
 
int n, sx, sy;
int x[25], y[25];
int d[25];
int fullMask;
 
vector<int> dp;
 
int dist(int a, int b) {
    int xx = x[a] - x[b];
    int yy = y[a] - y[b];
    return xx * xx + yy * yy;
}
 
int go(int mask) {
    if (mask == fullMask) return 0;
 
    if (dp[mask] != -1)
        return dp[mask];
 
    int a = 0;
 
    while (mask & (1 << a))
        a++;
 
    int next = mask | (1 << a);
 
    int ans = go(next) + d[a] * 2;
 
    for (int b = a + 1; b < n; b++) {
        if (mask & (1 << b))
            continue;
 
        int nmask = next | (1 << b);
 
        int temp = go(nmask);
        temp += d[a];
        temp += dist(a, b);
        temp += d[b];
 
        ans = min(ans, temp);
    }
 
    return dp[mask] = ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> sx >> sy;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
 
        int xx = x[i] - sx;
        int yy = y[i] - sy;
 
        d[i] = xx * xx + yy * yy;
    }
 
    fullMask = (1 << n) - 1;
 
    dp.assign(1 << n, -1);
 
    cout << go(0) << '\n';
 
    int mask = 0;
 
    cout << 0 << ' ';
 
    while (mask != fullMask) {
        int a = 0;
 
        while (mask & (1 << a))
            a++;
 
        int next = mask | (1 << a);
 
        if (dp[mask] == go(next) + d[a] * 2) {
            cout << a + 1 << ' ';
            cout << 0 << ' ';
 
            mask = next;
        }
        else {
            for (int b = a + 1; b < n; b++) {
                if (mask & (1 << b))
                    continue;
 
                int nmask = next | (1 << b);
 
                int temp = go(nmask);
                temp += d[a];
                temp += dist(a, b);
                temp += d[b];
 
                if (dp[mask] == temp) {
                    cout << a + 1 << ' ';
                    cout << b + 1 << ' ';
                    cout << 0 << ' ';
 
                    mask = nmask;
                    break;
                }
            }
        }
    }
 
    cout << '\n';
 
    return 0;
}
