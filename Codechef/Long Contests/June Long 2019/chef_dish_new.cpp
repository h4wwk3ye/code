/*
				C++
				encoding:UTF-8
				Modified: <15/Jun/2019 01:00:39 PM>

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
#define		 pii                    pair<ll, ll>
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

// clang-format on

const ll N = 3e5 + 5;
ll arr[N], fact[N];
umap< ll, ll > tree[4 * N];
ll n, m;

void build (ll node = 1, ll start = 1, ll end = n) {
	if (start == end) {
		tree[node][arr[start]] = 1;
		return;
	}
	ll mid = (start + end) / 2;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);
	for (auto& p : tree[2 * node]) {
		ll x = p.ff;
		ll y = p.ss;
		tree[node][x] += y;
	}
	for (auto& p : tree[2 * node + 1]) {
		ll x = p.ff;
		ll y = p.ss;
		tree[node][x] += y;
	}
}

ve< ll > query (ll node, ll l, ll r, ll start = 1, ll end = n) {
	ve< ll > ans;
	if (end < l or start > r) return ans;
	if (start >= l and end <= r) {
		for (auto p : tree[node]) {
			ans.pb (p.ss);
		}
		return ans;
	}
	ll mid = (start + end) / 2;
	ans = query (2 * node, l, r, start, mid);
	ve< ll > b;
	b = query (2 * node + 1, l, r, mid + 1, end);
	if (len (b) < len (ans)) {
		ans.insert (ans.end (), b.begin (), b.end ());
		return ans;
	} else {
		b.insert (b.end (), ans.begin (), ans.end ());
		return b;
	}
	return ans;
}

void precompute () {
	fact[0] = 1;
	fr (i, 1, N) fact[i] = (fact[i - 1] * i) % mod;
}

ll power (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}

void solve1 () {
	fr (i, 1, n + 1) cin >> arr[i];

	build ();

	map< pii, ll > already;
	ll l1, l2, r1, r2, l, r, a = 0;
	while (m--) {
		cin >> l1 >> l2 >> r1 >> r2;
		l = (l1 * a + l2) % n;
		r = (r1 * a + r2) % n;
		if (l > r) swap (l, r);
		l++;
		r++;
		if (already.find ({l, r}) != already.end ()) {
			a = already[{l, r}];
			pr1 (a);
			continue;
		}
		ve< ll > op = query (1, l, r);
		ll ans = fact[r - l + 1];
		ll div = 1;
		for (auto& p : op) {
			div = (div * fact[p]) % mod;
		}
		div = power (div, mod - 2, mod);
		a = (ans * div) % mod;
		already[{l, r}] = a;
		pr1 (a);
	}
}

ll res, ans[N];
struct rua {
	ll l, r, id;
} q[N];
ll b, l, r, cnt[5 * N];
bool cmp (rua x, rua y) {
	return x.l / b != y.l / b ? x.l < y.l : x.r < y.r;
}

void solve2 () {
	b = sqrt (n);
	fr (i, 1, n + 1) cin >> arr[i];
	for (int i = 1; i <= m; i++) {
		ll x, y;
		if (x > y) swap (x, y);
		q[i].l = x, q[i].r = y;
		q[i].id = i;
	}
	sort (q + 1, q + m + 1, cmp), l = 1;
	fr (i, 1, m + 1) {
		ll num = fact[q[i].r - q[i].l + 1];
		ll div = 1;
		while (l < q[i].l) {
			cnt[a[l]]--, res -= cnt[a[l]], l++;
		}
		while (l > q[i].l) {
			l--, res += cnt[a[l]], cnt[a[l]]++;
		}
		while (r > q[i].r) {
			cnt[a[r]]--, res -= cnt[a[r]], r--;
		}
		while (r < q[i].r) {
			r++, res += cnt[a[r]], cnt[a[r]]++;
		}
		ans[q[i].id] = res;
	}
	for (i, 1, m + 1)
		cout << ans[i] << endl;
	return;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	// freopen ("inp.txt", "r", stdin);
	precompute ();
	cin >> n >> m;

	if (n <= 1e3)
		solve1 ();
	else
		solve2 ();

	return 0;
}
