/*
				C++
				encoding: UTF-8
				Modified: <21/Jul/2019 12:11:28 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string s;
	cin >> s;
	int n = len (s);
	ve< int > v, o;
	fr (i, 0, n - 1) {
		if (s[i] == 'v' and s[i + 1] == 'v') v.pb (i);
		if (s[i] == 'o') o.pb (i);
	}
	// print (v);
	// print (o);
	ll ans = 0;
	for (auto i : v) {
		auto x = lower_bound (all (o), i);
		if (x == o.end ()) break;
		for (; x != o.end (); ++x) {
			auto y = lower_bound (all (v), *x);
			if (y == v.end ()) break;
			ll p = y - v.begin ();
			ans += len (v) - p;
		}
	}
	print (ans);
	return 0;
}
