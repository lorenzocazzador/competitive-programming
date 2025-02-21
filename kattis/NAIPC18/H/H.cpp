#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for(__typeof(b) i = a; i < (b); ++i)
#define per(i, a, b) for(__typeof(b) i = a; i >= (b); --i)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

// Check this: https://www.tomorrowtides.com/how-to-implement-a-dsu-treap-in-c.html

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(12);
  cout << fixed;
#ifdef _FILE_INPUT
  freopen("input.txt", "rt", stdin);
#endif
  /*
   *  Start coding here
   */

   int r, c, rp, cp;
   string rows_str, cols_str;
   cin >> rows_str >> cols_str;
   r = rows_str.size();
   c = cols_str.size();
   vector<int> rows(r), cols(c);
   rep(i, 0, r) rows[i] = rows_str[i] - '0';
   rep(i, 0, c) cols[i] = cols_str[i] - '0';
   rp = c % 2;
   cp = r % 2;

   vector<vector<int>> mat(r, vector<int>(c, 1));

   int wr = 0, wc = 0, i, j;
   rep(i, 0, r) if(rows[i] != rp) wr++;
   rep(i, 0, c) if(cols[i] != cp) wc++;
   // Different parity => no sol
   if((wr + wc) % 2 != 0){
     cout << "-1\n";
     return 0;
   }

   // rep(i, 0, r){
   //   rep(j, 0, c){
   //     cout << mat[i][j];
   //   }
   //   cout << endl;
   // }
   // cout << "Wrong rows: " << wr << ",\t Wrong cols: " << wc << endl;

   i = 0;
   while(wr > wc && i < r){
     if(rows[i] != rp){
       rows[i] ^= 1;
       mat[i][0] ^= 1;
       wr--;
     }
     i++;
   }
   j = 0;
   while(wc > wr && j < c){
     if(cols[j] != cp){
       cols[j] ^= 1;
       mat[0][j] ^= 1;
       wc--;
     }
     j++;
   }

   // rep(i, 0, r){
   //   rep(j, 0, c){
   //     cout << mat[i][j];
   //   }
   //   cout << endl;
   // }
   // cout << "Wrong rows: " << wr << ",\t Wrong cols: " << wc << endl;

   i = 0;
   j = 0;
   while(wc > 0 && wr > 0){
     while(rows[i] == rp) i++;
     while(cols[j] == cp) j++;
     rows[i] ^= 1;
     cols[j] ^= 1;
     mat[i][j] ^= 1;
     wc--;
     wr--;
   }
   // rep(i, 0, r) rep(j, 0, c) if(rows[i] != rp && cols[j] != cp){
   //   rows[i] ^= 1;
   //   cols[j] ^= 1;
   //   mat[i][j] ^= 1;
   // }

   rep(i, 0, r){
     rep(j, 0, c){
       cout << mat[i][j];
     }
     cout << endl;
   }
   // cout << "Wrong rows: " << wr << ",\t Wrong cols: " << wc << endl;

  /*
   *  End coding here
   */
#ifdef _FILE_INPUT
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
