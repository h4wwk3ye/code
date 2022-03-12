/*
				C++
				encoding:UTF-8
				Modified: <10/Apr/2019 03:16:24 PM>

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
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

#include <bits/stdc++.h>
using namespace std;

// dp[i][j] is going to store true if sum j is
// possible with array elements from 0 to i.
bool** dp;

bool check (int n, int sum) {
	return dp[n - 1][sum];
}

void display (const vector< int >& v) {
	pr1 (len (v));
}

void printSubsetsRec (int arr[], int i, int sum, vector< int >& p) {
	if (i == 0 && sum != 0 && dp[0][sum]) {
		p.push_back (arr[i]);
		display (p);
		return;
	}


	if (i == 0 && sum == 0) {
		display (p);
		return;
	}

	if (dp[i - 1][sum]) {
		vector< int > b = p;
		printSubsetsRec (arr, i - 1, sum, b);
	}

	if (sum >= arr[i] && dp[i - 1][sum - arr[i]]) {
		p.push_back (arr[i]);
		printSubsetsRec (arr, i - 1, sum - arr[i], p);
	}
}

void printAllSubsets (int arr[], int n, int sum) {
	if (n == 0 || sum < 0) return;
	dp = new bool*[n];
	for (int i = 0; i < n; ++i) {
		dp[i] = new bool[sum + 1];
		dp[i][0] = true;
	}

	if (arr[0] <= sum) dp[0][arr[0]] = true;

	for (int i = 1; i < n; ++i)
		for (int j = 0; j < sum + 1; ++j)
			dp[i][j] = (arr[i] <= j) ? dp[i - 1][j] || dp[i - 1][j - arr[i]] : dp[i - 1][j];
}

void print (int arr[], int n, int curr) {
	if (!check (n, curr)) {
		pr1 ("NOT");
		return;
	}
	vector< int > p;
	printSubsetsRec (arr, n - 1, curr, p);
}

int main () {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n];
		int total = 0;
		fr (i, 0, n) {
			cin >> arr[i];
			total += arr[i];
		}
		printAllSubsets (arr, n, total);
		fr (i, 1, n) {
			cout << i << "here" << endl;
			fr (j, 0, total) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		fr (i, 0, total + 1) {
			pr1 (i);
			print (arr, n, i);
		}
	}
	return 0;
}
