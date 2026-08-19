#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;

    long long ans1 = arr[left];
    long long ans2 = arr[right];
    long long best = llabs(ans1 + ans2);

    while (left < right) {
        long long sum = arr[left] + arr[right];

        if (llabs(sum) < best) {
            best = llabs(sum);
            ans1 = arr[left];
            ans2 = arr[right];
        }

        if (sum < 0) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
}