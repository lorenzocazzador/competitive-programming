#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
string S;

void inizia(int N, int M) {
    v.clear();
    v.resize(M);
    for (int i = 0; i < N; i++) {
        v[0].push_back(S[i]);
    }
}

void sposta(int a, int b) {
    int x = v[a].back();
    v[a].pop_back();
    v[b].push_back(x);
}

char controlla(int a, int i) {
    if (i < (int)v[a].size())
        return v[a][i];
    else
        return -1;
}

int main() {
    // Uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N, M, Q;
        cin >> N >> M >> Q >> S;

        inizia(N, M);

        for (int i = 0; i < Q; i++) {
            char t;
            int a, b;
            cin >> t >> a >> b;
            if (t == 's') {
                sposta(a, b);
            } else {
                cout << controlla(a, b);
            }
        }
        cout << "\n";
    }

    return 0;
}
