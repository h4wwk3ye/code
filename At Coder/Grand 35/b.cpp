#include <bits/stdc++.h>
#define pii pair< int, int >
#define fr(i, n) for (int i = 0; i < n; ++i)
#define fr1(i, n) for (int i = 1; i <= n; ++i)
#define ss second
#define ff first
#define pb push_back

using namespace std;

int n, m;

const int N = 1e5 + 1;

int usd[N], arr[N], sz[N], par[N];
bool even[N];
vector< pii > adj[N];

int root (int x) {
	int tmp = x;
	while (arr[x] != x)
		x = arr[x];
	return arr[tmp] = x;
}

void merge (int x1, int x2, int idx) {
	int r1 = root (x1), r2 = root (x2);
	if (r1 == r2) return;
	adj[x1].push_back ({x2, idx});
	adj[x2].push_back ({x1, idx});
	if (sz[r2] > sz[r1]) swap (r1, r2);
	arr[r2] = r1;
	sz[r1] += sz[r2];
	return;
}

int dfs (int cur) {
	int rem = -1;
	if (!even[cur]) rem = cur;

	for (auto i : adj[cur]) {
		if (i.ff == par[cur]) continue;
		par[i.ff] = cur;
		int x = dfs (i.ff);
		if (x == -1) continue;
		usd[i.ss] ^= 1;
		if (rem == -1) {
			rem = x;
			continue;
		}
		rem = -1;
	}
	return rem;
}

void solve () {
	cin >> n >> m;

	if (m % 2) {
		int a, b;
		fr (j, m) {
			cin >> a >> b;
		}
		cout << "-1\n";
		return;
	}

	fr1 (i, n) {
		even[i] = 1;
		adj[i].clear ();
		arr[i] = i;
		sz[i] = 1;
		par[i] = -1;
	}
	vector< pii > edges;
	fr (i, m) {
		usd[i] = 0;
		int a, b;
		cin >> a >> b;
		even[b] ^= 1;
		merge (a, b, i);
		edges.pb ({a, b});
	}

	dfs (1);

	// fr (i, m) cout << usd[i] << " ";
	fr (i, m) {
		if (usd[i])
			cout << edges[i].ff << " " << edges[i].ss << endl;
		else
			cout << edges[i].ss << " " << edges[i].ff << endl;
	}
	cout << "\n";
	return;
}

int main () {
	ios_base::sync_with_stdio (false);
	solve ();
	return 0;
}
