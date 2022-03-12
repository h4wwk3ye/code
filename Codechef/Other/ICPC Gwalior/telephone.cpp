//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Dec/19 07:43:56 PM
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

const int N = 105;
int arr[N][N], dp[N][N][N * N];
int n, K;

int solve (int I, int J, int k) {
	if (k > K) return 0;
	int& ans = dp[I][J][k];
	if (ans != -1) return ans;
	ans = 1e18;
	fr (i, 1, n + 1) {
		fr (j, 1, n + 1) {
			if (k == 1) {
				if (arr[i][j] == 1) {
					ans = solve (i, j, k + 1);
				}
			} else {
				if (arr[i][j] == k) {
					ans = min (ans, solve (i, j, k + 1) + (abs (I - i) + abs (J - j)));
				}
			}
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> K;
		fr (i, 1, n + 1) {
			fr (j, 1, n + 1) {
				cin >> arr[i][j];
				fr (k, 1, K + 1) {
					dp[i][j][k] = -1;
				}
			}
		}
		int ans = solve (1, 1, 1);
		pr (ans);
	}
	return 0;
}