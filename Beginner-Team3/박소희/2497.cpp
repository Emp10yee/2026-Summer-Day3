#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    int sum = 0;
    int a[100001];
    cin >> N >> K;
    
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    for (int i = 0; i < K; i++)
        sum += a[i];
    int best = sum;

    for (int i = K; i < N; i++){
        sum += a[i] - a[i-K];
        best = max(best, sum);
    }

    cout << best;

    return 0;
}