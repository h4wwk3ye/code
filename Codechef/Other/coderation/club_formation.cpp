/*
				C++
				encoding:UTF-8
				Modified: <09/Apr/2019 02:36:54 PM>

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
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on
#define BLOCK 174


const int N = 1e5 + 5;
ll parent[N], Rank[N], sz[N];
int answer;
struct query {
	int l, r, ind;
} Queries[N];

int ans[N];
int a[N];
int cnt[N];

void addition (int index) {
	cnt[a[index]]++;
	if (cnt[a[index]] == 1) answer++;
}

void subtraction (int index) {
	cnt[a[index]]--;
	if (cnt[a[index]] == 0) answer--;
}

bool fnc (query f, query s) {
	if ((f.l / BLOCK) != (s.l / BLOCK))
		return (f.l / BLOCK) < (s.l / BLOCK);
	else
		return f.r < s.r;
}

void init () {
	fr (i, 0, N) {
		parent[i] = i;
		Rank[i] = 0;
		sz[i] = 1;
	}
}

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

	if (sz[x_id] % 2 != sz[y_id] % 2) return;

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
	init ();
	int n, m, q;
	cin >> n >> m >> q;
	fr (i, 0, m) {
		int x, y;
		cin >> x >> y;
		Union (x, y);
	}

	fr (i, 1, n + 1) {
		parent[i] = Find (i);
	}

	fr (i, 0, n) {
		a[i] = parent[i + 1];
	}

	fr (i, 0, q) {
		cin >> Queries[i].l >> Queries[i].r;
		Queries[i].ind = i;
		Queries[i].l--;
		Queries[i].r--;
	}
	sort (Queries, Queries + q, fnc);
	int cl = 0, cr = 0;
	fr (i, 0, q) {
		int left = Queries[i].l, right = Queries[i].r;
		while (cl < left)
			subtraction (cl), cl++;
		while (cl > left)
			addition (cl - 1), cl--;
		while (cr <= right)
			addition (cr), cr++;
		while (cr > (right + 1))
			subtraction (cr - 1), cr--;
		ans[Queries[i].ind] = answer;
	}
	fr (i, 0, q) pr1 (ans[i]);
	return 0;
}
