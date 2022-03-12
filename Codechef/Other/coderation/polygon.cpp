/*
				C++
				encoding:UTF-8
				Modified: <09/Apr/2019 05:51:07 PM>

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
#define		 pii                    pair<ll, ll>
#define		 len(v)                 ll(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (ll i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const ll N = 1e3 + 5;
ll n, m, k;
ll matrix[N][N];
ll ft, fl, fb, fr;

ll kadane (ll* arr, ll* start, ll* finish, ll n) {
	ll sum = 0, maxSum = INT_MIN, i;

	*finish = -1;

	ll local_start = 0;

	for (i = 0; i < n; ++i) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
			local_start = i + 1;
		} else if (sum > maxSum) {
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if (*finish != -1) return maxSum;

	maxSum = arr[0];
	*start = *finish = 0;

	for (i = 1; i < n; i++) {
		if (arr[i] > maxSum) {
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

void findMaxSum () {
	// Variables to store the final output
	ll maxSum = INT_MIN;

	ll left, right, i;
	ll temp[n], sum, start, finish;

	for (left = 0; left < m; ++left) {
		memset (temp, 0, sizeof (temp));
		for (right = left; right < m; ++right) {
			for (i = 0; i < n; ++i)
				temp[i] += matrix[i][right];

			sum = kadane (temp, &start, &finish, n);

			if (sum > maxSum) {
				maxSum = sum;
				fl = left;
				fr = right;
				ft = start;
				fb = finish;
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m >> k;
	fr (i, 0, n) fr (j, 0, m) cin >> matrix[i][j];
	findMaxSum ();
	// cout << ft << " " << fl << " " << fb << " " << fr << endl;
	pr1 ((fr - fl + 1) * (fb - ft + 1));
	fr (i, ft, fb + 1) {
		fr (j, fl, fr + 1) {
			pr2 (i + 1, j + 1);
		}
	}
	return 0;
}
