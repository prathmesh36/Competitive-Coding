#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
bool prime[1000005];
vector<int> priv;
void soe(int n)
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
          priv.push_back(p);
}
int main()
{
	long long int l,u;
	soe(100000);
	while(cin>>l>>u)
	{
		vector<long long int> lp;
		if(l==1)
		l=2;
		for(long long int i=l;i<=u;i++)
		{
			int flag=0;
			for(int j=0;j<priv.size();j++)
			{
				if(priv[j]>sqrt(i))
				{
				break;
				}
				if(i%priv[j]==0)
				{
				flag=1;
				break;
				}
			}
			if(flag==0)
			lp.push_back(i);
		}
		int min=1000000,minl=0;
		int max=0,maxl=0;

		if(lp.size()>=2)
		{
		for(long long int i=0;i<=lp.size()-2;i++)
		{
			if(lp[i+1]-lp[i]<min)
			{
				min=lp[i+1]-lp[i];
				minl=i;
			}
			if(lp[i+1]-lp[i]>max)
			{
				max=lp[i+1]-lp[i];
				maxl=i;
			}
		}

		cout<<lp[minl]<<","<<lp[minl+1]<<" are closest, ";
		cout<<lp[maxl]<<","<<lp[maxl+1]<<" are most distant.\n";
		}
		else
		{
		cout<<"There are no adjacent primes.\n";
		}
	}
	return 0;
}
