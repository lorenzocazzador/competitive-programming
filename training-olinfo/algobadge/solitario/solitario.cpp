#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

vector<vector<bool>> m;
int N, M, res, tmp, blank;

inline bool inside(int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; }

inline bool tris(int r, int c) {
    if (inside(r-2, c-2) && m[r-2][c-2] && m[r-1][c-1])
        return true;
    if (inside(r-2, c) && m[r-2][c] && m[r-1][c])
        return true;
    if (inside(r-2, c+2) && m[r-2][c+2] && m[r-1][c+1])
        return true;
    if (inside(r, c-2) && m[r][c-2] && m[r][c-1])
        return true;

    return false;
}

inline pii getNextCell(int r, int c) {
    if (c + 1 < M) {
        return {r, c + 1};
    } else {
        return {r + 1, 0};
    }
}

void solve(int r, int c) {
    if (!inside(r, c))
        return;

    if (blank > N * M - res || blank > N * M / 2)
        return;

    pii p = getNextCell(r, c);

    if (!tris(r, c)) {
        m[r][c] = true;
        tmp++;
        res = max(res, tmp);
        solve(p.F, p.S);
        m[r][c] = false;
        tmp--;
    }

    blank++;
    solve(p.F, p.S);
    blank--;

    return;
}

int gioca() {
    m.resize(N, vector<bool>(M, false));
    solve(0, 0);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> N >> M;
    cout << gioca() << "\n";
}
