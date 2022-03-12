/*
				C++
				encoding:UTF-8
				Modified: <07/Mar/2019 01:23:58 PM>

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
#define		 fr(i, k, n)				for (int i = k ; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=1e5+5;
int n;
ve<pair<int,int>> graph[N];
int value[N], cost[N];
ll ans;

void dfs(int node,int parent){
    //visited[node]=1;
    for(auto to: graph[node]){
        if (to.ff!=parent and to.ff!=1){
            cost[to.ff]=to.ss;
            dfs(to.ff, node);
            cost[node]+=cost[to.ff];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    int u,v,c;
    fr(i,1,n+1)
        cin>>value[i];
    fr(i,0,n-1){
        cin>>u>>v>>c;
        graph[u].pb({v,c});
        graph[v].pb({u,c});
    }
    for(auto node: graph[1]){
        dfs(node.ff,-1);
    }

    int mx=-1,ind;
    for (auto i: graph[1]){
        if (cost[i.ff]>mx)
            ind=i.ff;
    }
    pr2("index",ind);
    fr(i,1,n+1)
        cout<<cost[i]<<" ";
    cout<<"ans \n";
    for (auto i: graph[1]){
        if (ind!=i.ff){
            ans+=2*(cost[i.ff]+i.ss);
        }
    }
    pr1(ans);
    return 0;
}
