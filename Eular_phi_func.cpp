#define sz 1000000
int phi[sz+5];
void findPhi()
{
	for(int i=1; i<=sz; i++) phi[i]=i;
	for(int i=2; i<=sz; i++)
	{
		if(i==phi[i])
		{
			for(int j=i; j<=sz; j+=i)
			{
				phi[j]/=i;
				phi[j]*=(i-1);
			}
		}
	}
}
