#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,mid,check,low,high;
    cin>>n>>m;
    long double a_arr[n],b_arr[n],prod_arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>a_arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b_arr[i];

    }
    for(int i=0;i<n;i++)
    {
        prod_arr[i]=a_arr[i]*b_arr[i];
    }
    low=0;
    high=pow(10,18);
    while(low<high)
    {
        mid=(low+high)/2;
        check=0;
        for (int i=0;i<n;i++)
        {
            if(mid<prod_arr[i])
            {
                check+=ceil((prod_arr[i]-mid)/b_arr[i]);
            }
        }
        if (check>m)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    cout<<(low+high)/2<<endl;
    return 0;
}
