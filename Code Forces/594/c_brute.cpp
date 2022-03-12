/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/2019 04:12:15 PM

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

int n, m;
ve< ve< int > > arr;

int solve (int i, int j, ve< ve< int > > c) {
	if (i == n and j == n) return 0;

	if (i + 1 < n and j + 1 < n) {
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	arr.resize (n, ve< int > (m, -1));
	ve< ve< int > > chk (n, ve< int > (m, 0));
	int ans = 0;
	ans += solve (0, 0, chk);
	return 0;
}
