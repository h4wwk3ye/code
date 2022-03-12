/*
				C++
				encoding:UTF-8
				Modified: <30/Mar/2019 11:40:30 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e5 + 5;
int n;
ve< int > graph[N];
int res[N];
int visited[N];
ve< int > curr, ans;
int flag;

void dfs (int node, int parent) {
	// visited[node] = 1;
	bool flag = false;

	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
		if (res[to] == 0) flag = true;
	}
	// pr2 (node, flag);
	if (!flag and res[node] == 1) ans.pb (node);
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	int root;
	fr (i, 1, n + 1) {
		int p, c;
		cin >> p >> c;
		if (p == -1) {
			root = i;
			continue;
		}
		graph[p].pb (i);
		res[i] = c;
	}
	fr (i, 1, n + 1) sort (all (graph[i]));

	dfs (root, -1);
	if (len (ans) == 0) {
		pr1 (-1);
		return 0;
	}
	sort (all (ans));
	for (int i : ans)
		cout << i << " ";
	cout << endl;

	return 0;
}
