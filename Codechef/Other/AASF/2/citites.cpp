//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 21/Mar/20 03:43:27 PM
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

int n, t;
const int N = 1e3 + 5;
ve< int > arr[N];
int inf = 1e9;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> t;
	fr (i, 1, n + 1) {
		int s, x, y;
		cin >> s >> x >> y;
		arr[i] = {s, x, y, inf};
		if (s == 1) {
			arr[i][3] = 0;
		}
	}

	auto manhattan = [](int x1, int y1, int x2, int y2) -> int {
		return abs (x1 - x2) + abs (y1 - y2);
	};

	fr (i, 1, n + 1) {
		if (!arr[i][0]) {
			fr (j, 1, n + 1) {
				if (arr[j][0]) {
					int x = manhattan (arr[i][1], arr[i][2], arr[j][1], arr[j][2]);
					arr[i][3] = min (x, arr[i][3]);
				}
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans = manhattan (arr[a][1], arr[a][2], arr[b][1], arr[b][2]);

		ans = min (ans, t + arr[a][3] + arr[b][3]);

		pr (ans);
	}

	return 0;
}