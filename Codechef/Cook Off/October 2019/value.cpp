/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/2019 11:41:02 PM
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		 int                    long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 (int)v.size()
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int mod = 987654319;
const int N = 3005;
int arr[N];
int dp[N][8][3][N];
int n;

int solve (int i, int j, int f, int p) {
	if (i > n) return 0;
	if (j == 7) return 1;

	int& ans = dp[i][j][f][p];
	if (ans != -1) return ans;
	ans = 0;

	ans += solve (i + 1, j, f, p);
	ans %= mod;

	fr (k, i + 1, n + 1) {
		if (f == 0) {
			if (arr[k] < arr[i] and arr[k] < arr[p]) {
				ans += solve (k, j + 1, 1, i);
				ans %= mod;
			}
		} else if (f == 1) {
			if (arr[k] > arr[i] and arr[k] < arr[p]) {
				ans += solve (k, j + 1, 2, i);
				ans %= mod;
			}
		} else {
			if (arr[k] < arr[i] and arr[k] < arr[p]) {
				ans += solve (k, j + 1, 0, i);
				ans %= mod;
			}
		}
	}
	ans %= mod;
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	reset (dp, -1);
	arr[0] = 1e18;
	int ans = solve (1, 1, 0, 0);
	ans %= mod;
	pr (ans);
	return 0;
}
