//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Feb/20 09:23:34 PM
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool flag = 0;

	fr (i, 0, n) {
		fr (j, i + 1, n) {
			fr (k, j + 1, n) {
				if (s[i] > s[j] and s[j] > s[k]) {
					flag = 1;
				}
			}
		}
	}
	if (flag) {
		pr ("NO");
		return 0;
	}

	ve< int > ans (n, -1);
	fr (i, 0, n) {
		if (ans[i] != -1) continue;
		ans[i] = 0;
		fr (j, i + 1, n) {
			if (s[j] < s[i]) {
				ans[j] = 1;
			}
		}
	}
	pr ("YES");
	for (auto& i : ans)
		cout << i;
	cout << endl;
	return 0;
}