/*
				C++
				encoding: UTF-8
				Modified: <16/Oct/2019 10:18:49 PM>

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

bool cmp (ve< int >& a, ve< int >& b) {
	if (a[0] == b[0] and a[1] == b[1]) {
		return a[2] < b[2];
	}
	if (a[0] == b[0]) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	ve< ve< int > > arr (n);
	fr (i, 0, n) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[i] = {x, y, z, i};
	}

	sort (all (arr), cmp);
	for (int i = 0; i < n; i += 2)
		pr (arr[i][3] + 1, arr[i + 1][3] + 1);

	return 0;
}
