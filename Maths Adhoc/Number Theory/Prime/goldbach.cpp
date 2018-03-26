#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> priv;
bool prime[1000005];
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

int main() {
	soe(1000000);
	int num;
	while(scanf("%d",&num),num)
	{
		vector<int>::iterator up;
		up= lower_bound (priv.begin(), priv.end(), num-2);
		int cprime=priv[up-priv.begin()-1];
		int cprime2=num-cprime;
		int i=2;
		while(!prime[cprime2])
		{
			cprime=priv[up-priv.begin()-i];
			cprime2=num-cprime;
			i++;
		}
		printf("%d = %d + %d\n",num,cprime2,cprime);
	}
	return 0;
}
