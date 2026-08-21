#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> arr(N);

    for (int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = 1;

    int start = arr[left].first;
    int end = arr[left].second;

    int max_use = 0;
    int max_empty = 0;

    while (right < N) {
        if (arr[right].first <= end) {
            end = max(end, arr[right].second);
            right++;
        }

        else {
            max_use = max(max_use, end-start);
            max_empty = max(max_empty, arr[right].first-end);

            left = right;

            start = arr[left].first;
            end = arr[left].second;

            right++;
        }
    }

    max_use = max(max_use, end-start);

    cout << max_use << " " << max_empty;
    return 0;
}