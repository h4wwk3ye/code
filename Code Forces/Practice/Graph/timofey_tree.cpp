/*
				C++
				encoding:UTF-8
				Modified: <16/Mar/2019 11:40:26 AM>

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
ve<int> graph[N];
int color[N], flag, curr;

void dfs(int node,int parent){
    for(int& to:graph[node]){
        if (to==parent or to==curr)
            continue;
        if (color[to]!=color[node]){
            flag=1;
            return;
        }
        dfs(to,node);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int u,v;
    fr(i,0,n-1){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    umap<int, int> x;
    fr(i,1,n+1){
        cin>>color[i];
        x[color[i]]=1;
    }

    if (n==2){
        pr1("YES");
        pr1(1);
        return 0;
    }


    if (len(x)==1){
        pr1("YES");
        pr1(1);
        return 0;
    }

    fr(i,1,n+1){
        curr=i;
        flag=0;
        for(int& to: graph[i]){
            if (color[to]!=color[i]){
                u=i, v=to;
                flag=1;
                break;
            }
        }
        if (flag)
            break;
    }

    flag=0;
    curr=u;
    for(int& to: graph[u]){
        dfs(to,-1);
        if(flag)
            break;
    }
    if (flag==0){
        pr1("YES");
        pr1(u);
        return 0;
    }
    flag=0;
    curr=v;
    for(int& to:graph[v]){
        dfs(to,-1);
        if (flag)
            break;
    }
    if (flag==0){
        pr1("YES");
        pr1(v);
        return 0;
    }

    pr1("NO");

    return 0;
}
