#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

int H, W, N, h, w;
vi C;
vector<vi> A;

int get_ans() {
    int ans = 0;
    for (int & x : C) ans += (x != 0);
    return ans;
}

void delete_rect(int r, int c) {
    for (int i = r; i < r + h; i++) {
        for (int j = c; j < c + w; j++) {
            C[A[i][j]]--;
        }
    }
}

void add_rect(int r, int c) {
    for (int i = r; i < r + h; i++) {
        for (int j = c; j < c + w; j++) {
            C[A[i][j]]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W >> N >> h >> w;
    C.resize(N + 1, 0);
    A.resize(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            C[A[i][j]]++;
        }
    }
    for (int i = 0; i <= H - h; i++) {
        for (int j = 0; j <= W - w; j++) {
            delete_rect(i, j);
            cout << get_ans() << " ";
            add_rect(i, j);
        }
        cout << "\n";
    }
}
