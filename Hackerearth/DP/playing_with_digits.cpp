/*
				C++
				encoding: UTF-8
				Modified: <06/Oct/2019 12:04:40 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 v.size()
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

int s, e, k;
int n;
string a, b;
const int k_limit = 1000;

int dp[11][100][k_limit][2][2];

bool isPrime (int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0) return false;

	return true;
}

int dig_sum (int x) {
	int s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int solve (int idx, int dig_sum, int mod_sum, int largerThanMin, int smallerthanMax) {
	if (idx == n) {
		if (isPrime (dig_sum) and mod_sum == 0) {
			return 1;
		}
		return 0;
	}

	int& ans = dp[idx][dig_sum][mod_sum][largerThanMin][smallerthanMax];
	if (ans != -1) return ans;
	ans = 0;
	fr (i, 0, 10) {
		if (!largerThanMin and i < a[idx] - '0') continue;
		if (!smallerthanMax and i > b[idx] - '0') continue;
		ans += solve (idx + 1,
					  dig_sum + i,
					  (10 * mod_sum + i) % k,
					  largerThanMin | (i > a[idx] - '0'),
					  smallerthanMax | (i < b[idx] - '0'));
	}
	return ans;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> s >> e >> k;

	if (k >= k_limit) {
		while (s % k)
			s++;
		int ans = 0;
		while (s <= e) {
			if (isPrime (dig_sum (s))) ans++;
			s += k;
		}
		pr (ans);
		return 0;
	}

	a = to_string (s);
	b = to_string (e);

	string tmp = "";
	int l = len (b) - len (a);
	while (l--) {
		tmp += "0";
	}
	a = tmp + a;
	n = len (b);
	reset (dp, -1);
	int ans = solve (0, 0, 0, 0, 0);
	pr (ans);
	return 0;
}
