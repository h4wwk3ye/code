/*
				C++
				encoding:UTF-8
				Modified: <04/Mar/2019 05:25:43 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll					long long
#define		 mod					1000000007
#define		 ve					vector
#define		 pb					push_back
#define		 umap					unordered_map
#define		 pq					priority_queue
#define		 endl					"\n";
#define		 ff					first
#define		 ss					second
#define		 len(v)					int(v.size())
#define		 all(v)					v.begin(), v.end()
#define		 reset(a, b)				memset(a, b, sizeof(a));
#define		 sum(v)					accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)					cout<<x<<"\n"
#define		 pr2(x, y)				cout<<x<<" "<<y<<"\n"
#define		 prv(v)					for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, e)				for (int i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=1e5+5;
int n,q;
ve<int> graph[N];
string value[N];
int visited[N];
umap<char,int> mp[N];

void dfs(int node){
    visited[node]=1;
    for (auto to: graph[node]){
        if (!visited[to]){
            dfs(to);
            value[node].append(value[to]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>n>>q;
    fr(i,1,n+1)
        cin>>value[i];
    int u,v;
    fr(i,0,n-1){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    fr(i,1,n+1){
        for (char p:value[i]){
            mp[i][p]++;
        }
    }
    int x;
    string s;
    fr(i,0,q){
        umap<char,int> omp;
        cin>>x>>s;
        int ans=0;
        omp.insert(all(mp[x]));
        for (char j: s){
            if (omp.find(j)==omp.end() or omp[j]==0)
                ans++;
            else
                omp[j]--;
        }
        pr1(ans);
    }
	return 0;
}
