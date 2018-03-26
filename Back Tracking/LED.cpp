#include <iostream>
#include<string>
using namespace std;
#define maxN 11
#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
int n, light[maxN];
const int num[] = { 126, 48, 109, 121, 51, 91, 95, 112, 127, 123 };

int main() {
	while(scanf("%d",&n) && n)
	{
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			light[i]=0;
			for(int j=0;j<7;j++)
			{
				light[i]<<=1;
				if(s[j]=='Y')light[i]|=1;
			}
		}
		bool ok = false;
		for(int start=9; start>=n-1 && !ok;start--)
		{
			int activeLED=BIT(7)-1;
			bool check=true;
			for(int i=start,j=0;j<n && check;i--,j++)
			{
				if(AND(activeLED,light[j])!=light[j]) check=false;
				if(AND(num[i],light[j])!=light[j]) check=false;
				int dieLED = AND(num[i],~light[j]);
				activeLED &= ~dieLED;
			}
			ok=check;
		}
		if(!ok)printf("MIS");
		puts("MATCH");
	}
	return 0;
}
