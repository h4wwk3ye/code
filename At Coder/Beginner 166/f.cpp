//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 03/May/20 06:40:21 PM
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

map< pair< string, int >, pair< bool, char > > mp;
int n;
ve< string > arr;

bool solve (int i, int a, int b, int c) {
	if (a < 0 or b < 0 or c < 0) return 0;
	if (i == n) return 1;

	string x = to_string (a) + to_string (b) + to_string (c);

	if (mp.find ({x, i}) != mp.end ()) return mp[{x, i}].ff;
	bool ans = 0;
	char d = 'A';
	if (arr[i] == "AB") {
		ans = solve (i + 1, a - 1, b + 1, c);
		if (ans) {
			d = 'B';
		} else {
			ans = solve (i + 1, a + 1, b - 1, c);
			if (ans) {
				d = 'A';
			}
		}

	} else if (arr[i] == "AC") {
		ans = solve (i + 1, a - 1, b, c + 1);
		if (ans) {
			d = 'C';
		} else {
			ans = solve (i + 1, a + 1, b, c - 1);
			if (ans) {
				d = 'A';
			}
		}

	} else {
		ans = solve (i + 1, a, b - 1, c + 1);
		if (ans) {
			d = 'C';

		} else {
			ans = solve (i + 1, a, b + 1, c - 1);
			if (ans) {
				d = 'B';
			}
		}
	}
	mp[{x, i}] = {ans, d};

	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int a, b, c;
	cin >> n >> a >> b >> c;
	arr.resize (n);
	fr (i, 0, n) cin >> arr[i];
	bool ans = solve (0, a, b, c);
	if (!ans) {
		pr ("No");
		return 0;
	}
	pr ("Yes");
	fr (i, 0, n) {
		string x = to_string (a) + to_string (b) + to_string (c);
		if (arr[i] == "AB" and mp[{x, i}].ss == 'A') { // a added and b subtracted
			pr ('A');
			a++;
			b--;
		} else if (arr[i] == "AB" and mp[{x, i}].ss == 'B') {
			pr ('B');
			b++;
			a--;
		} else if (arr[i] == "AC" and mp[{x, i}].ss == 'A') {
			pr ('A');
			a++;
			c--;
		} else if (arr[i] == "AC" and mp[{x, i}].ss == 'C') {
			pr ('C');
			a--;
			c++;
		} else if (arr[i] == "BC" and mp[{x, i}].ss == 'B') {
			pr ('B');
			b++;
			c--;
		} else {
			pr ('C');
			c++;
			b--;
		}
	}
	return 0;
}