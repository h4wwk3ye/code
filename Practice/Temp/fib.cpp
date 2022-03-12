/*
				C++
				encoding: UTF-8
				Last Modified: 11/Oct/20 05:40:49 PM
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

const int N = static_cast< int > (1e5 + 5);
array< int, N > arr;
int n;
vector< int > fib = {0, 1}, b;

void pre () {
	while (fib.back () <= 1e18) {
		size_t n = fib.size ();
		fib.push_back (fib[n - 1] + fib[n - 2]);
	}
}


int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	pre ();
	cin >> n;
	for (size_t i = 0; i < n; ++i)
		cin >> arr[i];

	for (size_t i = 0; i < n; i++) {
		size_t idx = lower_bound (fib.begin (), fib.end (), arr[i]) - fib.begin ();
		if (idx == fib.size ()) {
			b.push_back (idx - 1);
		} else {
			if (fib[idx] == arr[i]) {
				b.push_back (idx);
			} else {
				b.push_back (idx);
				if (idx) b.push_back (idx - 1);
			}
		}
	}
	vector< int > ans;
	for (auto& i : b) {
		auto it = lower_bound (ans.begin (), ans.end (), i);
		if (it == ans.end ())
			ans.push_back (i);
		else {
			*it = i;
		}
	}
	print (ans.size ());
	return 0;
}