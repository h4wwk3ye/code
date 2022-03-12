/*
				C++
				encoding:UTF-8
				Modified: <03/Mar/2019 07:00:41 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll						long long
#define		 mod						1000000007
#define		 ve						vector
#define		 pb						push_back
#define		 umap						unordered_map
#define		 endl						"\n";
#define		 len(v)						int(v.size())
#define		 all(v)						v.begin(), v.end()
#define		 reset(a, b)					memset(a, b, sizeof(a));
#define		 sum(v)						accumulate(v.begin(), v.end(), 0);
#define		 pr1(x)						cout<<x<<"\n";
#define		 pr2(x, y)					cout<<x<<" "<<y<<"\n";
#define		 prv(v)						for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n";
#define		 fr(i, s, e)					for (int i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=1e3+5;
int matrix[N][N],visited[N][N];
int n;

void dfs(int x,int y){
    visited[x][y]=1;
    fr(i,1,N){
        if (i!=x and matrix[i][y]==1 and !visited[i][y])
            dfs(i,y);
    }
    fr(i,1,N){
        if (i!=y and matrix[x][i]==1 and !visited[x][i])
        dfs(x,i);
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>n;
    int x,y;
    fr(i,0,n){
        cin>>x>>y;
        matrix[x][y]=1;
    }
    int ans=-1;
    fr(i,1,N){
        fr(j,1,N){
            if (matrix[i][j]==1 and !visited[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    pr1(ans);
	return 0;
}
