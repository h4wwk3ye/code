/*
				C++
				encoding:UTF-8
				Modified: <09/Mar/2019 10:31:23 AM>

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
    int n,s;
    cin>>n>>s;
    int arr[n+1];
    fr(i,1,n+1)
        cin>>arr[i];

    if (n==1){
        if (arr[1]+1<=s)
            pr2(1,arr[1]+1);
        else
            pr2(0,0);
        return 0;
    }
    ll ans=0;
    int low=0, high=n, mid;
    while (low<high){
        ll curr=0;
        mid=(low+high+1)/2;
        ll y[n+1];
        fr(i,1,n+1)
            y[i]=(ll)arr[i]+(ll)i*mid;
        sort(y+1,y+n+1);
        fr(i,1,mid+1){
            curr+=y[i];
            if (curr>s)
                break;
        }
        if (curr<=s)
            low=mid,ans=curr;
        else
            high=mid-1;
    }
    pr2(low,ans);
    return 0;
}
