/*
				C++
				encoding:UTF-8
				Modified: <03/Mar/2019 12:57:09 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll					    long long
#define		 mod			        1000000007
#define		 ve				        vector
#define		 pb				        push_back
#define		 umap			        unordered_map
#define		 endl			        "\n";
#define		 len(v)			        ll(v.size())
#define		 reset(a, b)		    memset(a, b, sizeof(a));
#define		 sum(v)				    accumulate(v.begin(), v.end(), 0);
#define		 prll1(x)		        cout<<x<<"\n";
#define		 prll2(x, y)		    cout<<x<<" "<<y<<"\n";
#define		 prllv(v)		        for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n";
#define		 fr(i, s, e)		    for (ll i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const ll N=1e6+5;

ll parent[N],rnk[N];
ll n,m,k;
vector<pair<ll,pair<ll,ll>>> edges;
ll ans;
vector<ll> cost;

ll find(ll x){
    if (parent[x]!=x)
        parent[x]=find(parent[x]);
    return parent[x];
}

void unon(ll x, ll y){
    ll x_id=find(x);
    ll y_id=find(y);
    if (x_id==y_id)
        return;
    if (rnk[x_id]>rnk[y_id])
        parent[y_id]=x_id;
    else{
        parent[x_id]=y_id;
        if (rnk[x_id]==rnk[y_id])
            rnk[y_id]++;
    }
}

void kruskal(){
    ll weight,u,v;
    for (auto edge: edges){
        weight=edge.first;
        u=edge.second.first;
        v=edge.second.second;
        //cout<<weight<<" "<<u<<" "<<v<<"\n";
        if (find(u)!=find(v)){
            cost.pb(weight);
            ans+=weight;
            unon(u,v);
        }
    }
}

ll visited[N];
vector<ll> graph[N];
void dfs(ll node){
    visited[node]=1;
    for (ll neighbour: graph[node]){
        if (!visited[neighbour])
            dfs(neighbour);
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
    fr(i,0,N-2){
        parent[i]=i;
        rnk[i]=0;
    }
    cin>>n>>m>>k;
    ll u,v,w;
    edges.resize(m);
    fr(i,0,m){
        cin>>u>>v>>w;
        graph[u].pb(v);
        graph[v].pb(u);
        edges[i]={w,{u,v}};
    }
    dfs(1);
    fr(i,1,n+1){
        if (!visited[i]){
            prll1(-1);
            return 0;
        }
    }

    sort(edges.begin(),edges.end());
    kruskal();
    //prllv(cost);
    ll l=n-2,no=0;

    while (ans>k and l>=0){
        ans=ans-cost[l]+1;
        l--;
        no++;
    }
    if(ans>k){
        prll1(-1);
        return 0;
    }
    prll1(no);
	return 0;
}
