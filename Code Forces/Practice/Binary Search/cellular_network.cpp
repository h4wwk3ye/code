/*
				C++
				encoding:UTF-8
				Modified: <10/Mar/2019 06:06:05 PM>

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


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    int a[n];
    fr(i,0,n)
        cin>>a[i];
    int b[m];
    fr(i,0,m)
        cin>>b[i];
    ll low=0, high=2e9+5, mid;
    while (low<high){
        mid=low+(high-low)/2;
        int j=0;
        fr(i,0,m){
            while (j<n){
                if (abs(b[i]-a[j]) > mid)
                    break;
                j++;
            }
        }
        if (j==n)
            high=mid;
        else
            low=mid+1;
    }
    pr1(low);
    return 0;
}
