#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		float ans;
		//cout.setf(ios::fixed,ios::floatfield);
		//cout.precision(3);
		if(n==1)
		{
			printf("%.3f\n",0.000);
		}
		else
		{
			printf("%.3lf\n",((n*n)-(n-2)*(n-2)) +sqrt(2)*((n-2)*(n-2)));
		}
		cout<<endl;
	}
	return 0;
}
