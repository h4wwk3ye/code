//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 05/Jan/20 05:26:55 PM
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
#define		endl                   "\n"
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
int x, y;

void matmult (long long a[][2], long long b[][2], long long c[][2], long long M) // multiply matrix a and b. put result in c
{
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			c[i][j] = 0;
			for (k = 0; k < 2; k++) {
				c[i][j] += (a[i][k] * b[k][j]);
				c[i][j] = c[i][j] % M;
			}
		}
	}
}
void matpow (long long Z[][2], int n, long long ans[][2], long long M)
// find ( Z^n )% M and return result in ans
{
	long long temp[2][2];
	// assign ans= the identity matrix
	ans[0][0] = x;
	ans[1][0] = 0;
	ans[0][1] = y;
	ans[1][1] = 1;
	int i, j;
	while (n > 0) {
		if (n & 1) {
			matmult (ans, Z, temp, M);
			for (i = 0; i < 2; i++)
				for (j = 0; j < 2; j++)
					ans[i][j] = temp[i][j];
		}
		matmult (Z, Z, temp, M);
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
				Z[i][j] = temp[i][j];


		n = n / 2;
	}
	return;
}
long long findFibonacci (long long n, long long M) {
	long long fib;
	if (n > 2) {
		long long Z[2][2] = {{x, y}, {1, 0}},
				  result[2][2]; // modify matrix a[][] for other recurrence relations
		matpow (Z, n - 2, result, M);
		fib = result[0][0] * 1 + result[0][1] * 0; // final multiplication of Z^(n-2) with the initial terms of the series
	} else
		fib = n - 1;

	return fib;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n >> x >> y;
	int mod = 1e9 + 7;
	pr (findFibonacci (n, mod));


	return 0;
}