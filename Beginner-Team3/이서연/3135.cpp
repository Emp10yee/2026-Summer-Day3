#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> S(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        long long x;
        cin >> x;
        S[i] = S[i - 1] + x;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int s, e;
        cin >> s >> e;

        cout << S[e] - S[s - 1] << '\n';
    }

    return 0;
}