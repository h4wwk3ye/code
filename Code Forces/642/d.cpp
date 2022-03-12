//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 14/May/20 08:54:59 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		map< int, set< pii >, greater<> > mp;
		mp[n].insert ({1, n});
		// mp.insert ({n, {1, n}});


		ve< int > arr (n + 1, 0);
		int i = 1;
		while (!mp.empty ()) {
			// pr (mp);
			auto it = mp.begin ();
			int x = it->ff;
			pii t = *(it->ss).begin ();
			int d = (t.ss + t.ff) / 2;

			auto itr = mp[x].begin ();
			mp[x].erase (itr);

			if (!len (mp[x])) mp.erase (it);

			arr[d] = i++;

			int l = d - 1 - t.ff + 1;
			if (l) mp[l].insert ({t.ff, d - 1});

			int r = t.ss - d;
			if (r) mp[r].insert ({d + 1, t.ss});
			// pr (mp);
			// pr (d, x, t, arr);
		}
		fr (i, 1, n + 1) cout << arr[i] << ' ';
		cout << '\n';
	}
	return 0;
}