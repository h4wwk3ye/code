/*
				C++
				encoding:UTF-8
				Modified: <18/Mar/2019 12:17:45 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e6 + 5;
int n, b[N], dp[N];

int main ()
{
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n;
	int a;
	fr (i, 0, n)
	{
		cin >> a;
		cin >> b[a];
	}
	if (b[0] > 0) dp[0] = 1;

	int mx = 0;
	fr (i, 1, N)
	{
		if (b[i] == 0)
			dp[i] = dp[i - 1];
		else
		{
			if (b[i] >= i)
				dp[i] = 1;
			else
				dp[i] = dp[i - b[i] - 1] + 1;
		}
		mx = max (dp[i], mx);
	}
	pr1 (n - mx);

	return 0;
}
