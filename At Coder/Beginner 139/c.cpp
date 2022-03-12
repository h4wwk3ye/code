/*
				C++
				encoding: UTF-8
				Last Modified: 2019/09/01 17:47:50

*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];
	ve< int > chk (n, 0);
	int ans = 0;
	fr (i, 1, n) {
		if (arr[i] <= arr[i - 1]) chk[i] = 1 + chk[i - 1];
		ans = max (ans, chk[i]);
	}
	pr (ans);
	return 0;
}
