/*
				C++
				encoding:UTF-8
				Modified: <19/May/2019 06:10:14 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
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
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 5e5 + 5;
ll parent[N], Rank[N];


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
	} else {
		parent[x_id] = y_id;
		if (Rank[x_id] == Rank[y_id]) Rank[y_id]++;
	}
}

int n, m;

void init () {
	fr (i, 1, n + 1) parent[i] = i;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m;
	init ();
	fr (i, 0, m) {
		int x, y, z;
		cin >> x >> y >> z;
		Union (x, y);
	}
	umap< int, int > mp;
	int ans = 0;
	fr (i, 1, n + 1) {
		ll x = Find (i);

		if (mp.find (x) != mp.end ()) continue;
		mp[x] = 1;
		ans++;
	}
	pr1 (ans);
	return 0;
}
