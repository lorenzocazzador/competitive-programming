#include <bits/stdc++.h>
using namespace std;

vector<string> res;

string get_opposite(string s) {
    string t = "";
    for (char c : s) {
        t += (c == 'B' ? 'W' : 'B');
    }
    return t;
}

void reverse(string s, int k) {
    if (k == 0) {
        res.push_back(s);
        return;
    }
    string t = "B";
    for (char c : s) {
        if (c == 'B') {
            t += t.back();
        } else {
            t += (t.back() == 'B' ? 'W' : 'B');
        }
    }
    if (t.back() == t.front()) {
        t.pop_back();
        reverse(t, k - 1);
        reverse(get_opposite(t), k - 1);
    }
    return;
}

bool is_same_string(string s, string t) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == t[0]) {
            int j = 0;
            while (j < (int)t.size() && s[(i + j) % s.size()] == t[j]) {
                j++;
            }
            if (j == (int)t.size())
                return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string a = s, b = "";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] == a[(j + 1) % n]) {
                b += "B";
            } else {
                b += "W";
            }
        }
        a = b;
        b = "";
    }
    reverse(a, k);
    vector<bool> valid(res.size(), true);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = i + 1; j < (int)res.size(); j++) {
            if (is_same_string(res[i], res[j])) {
                valid[j] = false;
            }
        }
    }
    int ans = 0;
    for (bool x : valid)
        ans += x;
    cout << ans << "\n";
}
