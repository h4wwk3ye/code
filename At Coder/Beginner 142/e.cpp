/*
				C++
				encoding: UTF-8
				Modified: <28/Sep/2019 07:07:48 PM>

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
#define         len(v)                 (v.size())
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

int n, m;
ve< ve< int > > arr;

const int N = 1e3 + 5;
ve< set< pair< set< int >, int > > > dp (N);

int solve (int i, set< int > s) {
	if (len (s) == n) return 0;
	if (i == m + 1) {
		return 1e18;
	}

	bool flag = 0;
	int ans = 1e18;
	for (auto c : dp[i]) {
		if (len (s) != 0 and c.ff == s) {
			ans = min (ans, c.ss);
		}
	}
	if (ans != 1e18) return ans;
	set< int > tmp;
	for (auto j : s) {
		tmp.insert (j);
	}

	fr (j, 1, len (arr[i])) {
		tmp.insert (arr[i][j]);
	}

	int b = solve (i + 1, s);
	int a = solve (i + 1, tmp) + arr[i][0];
	ans = min (a, b);

	dp[i].insert (make_pair (s, a));
	dp[i].insert (make_pair (tmp, b));
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	arr.resize (m + 1);
	set< int > chk;
	fr (i, 1, m + 1) {
		int a, b;
		cin >> a >> b;
		arr[i].resize (b + 1);
		arr[i][0] = a;
		fr (j, 1, b + 1) {
			cin >> arr[i][j];
			chk.insert (arr[i][j]);
		}
	}
	if (len (chk) != n) {
		pr (-1);
		return 0;
	}
	set< int > s;
	pr (solve (1, s));
	return 0;
}
