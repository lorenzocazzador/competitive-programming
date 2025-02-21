#include <bits/stdc++.h>
using namespace std;

int rr, cc, res, blank, init_x, tmp_res, rem_x;
bool b[10][10], can_put_x[10][10];

inline bool inside(int r, int c) {
    return r >= 0 && r < rr && c >= 0 && c < cc;
}

inline pair<bool,int> tris(int r, int c) {
    bool ans = false; int cnt = 0;

    if (inside(r-2, c-2) && b[r-2][c-2] && b[r-1][c-1])
        ans |= true;
    if (inside(r-2, c) && b[r-2][c] && b[r-1][c])
        ans |= true;
    if (inside(r-2, c+2) && b[r-2][c+2] && b[r-1][c+1])
        ans |= true;
    if (inside(r, c-2) && b[r][c-2] && b[r][c-1])
        ans |= true;

    if (inside(r+2, c+2) && b[r+2][c+2] && b[r+1][c+1]) {
        ans |= true;
        cnt += can_put_x[r+1][c];
    }
    if (inside(r+2, c) && b[r+2][c] && b[r+1][c])
        ans |= true;
    if (inside(r+2, c-2) && b[r+2][c-2] && b[r+1][c-1])
        ans |= true;
    if (inside(r, c+2) && b[r][c+2] && b[r][c+1])
        ans |= true;

    if (inside(r-1, c) && b[r-1][c] && inside(r+1,c) && b[r+1][c]) {
        ans |= true;
        cnt += can_put_x[r+1][c];
    }
    if (inside(r, c-1) && b[r][c-1] && inside(r,c+1) && b[r][c+1]) {
        ans |= true;
        cnt += can_put_x[r][c+1];
    }
    if (inside(r-1, c-1) && b[r-1][c-1] && inside(r+1,c+1) && b[r+1][c+1])  {
        ans |= true;
        cnt += can_put_x[r+1][c+1];
    }
    if (inside(r+1, c-1) && b[r+1][c-1] && inside(r-1,c+1) && b[r-1][c+1]) {
        ans |= true;
        cnt += can_put_x[r+1][c-1];
    }

    return {ans, cnt};
}


void solve(int &r, int &c) {
    if (r == rr || rem_x == 0) {
        res = max(res, tmp_res);
        return;
    }
    if (rr * cc - r * c - c <= res - tmp_res) {
        return;
    }
    if (blank >= rr * cc - res - init_x || blank > rr * cc / 2) {
        return;
    }
    if (tmp_res + rem_x <= res) {
        return;
    }

    int nc = (c + 1 < cc ? c + 1 : 0), nr = (c + 1 < cc ? r : r + 1);
    rem_x -= can_put_x[r][c];
    auto [can_tris, tmp] = tris(r, c);
    if (can_tris && can_put_x[r][c]) {
        rem_x -= tmp;
        b[r][c] = 1;
        tmp_res++;
        solve(nr, nc);
        rem_x += tmp;
        tmp_res--;
        b[r][c] = 0;
    }
    blank += !b[r][c];
    solve(nr, nc);
    blank -= !b[r][c];
    rem_x += can_put_x[r][c];
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> rr >> cc;
    for (int i = 0; i < rr; i++) {
        for (int j = 0; j < cc; j++) {
            cin >> b[i][j];
            init_x += b[i][j];
        }
    }
    for (int i = 0; i < rr; i++) {
        for (int j = 0; j < cc; j++) {
            if (!b[i][j] && !tris(i, j).first) {
                can_put_x[i][j] = 1;
                rem_x++;
            }
        }
    }
    int a = 0, b = 0;
    solve(a, b);
    cout << res << "\n";
}
