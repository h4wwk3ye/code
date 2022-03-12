/*
				C++
				encoding:UTF-8
				Modified: <06/Mar/2019 07:05:00 PM>

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
ve<int> graph[N];
int visited[N],child[N],ans,check;

void dfs(int node){
    visited[node]=1;
    for (int to: graph[node]){
        if (!visited[to]){
            if (check==0){
                if (len(graph[to])-1>len(graph[node]))
                    ans++;
                check=1;
            }
            else if (len(graph[to])>len(graph[node]))
                ans++;
            dfs(to);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m;
    cin>>n>>m;
    int u,v;
    fr(i,0,m){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    fr(i,1,n+1){
        if (!visited[i]){
            check=0;
            dfs(i);
        }
    }

    pr1(ans);
    return 0;
}
