#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n,q,k;
    cin>>n>>q>>k;
    vector<ll> arr(n);

    for(ll i=0; i<n; i++)
        cin>>arr[i];

    deque<ll> que;
    ll count=1;
    for(ll i=0; i<n-1; i++)
    {
        if(arr[i] == arr[i+1])
            count++;
        else
        {
            que.push_back(count);
            count=1;
        }
    }

    que.push_back(count);
    multiset<ll,greater<ll> > m;    // maximum value will always be at top
    ll total=0;
    deque<ll>::iterator it;
    for(it=que.begin();it!=que.end();it++)
    {
        total+=(*it);
        if(arr[total-1]==1)
            m.insert(*it);
    }
    //m.insert(0);
    ll maximum=*(m.begin()),rotation=0,l=0,r=0;
    char query;
    for(ll i=0; i<q; i++)
    {
        cin>>query;

        if (query=='!')
        {

            ll first_element=arr[(n-rotation+100000*n)%n];   // 100000 to prevent negative values
            ll last_element=arr[(n-1-rotation+100000*n)%n];
            if(first_element==1 && last_element==1)
            {
                it=que.begin();
                l=*it;
                m.erase(m.find(l));
                m.insert(l+1);
                (*it)++;
                it=que.end();
                it--;
                r=*it;
                m.erase(m.find(r));
                if(r!=1)
                    m.insert(r-1);
                (*it)--;

                maximum=*m.begin();
                if(r<=1)
                    que.pop_back();

            }
            else if(first_element==1 && last_element==0)
            {
                it=que.end();
                it--;
                que.push_front(1);
                (*it)--;
                if((*it)<=0)
                    que.pop_back();
                maximum=*m.begin();

            }
            else if(first_element==0 && last_element==1)
            {
                it=que.end();
                it--;
                m.erase(m.find(*it));
                if(*it!=1)
                    m.insert(*it-1);
                que.push_front(1);
                (*it)--;
                if((*it)<=0)
                    que.pop_back();
                m.insert(1);
                maximum=*m.begin();

            }

            else if(first_element==0 && last_element==0)
            {
                it=que.begin();
                (*it)++;
                it=que.end();
                it--;
                (*it)--;
                if((*it)<=0)
                    que.pop_back();
                maximum=*m.begin();
            }


                rotation++;
        }
        else if(query=='?')
        {
            cout<<min(k,maximum)<<"\n";
        }
     }
     return 0;
}
