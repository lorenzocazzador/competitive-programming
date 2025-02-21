#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F(a,b,c) for(int a = b; a <= c; a++)
const int N = 5010;
int t[N],d[N];
ll pre[N],pre2[N];

void solve(){
    int n;
    cin>>n;
    F(i,1,n) cin>>t[i]>>d[i];
    vector<pair<int,int>> v;
    F(i,1,n) v.push_back({d[i],i});
    pre[0]=0;
    sort(v.begin(),v.end());
    vector<int> ans(n+1);
    F(i,1,n){
        pre[i]=pre[i-1]+t[v[i-1].second];
        if(d[v[i-1].second]<pre[i]) {cout<<"*\n";return;}
    }
    F(i,1,n) ans[i]=v[i-1].second;
    for (int i = 0; i < n; i++) {
        if (ass[i].cur == ans[i].cur || ans[i].left != ans[j].left) {
            ans[i]
        }
    }
    F(i,1,n){
        int pos,mi;
        pos=0;mi=n+1;
        pre2[i]=d[ans[i]]-pre[i];
        F(j,i+1,n){
            pre2[j]=min(pre2[j-1],d[ans[j]]-pre[j]);
            if(ans[j]<ans[i]&&t[ans[j]]<=pre2[j-1]){
                if(ans[j]<mi){
                    mi=ans[j];
                    pos=j;
                }
            }
        }
        cout << i << " " << mi << "\n";
        if(pos) {
            ans.erase(ans.begin()+pos);
            ans.insert(ans.begin()+i,mi);
            F(j,1,n) pre[j]=pre[j-1]+t[ans[j]];
        }
        // F(i,1,n) cout<<ans[i]<<" \n"[i==n];
    }
    F(i,1,n) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    solve();
}
