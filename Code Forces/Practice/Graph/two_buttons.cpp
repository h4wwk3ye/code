/*
				C++
				encoding:UTF-8
				Modified: <03/Mar/2019 06:22:55 PM>

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

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,m;
    cin>>n>>m;
    if (n==m){
        print1(0);
        return 0;
    }
    queue<pair<int,int>> q;
    q.push({n,0});
    int visited[20005];
    reset(visited,0);
    while(1){
        auto p=q.front();
        q.pop();
        if (p.first==m){
            print1(p.second);
            return 0;
        }
        visited[p.first]=1;
        int a=p.first-1;
        int b=p.first*2;
        if (a>0 and !visited[a])
            q.push({a,p.second+1});
        if (p.first<m and !visited[b])
            q.push({b,p.second+1});
    }
	return 0;
}
