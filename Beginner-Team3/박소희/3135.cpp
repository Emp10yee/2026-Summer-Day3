#include <iostream>
using namespace std;

int N, Q, a, b;
long long A[1000001];
long long S[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    S[0] = 0;
    
    for (int i = 1; i <= N; i++){
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }
       
    
    cin >> Q;
    for (int i = 0; i < Q; i++){
        cin >> a >> b;
        cout << S[b] - S[a-1] << '\n';
    }

    return 0;
}