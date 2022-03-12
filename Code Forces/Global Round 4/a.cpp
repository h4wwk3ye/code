/*
				C++
				encoding: UTF-8
				Modified: <20/Jul/2019 11:40:34 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int x;
	cin >> x;
	ve< int > y;
	y.pb (1);
	int z, t = x, t1 = x;
	fr (i, 2, n + 1) {
		cin >> z;
		t += z;
		if (z <= x / 2) {
			y.pb (i);
			t1 += z;
		}
	}
	if (t1 > t / 2) {
		print (len (y));
		for (auto i : y)
			cout << i << " ";
		cout << endl;
	} else {
		print (0);
	}
	return 0;
}
