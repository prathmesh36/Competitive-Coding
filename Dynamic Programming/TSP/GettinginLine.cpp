#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
struct Coor
{
	int x;
	int y;
}a[13];
int p[13],a[13];
void solve()
{
	double clen=0xfffffff;
	do
	{
		double sum=0;
		for(int i=1;i<n;i++)
		{
			sum+=(sqrt(((a[p[i]].x-a[p[i-1]].x)*(a[p[i]].x-a[p[i-1]].x))+((a[p[i]].x-a[p[i-1]].x)*(a[p[i]].x-a[p[i-1]].x)))+16);
		}
		if(sum<clen)
		{
			clen=sum;
			for(int i=0;i<n;i++)
				a[i]=p[i];
		}

	}while(next_permutation(p,p+n));

	double tmp;
	for(int i=0;i<n;i++)
	{
		tmp=(sqrt(((a[p[i]].x-a[p[i-1]].x)*(a[p[i]].x-a[p[i-1]].x))+((a[p[i]].x-a[p[i-1]].x)*(a[p[i]].x-a[p[i-1]].x)))+16);
		printf("Cable requirement to connect (%d,%d) to (%d,%d) is %d feet.\n",a[p[i-1]].x,a[p[i-1]].y,a[p[i]].x,a[p[i]].y,tmp);
	}
	printf("Number of feet of cable required is %d.",clen);

}

int main() {
	int j=1;
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			p[i]=i;
		}
		printf("**********************************************************\n");
		printf("Network #%d\n",j);
		solve();
		j++;
	}
	return 0;
}
