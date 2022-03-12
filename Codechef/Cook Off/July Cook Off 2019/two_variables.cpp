/*
				C++
				encoding: UTF-8
				Modified: <21/Jul/2019 10:11:02 PM>

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

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

ve< ll > squares;

void pre () {
	fr (i, 0, 1e5 + 1) squares.pb (i * i);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	pre ();
	fr (i, 0, 10) cout << squares[i] << " ";
	return 0;
}
