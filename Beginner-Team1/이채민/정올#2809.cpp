#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long N;
    cin >> N;

    vector<long long> divisor;

    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            divisor.push_back(i);

            if (i != N / i) {
                divisor.push_back(N / i);
            }
        }
    }

    sort(divisor.begin(), divisor.end());

    for (int i = 0; i<divisor.size(); i++) {
        cout << divisor[i] << " ";
    }

    return 0;
}