#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
int arr[1000000];
int n;
void merge(int lo,int md,int hi)
{
    vector<int>v;
    int p=lo,q=md+1;
    while(p<=md && q<=hi)
    {
        if(arr[p]<=arr[q])
        {
            v.pb(arr[p]);
            p++;
        }
        else 
        {
            v.pb(arr[q]);
            q++;
        }
    }
    while(p<=md)
    {
        v.pb(arr[p]);
        p++;
    }
    while(q<=hi)
    {
        v.pb(arr[q]);
        q++;
    }
    for(int i=lo; i<=hi; i++)
    {
        arr[i]=v[i-lo];
    }
}
void merge_sort(int lo,int hi)
{
    if(lo==hi) return;
    int md=(lo+hi)/2;
    merge_sort(lo,md);
    merge_sort(md+1,hi);
    merge(lo,md,hi);
}
int main()
{
    fastio
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        merge_sort(0,n-1);
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}
