#define mod 998244353
ll binexp(ll b,ll p)
{
    if(p==0) return 1;
    ll res=binexp(b,p/2);
    if(p%2==0) return ((res%mod) * (res%mod)) %mod;
    else return ((res*res)%mod * (b%mod))%mod;
}
