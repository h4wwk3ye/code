#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

ll x;
const ll N = 1e6 + 5;
ll mod = 1000000007;
ll dp ll staircase (ll n) {
	if (n < 0) { // Base Case 1
		return 0;
	}

	if (n == 0) { // Base Case 2
		return 1;
	}
	if () ll count = 0;
	count += staircase (n - 1);
	count %= mod;
	count += staircase (n - 2);
	count %= mod;
	if (n + 3 > x) count += staircase (n - 3);
	count %= mod;

	return count;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> x;
	pr1 (staircase (x));
	return 0;
}
