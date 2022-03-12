/*
				C++
				encoding: UTF-8
				Modified: <15/Oct/2019 10:33:01 AM>

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

int n, m, c0, d0;
int arr[11][4];

int solve (int idx, int dough) {
	if (idx == m + 1) return 0;
	if (arr[idx][0] < arr[idx][1]) {
		return solve (idx + 1, dough);
	}
	if (dough < arr[idx][2]) {
		if (c0 <= arr[idx][1])
			return d0 + solve (idx + 1, dough);
		else
			return solve (idx + 1, dough);
	}
	return max (arr[idx][3] + solve (idx + 1, dough - arr[idx][2]),
				max (d0 + solve (idx + 1, dough), solve (idx + 1, dough)));
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> c0 >> d0;
	fr (i, 1, m + 1) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	int ans = solve (1, n);
	pr (ans);
	return 0;
}
