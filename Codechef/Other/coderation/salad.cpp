/*
				C++
				encoding:UTF-8
				Modified: <10/Apr/2019 02:12:36 PM>

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
#define		 pii                    pair<ll, ll>
#define		 len(v)                 ll(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (ll i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on
const ll N = 1e6 + 5;

ll value[N];
ll root;
ll t, u, v, val;
ll curr, mx, cnt, ans;
ll parent[N], visited[N];

ll findLCA (ll n1, ll n2) {
	visited[n1] = true;
	while (parent[n1] != n1) {
		visited[n1] = true;
		n1 = parent[n1];
	}

	visited[n1] = true;

	while (!visited[n2])
		n2 = parent[n2];

	return n2;
}


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	// fill (parent, parent + N, -1);
	int q;
	cin >> root >> val >> q;
	value[root] = val;
	parent[root] = root;
	while (q--) {
		cin >> t >> u >> v;
		if (t == 0) {
			cin >> value[v];
			parent[v] = u;
		} else if (t == 1) {
			ans = 0;
			mx = value[root] ^ v;
			ans = value[root];
			cnt = 1;
			while (parent[u] != u) {
				curr = value[u] ^ v;
				if (curr > mx) {
					mx = curr;
					ans = value[u];
					cnt = 1;
				} else if (curr == mx) {
					cnt++;
					ans = value[u];
				}
				u = parent[u];
			}
			pr2 (ans, cnt);
		} else {
			cin >> val;
			reset (visited, false);
			ll p = findLCA (u, v);
			cnt = 0;
			while (u != p) {
				if (value[u] < val) cnt++;
				u = parent[u];
			}
			while (v != p) {
				if (value[v] < val) cnt++;
				v = parent[v];
			}
			if (value[p] < val) cnt++;
			pr1 (cnt);
		}
	}
	return 0;
}
