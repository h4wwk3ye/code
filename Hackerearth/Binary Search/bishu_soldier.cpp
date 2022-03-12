/*
				C++
				encoding:UTF-8
				Modified: <01/Mar/2019 01:16:53 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll					    long long
#define		 mod			        1000000007
#define		 ve				        vector
#define		 pb				        push_back
#define		 umap			        unordered_map
#define		 endl			        "\n";
#define		 len(v)			        v.size()
#define		 reset(a, b)		    memset(a, b, sizeof(a));
#define		 sum(v)				    accumulate(v.begin(), v.end(), 0);
#define		 print1(x)		        cout<<x<<"\n";
#define		 print2(x, y)		    cout<<x<<" "<<y<<"\n";
#define		 printv(v)		        for (auto& ijk : v)  cout<<v<<" ";cout<<"\n";
#define		 fr(i,s, e, st)		    for (int i = s; i < e; i += st)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	int arr[n+1],prefix[n+1]={0};
	fr(i,1,n+1,1){
		cin>>arr[i];
		prefix[i]=prefix[i-1]+arr[i];
	}
	int q,m;
	cin>>q;
	while(q--){
		cin>>m;
		int low=1,high=n;
		while(low<high){
			int mid=(low+high)/2;
			if (arr[mid]>=m)
				high=mid;
			else
				low=mid+1;
		}
		print2(low,prefix[low]);
	}
	return 0;
}
