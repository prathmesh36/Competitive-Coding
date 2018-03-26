#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int r,n,i=1;
	while(scanf("%d %d",&r,&n),r && n)
	{
		int ans=ceil((r-n)*(1.0)/n);

		if(ans>26)
		{
			printf("Case %d: impossible\n",i);

		}
		else
		{
			printf("Case %d: %d\n",i,ans);
		}
		i++;
	}
	return 0;
}
