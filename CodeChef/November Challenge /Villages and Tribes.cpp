#include<iostream>
#include<string.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int a=0,b=0,ta=0,tb=0,fa=0,fb=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='A')
			{
				a++;
				if(fa==1)
				{
				a+=ta;
				}
				ta=0;
				tb=0;
				fb=0;
				fa=1;
			}
			if(s[i]=='B')
			{
				b++;
				if(fb==1)
				{
				b+=tb;
				}
				ta=0;
				tb=0;
				fb=1;
				fa=0;
			}
			if(s[i]=='.')
			{
				if(fa==1)
				ta++;
				if(fb==1)
				tb++;
			}
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
