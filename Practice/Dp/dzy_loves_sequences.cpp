/*
				C++
				encoding: UTF-8
				Modified: <15/Oct/2019 07:05:22 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 (int)v.size()
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 5e5 + 5;
int arr[N], dp[N][2];
int n;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) {
		cin >> arr[i];
	}

	int c1 = 1, c2 = 0, mx = 0;
	fr (i, 1, n + 1) {
		if (arr[i] > arr[i - 1]) {
			dp[i][0] = c1;
			c1++;
		} else {
			dp[i][1] = max (dp[i - 1][0] + 1, c1);
			c1 = 1;
		}
	}
	fr (i, 1, n + 1) cout << dp[i][0] << " ";
	cout << endl;
	fr (i, 1, n + 1) cout << dp[i][1] << " ";
	cout << endl;
	return 0;
}
