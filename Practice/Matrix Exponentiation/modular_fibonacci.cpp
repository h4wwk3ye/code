/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/22 06:59:22 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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

int mod;

struct Mat {
	int n, m;
	vector< vector< int > > a;
	Mat () {
	}
	Mat (int _n, int _m) {
		n = _n;
		m = _m;
		a.assign (n, vector< int > (m, 0));
	}
	Mat (vector< vector< int > > v) {
		n = v.size ();
		m = n ? v[0].size () : 0;
		a = v;
	}
	inline void make_unit () {
		assert (n == m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				a[i][j] = i == j;
		}
	}
	inline Mat operator+ (const Mat& b) {
		assert (n == b.n && m == b.m);
		Mat ans = Mat (n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
			}
		}
		return ans;
	}
	inline Mat operator- (const Mat& b) {
		assert (n == b.n && m == b.m);
		Mat ans = Mat (n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
			}
		}
		return ans;
	}
	inline Mat operator* (const Mat& b) {
		assert (m == b.n);
		Mat ans = Mat (n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
				}
			}
		}
		return ans;
	}
	inline Mat pow (long long k) {
		assert (n == m);
		Mat ans (n, n), t = a;
		ans.make_unit ();
		while (k) {
			if (k & 1) ans = ans * t;
			t = t * t;
			k >>= 1;
		}
		return ans;
	}
	inline Mat& operator+= (const Mat& b) {
		return *this = (*this) + b;
	}
	inline Mat& operator-= (const Mat& b) {
		return *this = (*this) - b;
	}
	inline Mat& operator*= (const Mat& b) {
		return *this = (*this) * b;
	}
	inline bool operator== (const Mat& b) {
		return a == b.a;
	}
	inline bool operator!= (const Mat& b) {
		return a != b.a;
	}
};

int power (int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m;
	while (cin >> n >> m) {
		Mat a (2, 2);
		a.a[0][0] = 1, a.a[0][1] = 1, a.a[1][0] = 1, a.a[1][1] = 0;
		Mat b (2, 1);
		b.a[0][0] = 0, b.a[1][0] = 1;

		mod = power (2, m);

		Mat An = a.pow (n);

		Mat ans = An * b;
		print (ans.a[0][0]);
	}
	return 0;
}