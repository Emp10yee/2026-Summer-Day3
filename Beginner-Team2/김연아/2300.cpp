#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;

    long long min_diff = LLONG_MAX;
    long long ans_left = arr[left];
    long long ans_right = arr[right];

    while (left < right) {
        long long sum = arr[left] + arr[right];

        // 0과의 거리가 더 가까운 경우 갱신
        if (abs(sum) < min_diff) {
            min_diff = abs(sum);
            ans_left = arr[left];
            ans_right = arr[right];
        }

        // 합이 0이면 가장 최적이므로 탐색 종료
        if (sum == 0) {
            break;
        }

        // 합이 0보다 작으면 값을 키우기 위해 left를 증가
        if (sum < 0) {
            left++;
        }
        // 합이 0보다 크면 값을 줄이기 위해 right를 감소
        else {
            right--;
        }
    }

    cout << ans_left << " " << ans_right << "\n";

    return 0;
}