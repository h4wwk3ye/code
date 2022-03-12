/*
				C++
				encoding: UTF-8
				Last Modified: 11/Aug/20 05:42:43 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, z;
		cin >> n >> z;
		priority_queue< int > pq;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			pq.push (x);
		}
		int ans = 0;
		while (z > 0 and pq.size ()) {
			int y = pq.top ();
			pq.pop ();
			z -= y;
			if (y / 2) pq.push (y / 2);
			++ans;
		}
		if (z > 0)
			print ("Evacuate");
		else
			print (ans);
	}
	return 0;
}