/*
				C++
				encoding: UTF-8
				Last Modified: 01/Nov/20 05:41:39 PM
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
	cout << t << ' ';
	print (u, args...);
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	vector< pair< int, int > > arr (n);
	for (auto& [a, b] : arr)
		cin >> a >> b;
	bool ans = false;
	for (auto i = 0; i < n; ++i) {
		auto [x1, y1] = arr[i];
		for (auto j = 0; j < n; ++j) {
			if (i == j) continue;
			auto [x2, y2] = arr[j];
			for (auto k = 0; k < n; ++k) {
				if (k == i or k == j) continue;
				auto [x3, y3] = arr[k];

				int num1 = y2 - y1, den1 = x2 - x1;
				int num2 = y3 - y1, den2 = x3 - x1;

				int g1 = __gcd (num1, den1);
				num1 /= g1;
				den1 /= g1;
				int g2 = __gcd (num2, den2);
				num2 /= g2;
				den2 /= g2;

				if (num1 == num2 and den1 == den2) {
					ans = true;
				}
			}
		}
	}
	print (ans ? "Yes" : "No");
	return 0;
}