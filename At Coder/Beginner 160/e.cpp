//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 28/Mar/20 06:43:27 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	int red[a], green[b], colorless[c];
	fr (i, 0, a) cin >> red[i];
	fr (i, 0, b) cin >> green[i];
	fr (i, 0, c) cin >> colorless[i];

	int p = 0, q = 0, r = 0;
	sort (red, red + a, greater< int > ());
	sort (green, green + b, greater< int > ());
	sort (colorless, colorless + c, greater< int > ());

	int ans = 0, cnt1 = 0, cnt2 = 0;

	while (cnt1 < x and cnt2 < y) {
		if (p != a and q != b and r != c) { // all present
			int mn = min ({red[p], green[q], colorless[r]});
			if (colorless[r] == mn) { // use p and q
				ans += red[p] + green[q];
				p++;
				q++;
			} else if (red[p] == mn) { // use colorless instead of red
				ans += colorless[r] + green[q];
				q++;
				r++;
			} else {
				ans += red[p] + colorless[r];
				p++;
				r++;
			}
		} else if (p != a and q != b) { // colorless finished
			ans += red[p] + green[q];
			p++;
			q++;
		} else if (q != b and r != c) { // red over
			ans += colorless[r] + green[q];
			q++;
			r++;
		} else if (p != a and r != c) { // green over
			ans += red[p] + colorless[r];
			p++;
			r++;
		} // no else as if two of p, q and r are over atleast one of cnt1 and cnt2 is over
		cnt1++;
		cnt2++;
	}

	//  either cnt1 or cnt2 will be over

	while (cnt1 < x) {
		if (p == a) {
			ans += colorless[r];
			r++;
		} else if (r == c) {
			ans += red[p];
			p++;
		} else {
			int mn = min ({red[p], colorless[r]});
			if (colorless[r] == mn) { // use p
				ans += red[p];
				p++;
			} else {
				ans += colorless[r];
				r++;
			}
		}
		cnt1++;
	}

	while (cnt2 < y) {
		if (q == b) {
			ans += colorless[r];
			r++;
		} else if (r == c) {
			ans += green[q];
			q++;
		} else {
			int mn = min ({green[q], colorless[r]});
			if (colorless[r] == mn) { // use p
				ans += green[q];
				q++;
			} else {
				ans += colorless[r];
				r++;
			}
		}
		cnt2++;
	}

	pr (ans);

	return 0;
}