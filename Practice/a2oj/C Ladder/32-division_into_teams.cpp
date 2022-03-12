/*
				C++
				encoding: UTF-8
				Last Modified: 25/Sep/20 06:46:42 PM
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
	size_t n;
	cin >> n;
	vector< pair< int, int > > arr (n);
	int j = 1;
	for (auto& i : arr) {
		cin >> i.first;
		i.second = j++;
	}
	sort (arr.begin (), arr.end ());
	vector< int > a, b;
	bool flag = false;
	for (size_t i = 0; i < n; i++) {
		if (flag)
			a.push_back (arr[i].second);
		else
			b.push_back (arr[i].second);
		flag = !flag;
	}
	print (a.size ());
	for (auto& i : a)
		cout << i << ' ';
	cout << '\n';
	print (b.size ());
	for (auto& i : b)
		cout << i << ' ';
	return 0;
}