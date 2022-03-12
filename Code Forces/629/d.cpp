//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 26/Mar/20 09:49:50 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n];
		bool f = 1;
		fr (i, 0, n) {
			cin >> arr[i];
			if (i != 0) {
				if (arr[i] != arr[0]) f = 0;
			}
		}
		if (f) {
			pr (1);
			fr (i, 0, n) cout << 1 << " ";
			cout << '\n';
			continue;
		}
		if (n % 2 == 0) {
			pr (2);
			fr (i, 0, n) {
				if (i & 1)
					cout << 1 << " ";
				else
					cout << 2 << " ";
			}
			cout << '\n';
			continue;
		}
		int idx = -1;
		fr (i, 0, n) {
			if (arr[i] == arr[(i + 1) % n]) {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			pr (3);
			fr (i, 0, n - 1) {
				if (i & 1) {
					cout << 1 << " ";
				} else {
					cout << 2 << " ";
				}
			}
			cout << 3 << '\n';
			continue;
		}
		pr (2);
		ve< int > ans (n);
		int c = 1;
		fr (i, 0, n) {
			if (i == (idx + 1) % n and i != 0) {
				ans[i] = ans[idx];
				continue;
			} else if (i == n - 1 and idx == i) {
				ans[i] = ans[0];
				continue;
			}
			if (i & 1)
				ans[i] = c;
			else
				ans[i] = c;
			if (c == 1)
				c = 2;
			else
				c = 1;
		}

		for (auto& i : ans)
			cout << i << " ";
		cout << '\n';
	}
	return 0;
}