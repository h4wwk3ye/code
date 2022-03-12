/*
				C++
				encoding: UTF-8
				Last Modified: 29/Aug/20 06:21:23 PM
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

const int MAXN = 1e6 + 5;
bool prime[MAXN];
set< int > indexes[MAXN];

int spf[MAXN];
bool flag = 0;

void sieve () {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)
		spf[i] = i;

	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAXN; j += i)
				if (spf[j] == j) spf[j] = i;
		}
	}
}

void factorize (int n, int idx) {
	while (n != 1) {
		indexes[spf[n]].insert (idx);
		if (indexes[spf[n]].size () > 1) {
			flag = 1;
			break;
		}
		n = n / spf[n];
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	vector< int > arr (n);
	int g = 0;

	sieve ();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		g = __gcd (arr[i], g);
		if (!flag) factorize (arr[i], i);
	}

	if (flag) {
		if (g == 1)
			print ("setwise coprime");
		else
			print ("not coprime");
	} else {
		print ("pairwise coprime");
	}

	return 0;
}