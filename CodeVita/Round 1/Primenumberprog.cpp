#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
set<int> pnum;
vector <int> pnum2;
set <int> finall;

void SieveOfEratosthenes(int n,int m)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=n; p++)
    {
       if (prime[p])
          pnum.insert(p);
       if(p<=m && prime[p])
       	  pnum2.push_back(p);
    }
}

int main() {
	unsigned int i,j;
	int m,temp,count=0;
	cin>>m;
	if(m==0 || m==1 || m<0)
	{
		cout<<0;
	}
	else
	{
		SieveOfEratosthenes(7070,m);
		for(i=0;i<pnum2.size();i++)
		{
			for(j=0;j<pnum2.size();j++)
			{
				if((pnum2[j]/10)>0)
				{
					temp=pnum2[i]*100+pnum2[j];
				}
				else
				{
					temp=pnum2[i]*10+pnum2[j];
				}
				set<int>::iterator got = pnum.find(temp);
				if ( got != pnum.end() )
					finall.insert(temp);

			}
		}

			cout<<finall.size();
	}
	return 0;
}
