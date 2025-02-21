#include <bits/stdc++.h>
using namespace std;

double scosse(int N) {
    double sum = (N - 1) * N / 2;
    double sum2 = (sum + 1) * sum / 2;
    return sum2 / (sum + 1);
}

int main() {
    int N;
    cin >> N;
    cout << setprecision(6) << scosse(N) << "\n";
}
