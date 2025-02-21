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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    set<char> a = {'H', 'D', 'C', 'S'}, b = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    set<string> p;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!a.count(s[0]) || !b.count(s[1]) || p.count(s)) {
            cout << "No";
            return 0;
        }
        p.insert(s);
    }
    cout << "Yes";
}
