#include <iostream>
#include <vector>
#include <climits>
#include <string.h>

using namespace std;

int N;

// 장소 간 이동 비용 (0이면 갈 수 없음)
int cost[19][19];

// dp[mask][last] = 회사(0번)에서 출발해서 mask에 포함된 장소들을 모두 방문하고
// 현재 last 장소에 있을 때까지의 최소 비용
int dp[1 << 19][19];

const int INF = INT_MAX / 2;

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

    // dp 초기화 (INF로 세팅해서 아직 못 온 상태 표시)
    for (int mask = 0; mask < full; mask++){
        for (int last = 0; last < N; last++){
            dp[mask][last] = INF;
        }
    }

    // 시작 상태: 0번(회사)만 방문한 상태
    dp[1][0] = 0;

    // 비트마스크 DP
    for (int mask = 1; mask < full; mask++){
        for (int last = 0; last < N; last++){
            // 아직 도달 못한 상태거나, mask에 last가 포함 안 되어 있으면 스킵
            if (!(mask & (1 << last))) continue;
            if (dp[mask][last] == INF) continue;

            for (int next = 0; next < N; next++){
                // 이미 방문한 장소면 스킵
                if (mask & (1 << next)) continue;
                // 갈 수 없는 경로면 스킵 (0번 장소로 가는 것 제외, 0은 회사라 별도 처리)
                if (cost[last][next] == 0) continue;

                int nextMask = mask | (1 << next);
                int nextCost = dp[mask][last] + cost[last][next];

                // 최소값 저장
                if (nextCost < dp[nextMask][next]){
                    dp[nextMask][next] = nextCost;
                }
            }
        }
    }

    // 모든 장소를 방문한 뒤, 다시 0번(회사)로 돌아오는 최소 비용 계산
    int full_mask = full - 1;
    int answer = INF;

    for (int last = 1; last < N; last++){
        // last에서 회사(0)로 돌아갈 수 없으면 스킵
        if (cost[last][0] == 0) continue;
        if (dp[full_mask][last] == INF) continue;

        int total = dp[full_mask][last] + cost[last][0];

        // 최소값 저장
        if (total < answer){
            answer = total;
        }
    }

    // N이 1인 경우(회사만 있는 경우) 예외 처리
    if (N == 1){
        answer = 0;
    }

    cout << answer << "\n";

    return 0;
}