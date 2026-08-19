#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long a[100000];
long long X = 4000000001LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    sort(a, a+N);
    
    int l = 0, r = N-1;
    long long bestL, bestR;

    while (l < r) {
        long long sum = a[l] + a[r];

        if (abs(sum) < abs(X)){
            X = sum;
            bestL = a[l]; bestR = a[r];
        }
        if (sum == 0) {
            cout << a[l] << ' ' << a[r] << '\n';
            return 0;
        }
        else if (sum < 0) {
            l++;
        }
        else r--;
    }

    cout << bestL << ' ' << bestR << '\n';

    return 0;
}