/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/22 06:45:59 PM
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

const int mod = 1e9 + 7;

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

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	Mat a (n, n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		a.a[u][v] = 1;
	}
	Mat ans = a.pow (k);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum += ans.a[i][j];
			sum %= mod;
		}
	}
	print (sum);
	return 0;
}