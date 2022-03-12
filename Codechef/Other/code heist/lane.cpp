//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jan/20 10:01:08 PM
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
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		int arr[n];
		fr (i, 0, n) cin >> arr[i];
		int k = 0, i = 0;
		ve< int > st;
		while (i < n) {
			while (st.size () && st.back () == k + 1)
				k++, st.pop_back ();
			if (arr[i] != k + 1)
				st.push_back (arr[i]);
			else
				k++;
			i++;
		}
		while (st.size () && st.back () == k + 1)
			k++, st.pop_back ();
		pr (k == n ? "yes" : "no");
	}

	return 0;
}