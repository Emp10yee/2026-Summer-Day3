#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> answer(n - k + 1);

    answer[0] = 0;
    for (int i = 0; i < k; i++) {
        answer[0] += v[i];
    }
    for (int i = 1; i < n - k + 1; i++) {
        answer[i] = answer[i - 1] - v[i - 1] + v[i - 1 + k];
    }

    int max = answer[0];
    for (int i = 1; i < answer.size(); i++) {
        if (answer[i] >= max) max = answer[i];
    }

    cout << max;

    return 0;
}
