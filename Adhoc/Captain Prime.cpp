#include <iostream>
#include<string>
#include<cstring>
using namespace std;
bool prime[1000000];
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.

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
}

int main() {
    memset(prime, true, sizeof(prime));
	SieveOfEratosthenes(1000000);
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		int fr=0,fl=0,fz=0;
		if(!prime[num])
		{
			printf("DEAD\n");
			continue;
		}
		int trnum=num,dig;
		trnum=trnum/10;
		while(trnum)
		{
			dig=trnum%10;
			if(dig==0)
			{
				fz=1;
				break;
			}
			if(!prime[trnum])
			{
				fr=1;
				break;
			}
			trnum=trnum/10;
		}
		if(fz==1)
		{
			printf("DEAD\n");
			continue;
		}
		int tlnum=num;
		string::size_type sz;
		string snum = to_string(tlnum);
		snum=snum.substr(1);
		tlnum = stoi(snum,&sz);
		while(tlnum)
		{
			if(snum.substr(0,1)=="0")
			{
				fz=1;
				break;
			}
			if(!prime[tlnum])
			{
				fl=1;
				break;
			}
			if(snum.length()>1)
			snum=snum.substr(1);
			else
			snum="0";
			tlnum = stoi(snum,&sz);

		}
		if(fz==1)
		{
			printf("DEAD\n");
			continue;
		}
		if(fr==0 && fl==0)
			printf("CENTRAL\n");
		else if(fr==0)
			printf("RIGHT\n");
		else
			printf("LEFT\n");
	}
	return 0;
}
