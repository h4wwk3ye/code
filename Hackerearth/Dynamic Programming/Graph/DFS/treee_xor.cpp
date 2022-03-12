/*
				C++
				encoding:UTF-8
				Modified: <07/Mar/2019 05:02:16 PM>

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
int n,k;
ve<int> graph[N];

int value[N];

void dfs(int node, int parent, int curr){
    value[node]=curr;
    if (node==1){
        if (len(graph[1])>=k)
            curr^=1;
    }
    else{
        if (len(graph[node])-1>=k){
            curr^=node;
        }
    }
    for(int to: graph[node]){
        if (to!=parent){
            //value[to]=curr;
            dfs(to,node,curr);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen("in.txt" , "r" , stdin);
    cin>>n>>k;
    int u,v;
    fr(i,0,n-1){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    fr(i,1,n+1){
        value[i]=i;
    }
    dfs(1,-1,0);
    fr(i,1,n+1)
        cout<<value[i]<<"\n";
    return 0;
}
