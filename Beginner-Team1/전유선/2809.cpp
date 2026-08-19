#include <iostream>
#include <set>

using namespace std;

int main() {
    // 입출력 속도 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 1부터 n까지 다 돌렸더니 런타임 나서 set으로 바꾸고 한 번에...
    set<int> divisors;

    // i * i <= n 로 제곱근까지만 탐색해야 시간 초과 안 남.
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    for (int d : divisors) {
        cout << d << " ";
    }

    return 0;
}