/*
				C++
				encoding: UTF-8
				Last Modified: 19/Aug/20 09:14:25 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int X, Y;
		cin >> X >> Y;

		set< int > a, b;
		int p = 0, q = 0;
		for (auto& i : s) {
			if (i == 'U')
				++p;
			else if (i == 'D')
				--p;
			else if (i == 'L')
				--q;
			else
				++q;
			a.insert (p);
			b.insert (q);
		}

		int l;
		cin >> l;
		while (l--) {
			int x, y;
			cin >> x >> y;
			x -= X;
			y -= Y;
			if (a.find (x) != a.end () and b.find (y) != b.end ())
				print ("YES", abs (x) + abs (y));
			else
				print ("NO");
		}
	}
	return 0;
}