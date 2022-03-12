/*
				C++
				encoding:UTF-8
				Modified: <08/Mar/2019 10:32:27 AM>

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
ve<pair<int,int>> graph[N];
int n,value[N],ans;

void init(){
    ans=0;
    fr(i,1,n+1){
        graph[i].clear();
        value[i]=0;
    }
}
void dfs(int node,int parent){
    if (len(graph[node])==1 and node!=1)
        if (value[node] % 2==1)
            ans++;

    for(auto to: graph[node]){
        if (to.ff==parent)
            continue;

        value[to.ff]=value[node]^to.ss;
        dfs(to.ff,node);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        init();
        int u,v,c;
        fr(i,0,n-1){
            cin>>u>>v>>c;
            graph[u].pb({v,c});
            graph[v].pb({u,c});
        }
        dfs(1,-1);
        pr1(ans);
    }
    return 0;
}
