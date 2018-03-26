#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
 vector<int> v;
 bool prime[1000000];
void SieveOfEratosthenes(int n)
{

    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }


    for (int p=2; p<=n; p++)
       if (prime[p])
          v.push_back(p);
}

vector<int> primefactor(long long int n)
{
	vector<int> factors;
	long long int pfind=0,pf=v[pfind];
	while(pf*pf<=n)
	{
		while(n%pf==0)
		{
			factors.push_back(pf);
			n/=pf;
		}
		pf=v[++pfind];
	}
	if(n!=1)factors.push_back(n);
	return factors;
}

int sod(int num)
{
	int sum=0;
	while(num>0)
	{
		sum+=(num%10);
		num/=10;
	}
	return sum;
}

int main()
{
    SieveOfEratosthenes(1000000);
    int t,i;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	for(i=n+1;i<=1000000200;i++)
	{
		vector<int>pfs=primefactor(i);
		if(pfs.size()>1)
		{
		    	int nsum=sod(i);
			int pfsum=0;
			for(auto elem:pfs)

				pfsum+=sod(elem);
			if(pfsum==nsum)
			{
			printf("%d\n",i);
			break;
			}
		}
	}
    }
    return 0;
}
