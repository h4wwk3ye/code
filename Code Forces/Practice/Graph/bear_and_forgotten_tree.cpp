/*
				C++
				encoding:UTF-8
				Modified: <18/Mar/2019 07:39:28 PM>

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

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int n, d, h;
	cin >> n >> d >> h;

	if (n == 2) {
		if (h != 1 or d != 1) {
			pr1 (-1);
			return 0;
		}
		pr2 (1, 2);
		return 0;
	}

	if (d == 1 or d > 2 * h) {
		pr1 (-1);
		return 0;
	}

	ve< int > graph[n + 1];
	int i;
	for (i = 2; i < h + 2; i++) graph[i - 1].pb (i);

	int curr = 1;
	for (; i < d + 2; i++) {
		graph[curr].pb (i);
		curr = i;
	}

	if (d == h)
		curr = 2;
	else
		curr = 1;

	while (i <= n) {
		graph[curr].pb (i);
		i++;
	}
	fr (i, 1, n + 1) {
		for (int j : graph[i]) pr2 (i, j);
	}


	return 0;
}
