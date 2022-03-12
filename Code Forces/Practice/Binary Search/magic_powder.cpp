/*
				C++
				encoding:UTF-8
				Modified: <08/Mar/2019 06:29:48 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll					long long
#define		 mod					1000000007
#define		 ve					vector
#define		 pb					push_back
#define		 umap					unordered_map
#define		 pq					priority_queue
#define		 endl					"\n";
#define		 ff					first
#define		 ss					second
#define		 len(v)					int(v.size())
#define		 all(v)					v.begin(), v.end()
#define		 reset(a, b)				memset(a, b, sizeof(a));
#define		 sum(v)					accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)					cout<<x<<"\n"
#define		 pr2(x, y)				cout<<x<<" "<<y<<"\n"
#define		 prv(v)					for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, k, n)				for (int i = k ; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=1e5+5;
int A[N], B[N], C[N];


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin>>n>>k;
    fr(i,1,n+1)
        cin>>A[i];
    fr(i,1,n+1)
        cin>>B[i];

    ll low=0, high=2e9, mid;
    while (low<high){
        mid=(low+high+1)/2;
        ll cnt=0;
        fr(i,1,n+1){
            cnt+=max(0LL,(ll)A[i]*mid-B[i]);
            if (cnt>k)
                break;
        }
        if (cnt<=k)
            low=mid;
        else
            high=mid-1;
    }
    pr1(low);


    return 0;
}
