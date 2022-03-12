//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 06/Jan/20 09:43:53 PM
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
	int n;
	cin >> n;
	int arr[n + 1];
	bool flag = 0;
	int x;
	fr (i, 1, n + 1) {
		cin >> arr[i];
		if (i == 1)
			x = arr[i];
		else {
			if (arr[i] != x) flag = 1;
		}
	}

	if (!flag) {
		if (n % 2 == 0) {
			pr ("Customer-B");
		} else {
			pr ("Customer-A");
		}
		return 0;
	}
	int cnt = 0;
	int i = n, j = n;
	while (arr[i] == arr[n]) {
		i--;
		cnt++;
	}

	auto check = [&]() -> pii {
		while (arr[i] == arr[j]) {
			i--;
			cnt++;
		}
		return {i, cnt};
	};

	auto A = []() { pr ("Customer-A"); };

	auto B = []() { pr ("Customer-B"); };

	while (i > 0) {
		pii x = check ();
		if (x.ss % 2 == 1) {
			A ();
			return 0;
		} else if (x.ff == 0) {
			B ();
			return 0;
		}
		j = i;
	}

	return 0;
}