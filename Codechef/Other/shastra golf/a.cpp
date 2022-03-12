//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 20/Jan/20 08:12:25 PM
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
	ve< int > arr = {7,	17,   19,   23,   29,   47,   59,   61,   97,   109,  113,  131,
					 149,  167,  179,  181,  193,  223,  229,  233,  257,  263,  269,  313,
					 337,  367,  379,  383,  389,  419,  433,  461,  487,  491,  499,  503,
					 509,  541,  571,  577,  593,  619,  647,  659,  701,  709,  727,  743,
					 811,  821,  823,  857,  863,  887,  937,  941,  953,  971,  977,  983,
					 1019, 1021, 1033, 1051, 1063, 1069, 1087, 1091, 1097, 1103, 1109, 1153,
					 1171, 1181, 1193, 1217, 1223, 1229, 1259, 1291, 1297, 1301, 1303, 1327,
					 1367, 1381, 1429, 1433, 1447, 1487, 1531, 1543, 1549, 1553, 1567, 1571,
					 1579, 1583, 1607, 1619, 1621, 1663, 1697, 1709, 1741, 1777, 1783, 1789,
					 1811, 1823, 1847, 1861, 1873, 1913, 1949, 1979, 2017, 2029, 2063};

	int m, n;
	cin >> m >> n;
	for (auto& i : arr) {
		if (i >= m and i <= n) cout << i << " ";
	}
	cout << endl;
	return 0;
}