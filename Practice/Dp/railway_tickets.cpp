/*
				C++
				encoding: UTF-8
				Modified: <13/Aug/2019 02:55:35 PM>

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

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

int l1, l2, l3, c1, c2, c3;
int n;
int u, v;
const int N = 1e4 + 5;
int arr[N], dp[N];

int solve (int i) {
	if (i > v) return 1e9;
	if (i == v) return 0;
	if (dp[i] != 1e9) return dp[i];
	fr (j, i + 1, n + 1) {
		if (arr[j] - arr[i] <= l1) {
			dp[i] = min (dp[i], c1 + solve (j));
		} else if (arr[j] - arr[i] <= l2) {
			dp[i] = min (dp[i], c2 + solve (j));
		} else if (arr[j] - arr[i] <= l3) {
			dp[i] = min (dp[i], c3 + solve (j));
		} else
			break;
	}
	return dp[i];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	fill (dp, dp + N, 1e9);
	cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
	cin >> n;
	cin >> u >> v;
	if (u > v) swap (u, v);
	fr (i, 2, n + 1) {
		cin >> arr[i];
	}
	pr (solve (u));
	return 0;
}
