#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        v.push_back({S, E});
    }
    sort(v.begin(), v.end());

    int cur_s = v[0].first;
    int cur_e = v[0].second;
    int max_stay = 0;
    int max_empty = 0;

    for (int i = 1; i < N; i++) {
        if (v[i].first <= cur_e) {
            cur_e = max(cur_e, v[i].second);
        } else {
            max_stay = max(max_stay, cur_e - cur_s);
            max_empty = max(max_empty, v[i].first - cur_e);

            cur_s = v[i].first;
            cur_e = v[i].second;
        }
    }
    max_stay = max(max_stay, cur_e - cur_s);

    cout << max_stay << " " << max_empty;
}