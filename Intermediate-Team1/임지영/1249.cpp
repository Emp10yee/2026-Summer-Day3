#include <iostream>
#include <vector>
#include <climits>
#include <string.h>

using namespace std;

int N;

// 비용 표, dp 배열, 경로 복원용 배열
int cost[20][20];
int dp[1 << 20];
int choice[1 << 20];

int main(){
    ios::sync_with_stdio(false);

    cin >> N;

    // 비용 입력
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> cost[i][j];
        }
    }

    int full = 1 << N;

    // dp 초기화 (INT_MAX로 세팅해서 아직 못 온 상태 표시)
    for (int mask = 0; mask < full; mask++){
        dp[mask] = INT_MAX;
        choice[mask] = -1;
    }
    dp[0] = 0;

    // 비트마스크 DP
    for (int mask = 0; mask < full; mask++){
        // 아직 도달 못한 상태는 건너뜀
        if (dp[mask] == INT_MAX) continue;

        // 현재까지 배정된 빌딩 개수 = 다음에 배정할 빌딩 번호
        int building = __builtin_popcount(mask);
        if (building == N) continue;

        for (int place = 0; place < N; place++){
            // 이미 사용된 장소면 스킵
            if (mask & (1 << place)) continue;

            int nextMask = mask | (1 << place);
            int nextCost = dp[mask] + cost[building][place];

            // 최소값 저장 & 경로 기록
            if (nextCost < dp[nextMask]){
                dp[nextMask] = nextCost;
                choice[nextMask] = place;
            }
        }
    }

    // 경로 복원: 마지막 상태부터 거꾸로 추적
    vector<int> assign(N);
    int mask = full - 1;
    for (int i = N - 1; i >= 0; i--){
        int place = choice[mask];
        assign[i] = place;
        mask ^= (1 << place);
    }

    // 출력
    cout << dp[full - 1] << "\n";
    for (int i = 0; i < N; i++){
        cout << assign[i] + 1;
        if (i != N - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}