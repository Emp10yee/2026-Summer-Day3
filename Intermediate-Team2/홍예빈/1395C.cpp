// Day3 - 코드포스 1395C번 : Boboniu and Bit Operations
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    /*
        ai, bj < 2^9 이므로 가능한 답은 0 ~ 511
    */
    for (int mask = 0; mask < (1 << 9); ++mask) {
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            bool canChoose = false;

            for (int j = 0; j < m; ++j) {
                /*
                    (a[i] & b[j])의 비트 중
                    mask에 포함되지 않은 비트가 없어야 한다.
                */
                if (((a[i] & b[j]) | mask) == mask) {
                    canChoose = true;
                    break;
                }
            }

            /*
                현재 a[i]에 대해 가능한 b[j]가 없다면
                이 mask는 불가능하다.
            */
            if (!canChoose) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << mask << '\n';
            return 0;
        }
    }

    return 0;
}
