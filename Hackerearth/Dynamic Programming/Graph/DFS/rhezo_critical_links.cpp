/*
				C++
				encoding:UTF-8
				Modified: <04/Mar/2019 02:25:23 AM>

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
#define		 pq						priority_queue
#define		 endl						"\n";
#define		 ff						first
#define		 ss						second
#define		 len(v)						int(v.size())
#define		 all(v)						v.begin(), v.end()
#define		 reset(a, b)					memset(a, b, sizeof(a));
#define		 sum(v)						accumulate(v.begin(), v.end(), 0);
#define		 pr1(x)						cout<<x<<"\n"
#define		 pr2(x, y)					cout<<x<<" "<<y<<"\n"
#define		 prv(v)						for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, e)					for (int i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

int n,m,p;
const int N=1e5+5;
ve<int> graph[N];
int visited[N],low[N],disc[N],parent[N];
int t,bridges,scc;
int cc[N],no[N],sz[N];

void ddfs(int node){
    visited[node]=1;
    no[scc]++;
    cc[node]=scc;
    for (int ne: graph[node])
        if (!visited[ne])
            ddfs(ne);
}

void explore(int node){
    visited[node]=1;
    low[node]=disc[node]=++t;
    sz[node]=1;
    int children=0;
    for (int child: graph[node]){
        if (!visited[child]){
            parent[child]=node;
            explore(child);
            low[node]=min(low[node], low[child]);
            sz[node]+=sz[child];
            if (low[child]>disc[node] and abs(sz[child]-no[cc[node]]-sz[child])<p){
                bridges++;
            }
        }
        else if(child!=parent[node])
            low[node]=min(low[node],disc[child]);
    }
}

void dfs(){
    fr(i,1,n+1){
        low[i]=1e7;
        disc[i]=1e7;
        parent[i]=-1;
        visited[i]=0;
    }
    fr(i,1,n+1){
        if (!visited[i])
            explore(i);
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>n>>m>>p;
    int u, v;
    fr(i,0,m){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    fr(i,1,n+1){
        if (!visited[i]){
            scc++;
            ddfs(i);
        }
    }
    dfs();
    pr1(bridges);
	return 0;
}
