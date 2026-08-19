#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    int temp[n];

    for (int i=0; i<n; i++) {
        cin >> temp[i];
    }

    int s[n-m+1] = {0};
    for (int i=0; i<m; i++) {
        s[0] += temp[i];
    }

    int num=s[0];

    for (int i=1; i<n-m+1; i++) {
        s[i] = s[i-1] - temp[i-1] + temp[i+m-1];
        if (num < s[i]) num = s[i];
    }

    cout << num;
}