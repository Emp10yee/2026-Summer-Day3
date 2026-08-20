#include <bits/stdc++.h>
using namespace std;

int n;
int dist[20][20];
int dp[20][1 << 20];
vector<int> ord;

int dfs(int cur, int visited)
{
    if (cur == n)
    {
        return 0;
    }

    if (dp[cur][visited] != -1)
        return dp[cur][visited];

    dp[cur][visited] = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (visited & (1 << i))
            continue;

        dp[cur][visited] = min(dp[cur][visited], dfs(cur + 1, visited | (1 << i)) + dist[cur][i]);
    }
    return dp[cur][visited];
}

void find_path(int cur, int visited)
{
    if (cur == n)
        return;

    for (int i = 0; i < n; i++)
    {
        if (visited & (1 << i))
            continue;

        if (dp[cur][visited] == dfs(cur + 1, visited | (1 << i)) + dist[cur][i])
        {
            ord.push_back(i + 1);
            find_path(cur + 1, visited | (1 << i));
            break;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0) << '\n';

    find_path(0, 0);
    for (int k : ord)
        cout << k << ' ';
    cout << '\n';

    return 0;
}
