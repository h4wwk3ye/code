/*
				C++
				encoding: UTF-8
				Last Modified: 25/Mar/22 09:31:33 PM
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

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int d, n, m;
	while (cin >> d >> n >> m) {
		if (d == 0 and n == 0 and m == 0) break;
		vector< int > a (d), f (d);
		for (auto& i : a)
			cin >> i;
		for (auto& i : f)
			cin >> i;
		reverse (f.begin (), f.end ());

		/*
			a b c d . . .    fd      = f n+d
			1 0 0 0 . . .    fd-1    = f n+d-1
			0 1 0 0 . . .
			. . . . . . .    f1      = f n+1
			so only raise to the power of n - 1 to get fn at last postition
		*/

		mod = m;
		Mat A (d, d);
		Mat B (d, 1);
		for (int i = 0; i < d; ++i) {
			for (int j = 0; j < d; ++j) {
				if (i == 0) {
					// first row will be a
					A.a[i][j] = a[j];
				} else {
					if (i == j + 1) A.a[i][j] = 1;
				}
			}
			B.a[i][0] = f[i];
		}

		Mat An = A.pow (n - 1);
		Mat ans = An * B;
		print (ans.a[d - 1][0]);
	}
	return 0;
}