/*
				C++
				encoding:UTF-8
				Modified: <07/Jul/2019 03:01:46 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define ve vector
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define endl "\n";
#define ff first
#define ss second
#define len(v) int(v.size ())
#define all(v) v.begin (), v.end ()
#define reset(a, b) memset (a, b, sizeof (a));
#define sum(v) accumulate (v.begin (), v.end (), 0);
#define pr1(x) cout << x << "\n"
#define pr2(x, y) cout << x << " " << y << "\n"
#define prv(v)              \
	for (auto& ijk : v)     \
		cout << ijk << " "; \
	cout << "\n"
#define fr(i, s, e) for (int i = s; i < e; i++)

ll powermod (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}

vector< pair< int, pair< int, int > > > edges;
const int N = 5e3 + 5;
int parent[N], rnk[N];
ll ans;
ll find (int x) {
	if (parent[x] != x) parent[x] = find (parent[x]);
	return parent[x];
}

void unon (int x, int y) {
	int x_id = find (x);
	int y_id = find (y);
	if (x_id == y_id) return;
	if (rnk[x_id] > rnk[y_id])
		parent[y_id] = x_id;
	else {
		parent[x_id] = y_id;
		if (rnk[x_id] == rnk[y_id]) rnk[y_id]++;
	}
}

void kruskal () {
	int weight, u, v;
	for (auto p : edges) {
		weight = p.ff;
		u = p.ss.ff;
		v = p.ss.ss;
		if (find (u) != find (v)) {
			ans += weight;
			unon (u, v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int t;
	cin >> t;
	while (t--) {
		edges.clear ();
		int n, m;
		cin >> n >> m;
		fr (i, 0, n + 1) {
			parent[i] = i;
			rnk[i] = 0;
		}
		ans = 0;
		int u, v, w;
		fr (i, 0, m) {
			cin >> u >> v >> w;
			edges.pb ({w, {u, v}});
		}
		sort (all (edges), greater<> ());
		kruskal ();
		pr1 (ans);
	}
	return 0;
}
