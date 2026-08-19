#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // 시작 시간 기준 정렬
    sort(v.begin(), v.end());

    // 지금 시간 구간
    int curS = v[0].first;
    int curE = v[0].second;

    // 구해야 하는 것 두 개
    int maxOccupied = 0;
    int maxEmpty = 0;

    // 다음 것부터.
    for (int i = 1; i < n; i++) {
        int nextS = v[i].first;
        int nextE = v[i].second;

        // 현재 구간과 겹치거나 이어지는 경우 끝 구간을 다음 걸로 바꿈
        if (nextS <= curE) {
            curE = max(curE, nextE);
        }
        // 현재 구간과 떨어져 있는 경우
        else {
            // 현재 구간의 길이
            maxOccupied = max(maxOccupied, curE - curS);

            // 현재 구간과 다음 구간 사이의 빈 시간
            maxEmpty = max(maxEmpty, nextS - curE);

            // 현재 구간을 다음 구간으로 변경
            curS = nextS;
            curE = nextE;
        }
    }

    // 마지막 구간 처리
    maxOccupied = max(maxOccupied, curE - curS);

    cout << maxOccupied << ' ' << maxEmpty << '\n';

    return 0;
}