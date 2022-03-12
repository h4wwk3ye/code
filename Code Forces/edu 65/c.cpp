/*
				C++
				encoding:UTF-8
				Modified: <15/May/2019 08:53:10 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
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
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 5e5 + 5;
ll parent[N], Rank[N], sz[N];

ll Find (int x) {
	if (parent[x] != x) {
		parent[x] = Find (parent[x]);
	}
	return parent[x];
}

void Union (int x, int y) {
	ll x_id = Find (x);
	ll y_id = Find (y);
	if (x_id == y_id) return;

	if (Rank[x_id] > Rank[y_id]) {
		parent[y_id] = x_id;
		sz[x_id] += sz[y_id];
	} else {
		parent[x_id] = y_id;
		sz[y_id] += sz[x_id];
		if (Rank[x_id] == Rank[y_id]) Rank[y_id]++;
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, m;
	cin >> n >> m;
	fr (i, 1, n + 1) parent[i] = i;
	fill (sz, sz + N, 1);
	fr (i, 0, m) {
		int k;
		cin >> k;
		if (k == 0) continue;
		int x;
		cin >> x;
		fr (i, 1, k) {
			int y;
			cin >> y;
			Union (x, y);
		}
	}

	fr (i, 1, n + 1) {
		int a = Find (i);
		sz[i] = sz[a];
	}
	fr (i, 1, n + 1) {
		cout << sz[i] << " ";
	}
	return 0;
}
