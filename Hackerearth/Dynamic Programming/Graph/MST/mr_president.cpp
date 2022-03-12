/*
				C++
				encoding:UTF-8
				Modified: <03/Mar/2019 12:00:05 PM>

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
#define		 len(v)			        v.size()
#define		 reset(a, b)		    memset(a, b, sizeof(a));
#define		 sum(v)				    accumulate(v.begin(), v.end(), 0);
#define		 print1(x)		        cout<<x<<"\n";
#define		 print2(x, y)		    cout<<x<<" "<<y<<"\n";
#define		 printv(v)		        for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n";
#define		 fr(i, s, e)		    for (int i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=1e6+5;
int n,m,k;
vector<pair<int, int>> graph[N];
int visited[N];
//ll dis[N];
vector<int> cost;
int weight;

void prims(){
    set<pair<int,int>> s;
    s.insert({0,1});
    //fill(dis,dis+N,1e9);
    int v,x;

    while (!s.empty()){
        v=s.begin()->second;
        x=s.begin()->first;
        s.erase(s.begin());
        if (visited[v])
            continue;
        visited[v]=1;
        cost.pb(x);
        weight+=x;
        for (auto p: graph[v]){
            int u=p.second;
            int w=p.first;
            if (!visited[u])
                s.insert(p);
        }
    }

}

int main() {
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
    int u,v,c;
    fr(i,0,m){
        cin>>u>>v>>c;
        graph[u].pb({c,v});
        graph[v].pb({c,u});
    }
    prims();
    fr(i,1,n+1){
        if (!visited[i]){
            print1(-1);
            return 0;
        }
    }
    //printv(cost)
    sort(cost.begin(),cost.end());
    ll sum=0,cnt=0;
    for (int i: cost){
        if ((i+sum)<=k-cnt){
            sum+=i;
            cnt+=1;
        }
        else
            break;
    }
    int l=len(cost)-1;
    int ans=0;
    while (weight>k and l>=0){
        weight-=(cost[l]);
        weight++;
        l--;
        ans++;
    }
    if (weight>k){
        print1(-1);
        return 0;
    }
    print1(ans);
	return 0;
}
