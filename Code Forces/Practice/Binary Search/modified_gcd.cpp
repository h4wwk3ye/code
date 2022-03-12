/*
				C++
				encoding:UTF-8
				Modified: <27/Mar/2019 06:59:54 PM>

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
#define		 prv(v, s, n)           for (int i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int main () {
	chrono::time_point< chrono::high_resolution_clock > start, end;
	start = chrono::high_resolution_clock::now ();
	ios_base::sync_with_stdio (false), cin.tie (0);
	int a, b;
	cin >> a >> b;
	ve< int > divisors;
	fr (i, 1, a + 1) {
		if (a % i == 0 and b % i == 0) divisors.pb (i);
	}
	end = chrono::high_resolution_clock::now ();
	ll elapsed_time = chrono::duration_cast< chrono::milliseconds > (end - start).count ();
	cout << "\nElapsed Time: " << elapsed_time << "ms\n";
	return 0;
}
