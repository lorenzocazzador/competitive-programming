#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5010;
const int MAXK = 1000010;
ll N, K, piatti[MAXN];

bool peso[MAXN];
ll ris;

void bottom_up(ll p){
    if(p >= K) ris = min(ris, p);
    for(ll i=K-1; i>=0; i--){
        if(peso[i]){
            if(i+p >= K) ris = min(i+p, ris);
            else peso[i+p] = true;
        }
    }
    if(p < K)peso[p] = true;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    cin >> N >> K;
    for(ll i=0; i<N; i++) cin >> piatti[i];

    ris = LLONG_MAX;
    /*for(ll i=0; i<(1<<N); i++){
        ll tmp = 0;
        for(ll j=0; j<N; j++){
            if(i & (1 << j)) tmp += piatti[j];
        }
        if(tmp >= K) ris = min(ris, tmp);
    }*/

    //ris = funzione(0, 0);

    for(ll i=0; i<N; i++){
        bottom_up(piatti[i]);
    }

    cout << ris << "\n";
    return 0;
}
