#define sz 10000000
bool is_prime[sz+5];
vector<ll>primes;
map<ll,ll>mp;
void sieve()
{
    for(int i=3; i*i<=sz; i+=2)
    {
        if(is_prime[i]==0)
        {
            for(int j=i*i; j<=sz; j+=i) is_prime[j]=1;
        }
    }
    is_prime[1]=1;
    primes.pb(2);
    mp[2]=1;
    for(int i=3; i<=sz; i+=2) 
    {
        if(is_prime[i]==0) 
        {
            primes.pb(i);
            mp[i]=1;
        }
    }
}
