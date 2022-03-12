/*
				C++
				encoding: UTF-8
				Last Modified: 15/Sep/20 10:40:56 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	const int N = 1e3 + 5;
	vector< bool > prime (N, 1);
	prime[0] = prime[1] = 0;

	for (int i = 2; i < N; ++i) {
		if (prime[i]) {
			for (int j = 2 * i; j < N; j += i) {
				prime[j] = 0;
			}
		}
	}

	int a, b;
	cin >> a >> b;

	vector< int > p;
	for (int i = a; i <= b; ++i) {
		if (prime[i]) {
			p.push_back (i);
		}
	}

	int l = (a / 2) * (b / 2), r = a * b;
	for (int i = 0; i < (int)p.size (); ++i) {
		for (int j = i + 1; j < (int)p.size (); ++j) {
			int x = p[i] * p[j];
			if (x >= l and x <= r) {
				cout << p[i] << ',' << p[j] << '\n';
			}
		}
	}

	return 0;
}