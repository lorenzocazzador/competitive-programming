#include <bits/stdc++.h>
#define maxn 210
using namespace std;
#define ll long long

int n;
ll mat[maxn][maxn];

ll dip(){
	vector<ll>mam(n,0),tmam(n,0),sus(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sus[i] += mat[i][j];
		}
	}

	for(int en=0;en<1;en++){
		mam[en] = max(mam[en],mat[0][en]);

		ll som = mat[0][en];
		for(int us = en+1;us != en;us++){
			if(us == n)us = 0;
			if(us == en)break;

			som += mat[0][us];
			ll perc = max(som,sus[0] - som + mat[0][en] + mat[0][us]);
			mam[us] = max(mam[us],perc);
		}
	}
	for(int r=1;r<n;r++){
		for(int i=0;i<n;i++)
			tmam[i] = 0;

		for(int en=0;en<n;en++){
			tmam[en] = max(tmam[en], mam[en] + mat[r][en]);

			ll som = mat[r][en];
			for(int us = en+1;us != en;us++){
				if(us == n)us = 0;
				if(us == en)break;

				som += mat[r][us];
				ll perc = max(som, sus[r] - som + mat[r][en] + mat[r][us]);
				tmam[us] = max(tmam[us],mam[en] + perc);
			}
		}

		swap(mam,tmam);
	}

	return mam[n-1];
}

void trasponi(){
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			swap(mat[i][j],mat[j][i]);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	ll mam = dip();
	trasponi();
	mam = max(mam,dip());
	cout<<mam<<endl;
}
