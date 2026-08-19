#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int W, H; // W: 가로 길이(N), H: 세로 높이(M)

// dp[mask] : 이전 줄에서 넘어와서 현재 줄의 특정 칸들이 이미 채워진 상태(mask)일 때의 경우의 수
// ndp[mask] : 다음 줄로 넘어갈 때의 경우의 수 (재귀 처리 중 누적)
unsigned long long dp[1 << 11];
unsigned long long ndp[1 << 11];

int fullMask;
unsigned long long curVal; // 현재 처리 중인 dp[mask] 값 (재귀 함수에서 참조)

// col: 현재 처리 중인 칸의 열 번호
// state: 이번 줄에서 이미 채워진 칸 표시 (이전 줄의 수직 도미노 때문에)
// nextState: 다음 줄로 넘어갈 때 채워야 하는 칸 표시 (이번 줄에서 수직 도미노를 놓은 경우)
void fillRow(int col, int state, int nextState){
    // 한 줄을 다 처리했으면 결과를 다음 dp(ndp)에 누적
    if (col == W){
        ndp[nextState] += curVal;
        return;
    }

    // 이미 채워진 칸이면 그냥 다음 칸으로 이동
    if (state & (1 << col)){
        fillRow(col + 1, state, nextState);
        return;
    }

    // 경우 1: 수직 도미노 - 이번 칸을 채우고 다음 줄까지 이어짐
    fillRow(col + 1, state, nextState | (1 << col));

    // 경우 2: 수평 도미노 - 옆 칸(col+1)과 함께 채움
    // 옆 칸이 존재하고, 옆 칸이 이미 채워져 있지 않은 경우에만 가능
    if (col + 1 < W && !(state & (1 << (col + 1)))){
        fillRow(col + 2, state, nextState);
    }
}

int main(){
    ios::sync_with_stdio(false);

    cin >> W >> H;

    fullMask = 1 << W;

    // 초기 세팅: 맨 첫 줄 시작 전에는 "채워야 할 칸"이 없는 상태(mask=0)로 시작
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    // 한 줄씩 처리
    for (int row = 0; row < H; row++){
        // 다음 상태 배열 초기화
        memset(ndp, 0, sizeof(ndp));

        // 현재 가능한 모든 상태(mask)에 대해 처리
        for (int mask = 0; mask < fullMask; mask++){
            if (dp[mask] == 0) continue;

            curVal = dp[mask];
            fillRow(0, mask, 0);
        }

        // 다음 줄로 넘어가기 위해 dp 갱신
        memcpy(dp, ndp, sizeof(dp));
    }

    // 모든 줄을 다 채운 후, 남는 칸(다음 줄로 넘어가야 할 칸)이 없는 상태(mask=0)가 정답
    cout << dp[0] << "\n";

    return 0;
}