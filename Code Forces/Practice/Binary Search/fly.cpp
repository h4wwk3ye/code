/*
				C++
				encoding:UTF-8
				Modified: <09/Mar/2019 04:41:09 PM>

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
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n+1], b[n+1];
    fr(i,1,n+1)
        cin>>a[i];
    fr(i,1,n+1)
        cin>>b[i];
    long double f;
    long double low=1, high=1e9+5, mid;
    cout.precision(7);
    int t=100;
    while (t--){
        mid=low + (high-low)/2;
        //cout<<fixed<<mid<<"\n";
        f=mid;
        fr(i,1,n+1){
            if(f<0)
                break;
            f-=(m+f)/a[i];
            if (f<0)
                break;
            f-=(m+f)/b[i];
        }
        if (f>=0)
            high=mid;
        else
            low=mid;
    }
    if (high<1e9+1)
        cout<<fixed<<high<<"\n";
    else
        pr1(-1);
    return 0;
}
