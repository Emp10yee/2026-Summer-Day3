#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int x = 0; x < 512; x++) {

        bool possible = true;

        for (int i = 0; i < n; i++) {

            bool found = false;

            for (int j = 0; j < m; j++) {

                int value = a[i] & b[j];

                if ((value | x) == x) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << x << '\n';
            return 0;
        }
    }

    return 0;
}