#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int nums[n];

    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    long long s[n+1] = {0};
    s[1] = nums[0];
    
    for (int i=2; i<n+1; i++) {
        s[i] = s[i-1]+nums[i-1];
    }

    int m,a,b;
    cin >> m;

    for (int i=0; i<m; i++) {
        cin >> a >> b;
        cout << s[b]-s[a-1] << '\n';
    }

}