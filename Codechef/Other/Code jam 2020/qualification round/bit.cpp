//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Apr/20 05:35:37 PM
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

const int N = 105;
int a[N], b, samePair, diffPair;

int query (int i) {
	cout << i + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

void findPair (int i) {
	a[i] = query (i);
	a[b - i - 1] = query (b - i - 1);
	if (samePair == -1 and a[i] == a[b - i - 1]) samePair = i;
	if (diffPair == -1 and a[i] != a[b - i - 1]) diffPair = i;
}

void findChange () {
	bool cmp = 0;
	if (samePair != -1 and a[samePair] != query (samePair)) cmp = 1;
	bool reverse = cmp;
	if (diffPair != -1 and a[diffPair] != query (diffPair)) reverse = !cmp;
	if (cmp) fr (i, 0, b) a[i] = 1 ^ a[i];
	if (reverse) fr (i, 0, b / 2) swap (a[i], a[b - i - 1]);
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc >> b;
	while (tc--) {
		samePair = -1;
		diffPair = -1;

		query (0);

		int c = 0;
		findChange ();
		while (c < 5) {
			findPair (c);
			c++;
		}

		while (c < b / 2) {
			int i = 0;
			for (i = 0; i < 4 and c < b / 2; ++i, ++c) {
				findPair (c);
			}
			if (i == 4) {
				findChange ();
			}
		}
		fr (i, 0, b) cout << a[i];
		cout << endl;
		char ans;
		cin >> ans;
		if (ans == 'N') exit (0);
	}
	return 0;
}