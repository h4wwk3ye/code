//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Feb/20 03:04:40 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string a, b, c;

	auto check = [](string a, int f) -> void {
		for (auto& i : a) {
			if (i >= 'a' and i <= 'z') {
				f = 2;
				break;
			} else if (i == '.')
				f = 1;
		}
		if (f == 0)
			cout << "int";
		else if (f == 1)
			cout << "float";
		else
			cout << "string";
	};

	while (cin >> a >> b >> c) {
		check (a, 0);
		cout << " ";
		check (b, 0);
		cout << " ";
		check (c, 0);
		cout << "\n";
	}
	return 0;
}