/*
				C++
				encoding: UTF-8
				Last Modified: 25/Jul/20 02:00:25 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

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
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; ++T) {
		cout << "Case #" << T << ":\n";
		int n;
		cin >> n;
		vector< bool > incoming (n, 0), outgoing (n, 0);

		string in;
		cin >> in;
		for (int i = 0; i < n; ++i) {
			if (in[i] == 'Y') incoming[i] = 1;
		}

		string out;
		cin >> out;
		for (int i = 0; i < n; ++i) {
			if (out[i] == 'Y') outgoing[i] = 1;
		}

		for (int i = 0; i < n; ++i) {
			vector< bool > ans (n, 0);
			ans[i] = 1;
			// try going left
			for (int j = i - 1; j >= 0; --j) {
				if (incoming[j] and outgoing[j + 1])
					ans[j] = 1;
				else
					break;
			}
			// now go right
			for (int j = i + 1; j < n; ++j) {
				if (incoming[j] and outgoing[j - 1])
					ans[j] = 1;
				else
					break;
			}

			for (auto c : ans) {
				cout << (c ? 'Y' : 'N');
			}
			cout << '\n';
		}
	}


	return 0;
}