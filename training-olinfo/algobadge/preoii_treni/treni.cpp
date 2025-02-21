#include <bits/stdc++.h>
using namespace std;

int tempo_massimo(int N, int A[], int B[]) {
    vector<long long> dp(N + 1, 0);
    dp[0] = 0;
    dp[1] = max(A[0], B[0]);
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + A[i-1];
        if (i > 1)
            dp[i] = max(dp[i], dp[i-2] + B[i-1]);
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    int A[N], B[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    cout << tempo_massimo(N, A, B) << "\n";
}
