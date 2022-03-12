/*
				C++
				encoding:UTF-8
				Modified: <30/Mar/2019 11:13:11 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int product (int x) {
	int prod = 1;
	while (x) {
		prod *= (x % 10);
		x /= 10;
	}
	return prod;
}

// This function returns the number having
// maximum product of the digits
int findNumber (int l, int r) {
	// Converting both integers to strings
	string a = to_string (l);
	string b = to_string (r);

	// Let the current answer be r
	int ans = r;
	for (int i = 0; i < b.size (); i++) {
		if (b[i] == '0') continue;

		// Stores the current number having
		// current digit one less than current
		// digit in b
		string curr = b;
		curr[i] = ((curr[i] - '0') - 1) + '0';

		// Replace all following digits with 9
		// to maximise the product
		for (int j = i + 1; j < curr.size (); j++)
			curr[j] = '9';

		// Convert string to number
		int num = 0;
		for (auto c : curr)
			num = num * 10 + (c - '0');

		// Check if it lies in range and its product
		// is greater than max product
		if (num >= l && product (ans) < product (num)) ans = num;
	}

	return ans;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	ll n;
	cin >> n;
	pr1 (product (findNumber (1, n)));
	return 0;
}
