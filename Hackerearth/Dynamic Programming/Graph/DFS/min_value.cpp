/*
				C++
				encoding:UTF-8
				Modified: <04/Mar/2019 10:36:48 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll						signed long long
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
#define		 sum(v)						accumulate(all(v), ll(0));
#define		 pr1(x)						cout<<x<<"\n";
#define		 pr2(x, y)					cout<<x<<" "<<y<<"\n"
#define		 prv(v)						for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, e)					for (ll i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const ll N=1e5+5;
ll n,x;
ve<ll> weight(N);
ve<ll> graph[N];
ll visited[N];

void bfs(){
    visited[1]=1;
    queue<ll> q;
    q.push(1);
    ll node;
    while(!q.empty()){
        node=q.front();
        q.pop();
        if (node==1 and len(graph[node])<=1){
            graph[node].pb(n+1);
            weight[n+1]=x;
            return;
        }
        else if (node!=1 and len(graph[node])<=2){
            graph[node].pb(n+1);
            weight[n+1]=x;
            //pr2(node,"yes");
            return;
        }
        for (ll ne: graph[node]){
            if (!visited[ne]){
                q.push(ne);
                visited[ne]=1;
            }
        }
    }

}

void dfs(ll node){
    visited[node]=1;
    for (ll ne: graph[node]){
        if (!visited[ne]){
            dfs(ne);
            weight[node]+=weight[ne];
        }
    }
}

signed main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>x;
    fr(i,1,n+1)
        cin>>weight[i];
    ll u,v;
    fr(i,0,n-1){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    bfs();
    /*fr(i,1,n+2)
        cout<<weight[i]<<" ";

    cout<<endl;*/
    reset(visited,0);
    dfs(1);
    ll total=0;

    fr(i,1,n+2)
        total+=weight[i];

    //cout<<endl;
    pr1(total);
	return 0;
}
