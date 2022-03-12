//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Jan/20 10:03:07 PM
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

int n;
const int N = 1e3 + 5;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		ve< pii > arr (n);
		fr (i, 0, n) {
			int x, y;
			cin >> x >> y;
			arr[i] = {x, y};
		}
		bool flag = 0;
		fr (i, 0, n) {
			int x = arr[i].ff, y = arr[i].ss;
			fr (j, 0, n) {
				int p = arr[j].ff, q = arr[j].ss;
				if (p > x and y > q) {
					flag = 1;
				}
			}
		}
		if (flag) {
			pr ("NO");
			continue;
		}
		sort (all (arr));
		ve< char > ans;
		pr ("YES");
		int x = 0, y = 0;
		for (auto& [p, q] : arr) {
			while (x != p) {
				ans.pb ('R');
				x++;
			}
			while (y != q) {
				ans.pb ('U');
				y++;
			}
		}
		for (auto& i : ans)
			cout << i;
		cout << "\n";
	}
	return 0;
}