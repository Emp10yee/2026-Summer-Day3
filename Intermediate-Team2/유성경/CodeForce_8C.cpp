// CodeForce 8C. Looking for Order
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int x[24];
int y[24];
int distS[24];
int distO[24][24];
int dp[1 << 24];
int parent[1 << 24];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int xs, ys;
    cin >> xs >> ys;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
        distS[i] = (x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            distO[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + 
                          (y[i] - y[j]) * (y[i] - y[j]);
        }
    }

    int maxM = 1 << n;
    for (int i = 0; i < maxM; ++i)
    {
        dp[i] = 2e9;
    }

    dp[0] = 0;

    for (int mask = 0; mask < maxM - 1; ++mask)
    {
        if (dp[mask] == 2e9)
        {
            continue;
        }

        int i = 0;
        for (int bit = 0; bit < n; ++bit)
        {
            if (!(mask & (1 << bit)))
            {
                i = bit;
                break;
            }
        }

        int next1 = mask | (1 << i);
        int cost1 = dp[mask] + 2 * distS[i];

        if (dp[next1] > cost1)
        {
            dp[next1] = cost1;
            parent[next1] = mask;
        }

        for (int j = i + 1; j < n; ++j)
        {
            if (!(mask & (1 << j)))
            {
                int next2 = mask | (1 << i) | (1 << j);
                int cost2 = dp[mask] + distS[i] + distO[i][j] + distS[j];

                if (dp[next2] > cost2)
                {
                    dp[next2] = cost2;
                    parent[next2] = mask;
                }
            }
        }
    }

    cout << dp[maxM - 1] << "\n";
    cout << "0 ";

    int curr = maxM - 1;

    while (curr > 0)
    {
        int prev = parent[curr];
        int diff = curr ^ prev;

        for (int i = 0; i < n; ++i)
        {
            if (diff & (1 << i))
            {
                cout << i + 1 << " ";
            }
        }

        cout << "0 ";
        curr = prev;
    }

    cout << "\n";

    return 0;
}
#endif