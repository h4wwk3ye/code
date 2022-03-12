///==================================================///
///
///  Ir0nic_  ///
///  MEHUL BHUTALIA  ///
/// Indian Institute Of Information Technology and Management,Gwalior.  ///
///
///==================================================///
#include <bits/stdc++.h>

#define T()    \
	ll tt;     \
	cin >> tt; \
	while (tt--)
#define ll long long
#define vi vector< ll >
#define pii pair< ll, ll >
#define vpair vector< pii >
#define fast ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
#define repp(i, a, n) for (ll i = a; i < n; ++i)
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define p_b push_back
#define p_f push_front
#define pop_b pop_back ()
#define pop_f pop_front ()
#define m_p make_pair
#define sumv(v) accumulate (v.begin (), v.end (), 0);
#define sortv(v) sort (v.begin (), v.end ())
#define sort_dec(v) sort (v.begin (), v.end (), greater< ll > ())
#define l_b(v, l) lower_bound (v.begin (), v.end (), l)
#define u_b(v, l) upper_bound (v.begin (), v.end (), l)
#define pq priority_queue
#define ff first
#define ss second
#define len length ()
#define all(v) v.begin (), v.end ()
#define mset(a, b) memset (a, b, sizeof (a));

///==========INPUT=============///
#define sc(a) cin >> a;
#define sc2(a, b) cin >> a >> b;
#define sc3(a, b, c) cin >> a >> b >> c;
#define sc4(a, b, c, d) cin >> a >> b >> c >> d;

///==========PRINTING=============///
#define prarr(arr)                                             \
	rep (i, sizeof (arr) / sizeof (ll)) cout << arr[i] << " "; \
	nl
#define prvec(v)                            \
	rep (i, v.size ()) cout << v[i] << " "; \
	nl
#define pr(x) cout << x << "\n";
#define pr2(x, y) cout << x << " " << y << "\n";
#define pr3(x, y, z) cout << x << " " << y << " " << z << "\n";

///==========DEBUGGING=============///
#define debug(a) cout << "*" << a << endl;
#define debug2(a, b) cout << "$" << a << " " << b << endl;
#define debug3(a, b, c) cout << "$" << a << " " << b << " " << c << endl;
#define bug cout << "#" << endl;
#define nl cout << '\n';
#define endl '\n'

///==========CONSTANTS=============///
#define max6 1000005
#define max5 100004
#define max4 10003
#define mod 1000000007
#define inf 1e18
ll powermod (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}
using namespace std;
map< ll, vi > mp;
ll fun (ll i, ll j) {
	vi cnt;
	for (auto itr : mp)
		cnt.p_b (itr.ss.size ());
	int q = 0;
	for (auto itr : mp) {
		ll f1 = 0, f2 = 0;
		for (ll ii = 0; ii < itr.ss.size (); ii++) {
			if (itr.ss[ii] == i) f1 = 1;
			if (itr.ss[ii] == j) f2 = 1;
		}
		if (f1 + f2 == 2) cnt[q]--;
		q++;
	}
	rep (q, cnt.size ()) if (cnt[q] > 2) return inf;
	return 1;
}
ll fun2 (ll i, ll j, ll k) {
	vi cnt;
	for (auto itr : mp)
		cnt.p_b (itr.ss.size ());
	int q = 0;
	for (auto itr : mp) {
		ll f1 = 0, f2 = 0, f3 = 0;
		for (ll ii = 0; ii < itr.ss.size (); ii++) {
			if (itr.ss[ii] == i) f1 = 1;
			if (itr.ss[ii] == j) f2 = 1;
			if (itr.ss[ii] == k) f3 = 1;
		}
		if (f1 + f2 + f3 == 2) cnt[i]--;
		if (f1 + f2 + f3 == 3) cnt[q] -= 2;
		q++;
	}
	rep (q, cnt.size ()) if (cnt[q] > 2) return inf;
	return 2;
}
ll fun3 (ll i, ll j, ll k, ll m) {
	vi cnt;
	for (auto itr : mp)
		cnt.p_b (itr.ss.size ());
	int q = 0;

	for (auto itr : mp) {
		ll f1 = 0, f2 = 0;
		for (ll ii = 0; ii < itr.ss.size (); ii++) {
			if (itr.ss[ii] == i) f1 = 1;
			if (itr.ss[ii] == j) f2 = 1;
		}
		if (f1 + f2 == 2) cnt[q]--;
		q++;
	}
	q = 0;
	for (auto itr : mp) {
		ll f1 = 0, f2 = 0;
		for (ll ii = 0; ii < itr.ss.size (); ii++) {
			if (itr.ss[ii] == k) f1 = 1;
			if (itr.ss[ii] == m) f2 = 1;
		}
		if (f1 + f2 == 2) cnt[q]--;
		q++;
	}
	rep (q, cnt.size ()) if (cnt[q] > 2) return inf;
	return 2;
}
int main () {
	fast ll n, m, a;
	cin >> n >> m;
	ll arr[n];
	for (ll i = 0; i < n; i++) {
		arr[i] = i;
		for (ll j = 0; j < m; j++) {
			cin >> a;
			mp[a].p_b (i);
		}
	}
	ll ans = inf, f = 0;
	for (auto itr : mp) {
		if (itr.ss.size () > 2) f = 1;
	}
	if (f == 0) {
		cout << 0;
		return 0;
	}
	do {
		ans = min (fun (arr[0], arr[1]), ans);
	} while (next_permutation (arr, arr + n));
	if (ans != inf) {
		cout << ans;
		return 0;
	}
	do {
		ans = min (fun2 (arr[0], arr[1], arr[2]), ans);
	} while (next_permutation (arr, arr + n));
	if (ans != inf) {
		cout << ans;
		return 0;
	}
	do {
		ans = min (ans, fun3 (arr[0], arr[1], arr[2], arr[3]));
	} while (next_permutation (arr, arr + n));
	// debug(fun3(arr[0],arr[1],arr[2],arr[3]))
	if (ans != inf) {
		cout << ans;
		return 0;
	}
	cout << 3;
}
