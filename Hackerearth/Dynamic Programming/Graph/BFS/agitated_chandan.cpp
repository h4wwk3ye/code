/*
				C++
				encoding:UTF-8
				Modified: <18/Mar/2019 03:03:19 PM>

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
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e5 + 5;
int n;
ve< pair< int, int > > graph[N];
int visited[N], dist[N];

void initialise () {
	reset (visited, 0);
	reset (dist, 0);
	fr (i, 1, n + 1) graph[i].clear ();
}

void bfs (int node) {
	visited[node] = 1;
	dist[node] = 0;
	queue< int > q;
	q.push (node);
	while (!q.empty ()) {
		int from = q.front ();
		q.pop ();
		for (auto& i : graph[from]) {
			if (!visited[i.ff]) {
				visited[i.ff] = 1;
				q.push (i.ff);
				dist[i.ff] = dist[from] + i.ss;
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		initialise ();
		cin >> n;
		int u, v, d;
		fr (i, 0, n - 1) {
			cin >> u >> v >> d;
			graph[u].pb ({v, d});
			graph[v].pb ({u, d});
		}

		bfs (1);
		int source, mx = -1;
		fr (i, 1, n + 1) {
			if (dist[i] > mx) {
				mx = dist[i];
				source = i;
			}
		}
		reset (visited, 0);
		reset (dist, 0);
		bfs (source);
		mx = -1;
		fr (i, 1, n + 1) if (dist[i] > mx) mx = dist[i];
		int cost;
		if (mx <= 100)
			cost = 0;
		else if (mx <= 1000)
			cost = 100;
		else if (mx < 10000)
			cost = 1000;
		else
			cost = 10000;
		pr2 (cost, mx);
	}
	return 0;
}
