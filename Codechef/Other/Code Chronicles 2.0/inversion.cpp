/*
				C++
				encoding: UTF-8
				Last Modified: 10/Aug/20 09:17:47 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>	 // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

#define int int64_t

typedef tree< int, null_type, less_equal< int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

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
	int n, q;
	cin >> n >> q;
	vector< int > arr (n), cnt (n);

	for (auto& i : arr)
		cin >> i;

	ordered_set X;
	map< int, int > mp;
	for (int i = 0; i < n; ++i) {
		int x = i - X.order_of_key (arr[i]);

		if (mp.find (arr[i]) != mp.end ()) {
			x -= mp[arr[i]];
		}

		cnt[i] = x;
		X.insert (arr[i]);
		mp[arr[i]]++;
	}
	for (int i = 1; i < n; ++i)
		cnt[i] += cnt[i - 1];

	// print (cnt);

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int ans = cnt[r];
		if (l) ans -= cnt[l - 1];
		print (ans);
	}

	return 0;
}