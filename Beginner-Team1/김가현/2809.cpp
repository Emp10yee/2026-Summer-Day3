#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    int sq;
    int arr[10000], cnt=0;

    cin >> N;
    sq = (int)sqrt(N);
    for (int i=1; i<=sq; i++) {
        if (N%i==0) {
            arr[cnt++] = i;
            if (N/i != i) arr[cnt++] = N/i;
        }
    }
    sort(arr, arr + cnt);

    for (int i = 0; i < cnt; i++) {
        cout << arr[i] << " ";
    }
}