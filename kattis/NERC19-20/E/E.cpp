#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define maxn 200010
#define pii pair<int,int>
#define fi first
#define se second

int n,m,k;
vector<pii>v;
int fence[maxn];

int main(){
    #ifdef SO_IO
        ifstream cin("input.txt");
    #endif

    cin>>n>>m>>k;
    v.resize(m);
    for(int i=0;i<m;i++){
        cin>>v[i].fi;
        v[i].se = i+1;
    }

    sort(v.begin(),v.end(),greater<pii>());

    int i = 0,j = 0, lel = 0;
    int nn = n;
    while(n){
        if(!v[j].fi)j++;
        v[j].fi--;
        fence[i] = v[j].se;
        i += k+1;
        if(i >= nn){
            lel++;
            i = lel;
        }
        n--;
    }
    n = nn;

    if(fence[k-1] == fence[k]){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=0;i<n;i++)
        cout<<fence[i]<<" ";
    cout<<endl;
}
