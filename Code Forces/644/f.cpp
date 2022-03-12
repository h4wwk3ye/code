//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/May/20 08:42:06 PM
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
set< string > a;
ve< string > arr;
int n, m;
bool o;
string ans;

void solve () {
	string ans1, ans2;

	fr (i, 0, m) {
		int idx = -1;
		char x = arr[0][i];
		fr (j, 1, n) {
			if (arr[j][i] != x) {
				idx = j;
				break;
			}
		}

		if (idx == -1) {
			ans1 += x;
			ans2 += x;
		} else {
			ans1 += x;
			ans2 += arr[idx][i];
			fr (j, len (ans1), m) {
				ans2 += arr[0][j];
				ans1 += arr[idx][j];
			}
			break;
		}
	}

	o = 1;

	fr (i, 0, n) {
		int c = 0;
		fr (j, 0, m) {
			if (arr[i][j] != ans1[j]) {
				c++;
			}
		}
		if (c > 1) {
			o = 0;
			break;
		}
	}
	if (o) {
		ans = ans1;
		return;
	}
	o = 1;

	fr (i, 0, n) {
		int c = 0;
		fr (j, 0, m) {
			if (arr[i][j] != ans2[j]) {
				c++;
			}
		}
		if (c > 1) {
			o = 0;
			break;
		}
	}
	if (o) ans = ans2;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		a.clear ();
		arr.clear ();
		ans.clear ();

		cin >> n >> m;

		fr (i, 0, n) {
			string s;
			cin >> s;
			a.insert (s);
		}
		for (auto& i : a)
			arr.pb (i);
		n = len (a);

		solve ();
		if (o) {
			pr (ans);
			continue;
		}
		swap (arr[0], arr.back ());
		solve ();
		if (o) {
			pr (ans);
			continue;
		}
		pr (-1);
	}
	return 0;
}