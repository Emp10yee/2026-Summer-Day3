#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL); //입출력 속도 향상
    cout.tie(NULL); //입출력 속도 향상 

    int n;
    cin >> n;

    vector<int> v(n + 1);
    vector<long long> prefix_sum(n + 1, 0); // (size, value)

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    int q, s, e;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s >> e;
        cout << prefix_sum[e] - prefix_sum[s - 1] << '\n';
    }

    return 0;
}
