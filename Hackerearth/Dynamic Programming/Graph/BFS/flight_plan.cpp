/*
				C++
				encoding:UTF-8
				Modified: <05/Mar/2019 11:14:40 AM>

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

const int N=1e3+5;
int n,t,c,a,b;
ve<int> graph[N];
int dist[N],visited[N],parent[N];

void bfs(){
    visited[a]=1;
    queue<int> q;
    q.push(a);
    while (!q.empty()){
        int node=q.front();
        q.pop();
        for (int to: graph[node]){
            if (!visited[to]){
                parent[to]=node;
                dist[to]=1+dist[node];
                visited[to]=1;
                q.push(to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m;
    cin>>n>>m>>t>>c;
    int u,v;
    fr(i,0,m){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    fr(i,1,n+1){
        sort(all(graph[i]));
    }
    cin>>a>>b;
    bfs();
    pr1(dist[b]);
    int node=b;
    ve<int> ans;
    while(node!=0) {
        ans.pb(node);
        //cout<<node<<" ";
        node=parent[node];
    }
    //cout<<endl;
    reverse(all(ans));
    prv(ans);
    return 0;
}
