//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 31/Mar/20 09:11:35 PM
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
	int k;
	cin >> k;
	if (!k) {
		pr (1, 1);
		int x = 3e5;
		pr (x);
		return 0;
	}
	ve< ve< int > > arr (3, ve< int > (3, 0));
	arr[2][2] = arr[0][1] = arr[1][1] = k;

	int x = log2 (k) + 1;

	string s = "1";
	string t = "1";
	string p = "1";
	while (x--) {
		if ((k >> x) & 1)
			p += '1';
		else
			p += '0';
		s += '0';
		t += "1";
	}


	int y = stoll (s, nullptr, 2);
	int z = stoll (t, nullptr, 2);

	arr[0][0] = z;
	arr[1][0] = arr[2][0] = y;
	arr[2][1] = stoll (p, nullptr, 2);
	pr (3, 3);
	fr (i, 0, 3) {
		fr (j, 0, 3) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}