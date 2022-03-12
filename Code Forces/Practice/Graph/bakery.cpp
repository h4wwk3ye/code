/*
				C++
				encoding:UTF-8
				Modified: <01/Mar/2019 07:51:18 PM>

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

const int N=1e5+5;
int n,m,k;
ve<pair<int,int>> graph[N];
ve<int> storages;
umap<int,int> mp;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    int u,v,l;
    fr(i,0,m){
        cin>>u>>v>>l;
        graph[u].pb(make_pair(l,v));
        graph[v].pb(make_pair(l,u));
    }
    if (k==0)
        {
            print1(-1);
            return 0;
        }
    if (k>0){
        storages.resize(k);
        fr(i,0,k){
            cin>>storages[i];
            mp[storages[i]]=1;
        }
    }
    ll ans=1e15;
    fr (i,0,k){
        for (auto p: graph[storages[i]]){
            if (mp.find(p.second)!=mp.end())
                continue;
            ll weight=p.first;
            ans=min(ans,weight);
        }
    }
    if (ans==1e15)
        print1(-1)
    else
        print1(ans);
    return 0;
}
