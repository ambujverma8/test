#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        pair<ll,ll> lmax[n];
        pair<ll,ll> rmax[n];
        lmax[0].first=a[0];
        lmax[0].second=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>lmax[i-1].first)
            {
                lmax[i].first=a[i];
                lmax[i].second=i;
            }
            else
            {
                lmax[i].first=lmax[i-1].first;
                lmax[i].second=lmax[i-1].second;
            }
        }
        rmax[n-1].first=a[n-1];
        rmax[n-1].second=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] > rmax[i+1].first)
            {
                rmax[i].first=a[i];
                rmax[i].second=i;
            }
            else
            {
                rmax[i].first=rmax[i+1].first;
                rmax[i].second=rmax[i+1].second;
            }
        }
        ll ans=0;
        for(int i=1;i<n-1;i++)
        {
            ll tmp = min(lmax[i-1].first , rmax[i+1].first) *(abs(lmax[i-1].second - rmax[i+1].second) - 1);
            cout<<tmp<<" ";
            if(tmp>ans)
            ans=tmp;
        }
        cout<<ans<<endl;
    }
}
