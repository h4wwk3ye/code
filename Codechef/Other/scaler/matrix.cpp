//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 29/Mar/20 03:56:40 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m;
	cin >> n >> m;
	vector< vector< int > > arr (n + 1, vector< int > (m + 1, 0)),
	prefix_row (n + 1, vector< int > (m + 1, 0)), prefix_col (n + 1, vector< int > (m + 1, 0));
	fr (i, 1, n + 1) fr (j, 1, m + 1) cin >> arr[i][j];

	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			prefix_row[i][j] = prefix_row[i - 1][j] + arr[i][j];
		}
	}

	fr (j, 1, m + 1) {
		fr (i, 1, n + 1) {
			prefix_col[i][j] = prefix_col[i][j - 1] + arr[i][j];
		}
	}

	vector< vector< int > > pref (n + 1, vector< int > (m + 1, 0));
	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			pref[i][j] = pref[i - 1][j - 1] + prefix_row[i - 1][j] + prefix_col[i][j - 1] + arr[i][j];
		}
	}

	pr (pref);
	int B = 40;

	int low = 0, high = min (n, m);
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) >> 1;

		bool flag = 1;


		fr (i, 1, n + 1) {
			if (i + mid > n + 1) break;

			fr (j, 1, m + 1) {
				if (j + mid > m + 1) break;

				// from i, j to i + mid, j + mid

				int curr = pref[i + mid - 1][j + mid - 1] - pref[i - 1][j + mid - 1] -
						   pref[i + mid - 1][j - 1] + pref[i - 1][j - 1];

				if (curr > B) {
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	pr (ans);

	return 0;
}