/*
				C++
				encoding:UTF-8
				Modified: <16/Mar/2019 10:45:18 AM>

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

const int N=405;
ve<int> graph[N];
int parent[N], visited[N],dist[N];
ve<int> new_graph[N];
int new_dist[N];

void bfs(int s){
    visited[s]=1;
    dist[s]=0;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int& to: graph[node]){
            if (!visited[to]){
                dist[to]=1+dist[node];
                visited[to]=1;
                q.push(to);
            }
        }
    }
}

void bfs_o(int s){
    visited[s]=1;
    new_dist[1]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int& to:new_graph[node]){
            if (!visited[to] and 1+new_dist[node]!=dist[to]){
                visited[to]=1;
                new_dist[to]=1+new_dist[node];
                q.push(to);
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    int u,v;
    fr(i,0,m){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    bfs(1);
    fr(i,1,n+1){
        fr(j,i+1,n+1){
            int flag=0;
            for(int& x: graph[i])
                if (x==j){
                    flag=1;
                    break;
                }
            if (flag==1)
                continue;
            new_graph[i].pb(j);
            new_graph[j].pb(i);
        }
    }

    reset(visited,0);
    bfs_o(1);
    if (dist[n]==0 or new_dist[n]==0){
        pr1(-1);
        return 0;
    }
    pr1(max(dist[n],new_dist[n]));
    return 0;
}
