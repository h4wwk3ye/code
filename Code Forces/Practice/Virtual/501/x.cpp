///==================================================///
///
///  Ir0nic_  ///
///  MEHUL BHUTALIA  ///
/// Indian Institute Of Information Technology and Management,Gwalior.  ///
///
///==================================================///
#include <bits/stdc++.h>
using namespace std;
#define T()    \
	int tt;    \
	cin >> tt; \
	while (tt--)
#define ll long long
#define vi vector< ll >
#define pii pair< ll, ll >
#define vpair vector< pii >
#define repp(i, a, n) for (ll i = a; i < n; ++i)
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rrep(i, n) for (ll i = n - 1; i >= 0; --i)
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
#define nl cout << endl;

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
ll arr1[1005][1005];
ll arr2[1005][1005];
ll arr3[1005][1005];
ll arr4[1005][1005];
ll ans1[1005][1005];
ll ans2[1005][1005];
ll min4 (ll a, ll b, ll c, ll d) {
	return min (a, min (b, min (c, d)));
}
int main () {
	fast;
	ll n, m;
	sc2 (n, m) string s[n];
	rep (i, n) sc (s[i])

	rep (i, n) rep (j, m) if (s[i][j] == '*') arr1[i + 1][j + 1] = arr1[i][j + 1] + 1;
	else arr1[i + 1][j + 1] = 0;

	rep (i, n) rep (j, m) if (s[i][j] == '*') arr2[i + 1][j + 1] = arr2[i + 1][j] + 1;
	else arr2[i + 1][j + 1] = 0;


	rrep (i, n) rrep (j, m) if (s[i][j] == '*') arr3[i + 1][j + 1] = arr3[i + 1][j + 2] + 1;
	else arr3[i + 1][j + 1] = 0;


	rrep (i, n) rrep (j, m) if (s[i][j] == '*') arr4[i + 1][j + 1] = arr4[i + 2][j + 1] + 1;
	else arr4[i + 1][j + 1] = 0;


	vector< pair< ll, pii > > final;
	repp (i, 1, n + 1) repp (j, 1, m + 1) if (s[i - 1][j - 1] == '*') {
		ll k = min4 (arr1[i][j], arr2[i][j], arr3[i][j], arr4[i][j]) - 1;
		if (k == 0) continue;
		final.p_b ({i, {j, k}});
		ll ii = i - k, jj = j - k;
		ans1[ii][j]++, ans2[i][jj]++;
		ii = i + k + 1, jj = j + k + 1;
		ans1[ii][j]--, ans2[i][jj]--;
	}
	repp (i, 1, n + 1) repp (j, 1, m + 1) ans1[i][j] += ans1[i - 1][j];


	repp (i, 1, n + 1) repp (j, 1, m + 1) ans2[i][j] += ans2[i][j - 1];
	rep (i, n) rep (j, m) {
		if (s[i][j] == '*' && (ans1[i + 1][j + 1] <= 0 && ans2[i + 1][j + 1] <= 0)) {
			cout << "-1";
			return 0;
		}
	}
	pr (final.size ()) rep (i, final.size ()) {
		cout << final[i].ff << " " << final[i].ss.ff << " " << final[i].ss.ss << "\n";
	}
}
