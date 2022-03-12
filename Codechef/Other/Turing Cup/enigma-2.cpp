/*
				C++
				encoding:UTF-8
				Modified: <16/Mar/2019 09:18:28 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 prv(v)                 for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=1e5+5;
int n,k;
ve<int> graph[N];
ve<int> reversed_graph[N];
int visited[N];
ve<int> stk;
int scc;
int com[N];

void initialise(){
    fr(i,1,n+1){
        graph[i].clear();
        reversed_graph[i].clear();
    }
    scc=-1;
    reset(visited,0);
    stk.clear();
    reset(com,0);
}

void dfs(int node){
    visited[node]=1;
    for(int to: reversed_graph[node])
        if (!visited[to])
            dfs(to);
    stk.pb(node);
}

void dfs_o(int node){
    visited[node]=1;
    com[scc]++;
    for (int to: graph[node])
        if (!visited[to])
            dfs_o(to);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        cin>>n>>k;
        initialise();

        int u,v;
        fr(i,0,k){
            cin>>u>>v;
            graph[u].pb(v);
            reversed_graph[v].pb(u);
        }
        int m;
        cin>>m;
        int x[m];
        fr(i,0,m)
            cin>>x[i];
        sort(x,x+m);
        fr(i,1,n+1){
            if (!visited[i]){
                dfs(i);
            }
        }
        reverse(all(stk));
        reset(visited,0);
        for (int node: stk){
            if (!visited[node]){
                scc++;
                dfs_o(node);
            }
        }
        int ind=0;
        multiset<int> s;
        fr(i,0,scc+1)
            s.insert(com[i]);
        int ans=0;
        fr(i,0,m){
            while(!s.empty()){
                auto p=s.begin();
                int y=*p;
                s.erase(p);
                if(y>=x[i]){
                    ans++;
                    break;
                }
            }
        }
        pr1(ans);
    }
    return 0;
}
