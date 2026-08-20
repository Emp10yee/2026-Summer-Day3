// CodeForce 1395C. Boboniu and Bit Operations
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    for (int ans = 0; ans < 512; ++ans)
    {
        bool possible = true;

        for (int i = 0; i < n; ++i)
        {
            bool found = false;

            for (int j = 0; j < m; ++j)
            {
                if (((a[i] & b[j]) | ans) == ans)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << ans << "\n";
            break;
        }
    }

    return 0;
}
#endif
