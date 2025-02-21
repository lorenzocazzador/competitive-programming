#include <bits/stdc++.h>
using namespace std;

bool f(int N, long long M, int V[], int L) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += V[i];
        if (i >= L)
            sum -= V[i - L];
        if (sum > M)
            return false;
    }
    return true;
}

int quadri(int N, long long M, int V[]) {
    int l = 0, r = N + 1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (f(N, M, V, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    int N;
    long long M;
    cin >> N >> M;
    int V[N];
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    cout << quadri(N, M, V) << "\n";
}
