/*
				C++
				encoding:UTF-8
				Modified: <04/Mar/2019 12:57:13 PM>

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
#define		 fr(i, s, e)				for (int i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}


int main() {
    //freopen("input.txt" , "r" , stdin) ;
    //ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int arr[n+1];
    fr(i,1,n+1)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    int q,m;
    cin>>q;
    while(q--){
        cin>>m;
        int low=1,high=n,mid;
        while (low<high){
            mid=(low+high+1)/2;
            if (arr[mid]<m)
                low=mid;
            else
                high=mid-1;
        }
        if (low==1){
            if (arr[1]<m)
                pr1(1);
            else
                pr1(0);
        }
        else{
            pr1(low);
        }
    }
    return 0;
}
