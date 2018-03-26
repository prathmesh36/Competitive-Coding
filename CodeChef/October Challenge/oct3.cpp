#include <iostream>
#include<vector>
using namespace std;


int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
		unsigned int b=4294967295;
		int n;
		cin>>n;
		int a=b%(n-1),c=b/(n-1);
		cout<<1<<" ";
		for(int i=0;i<n-2;i++)
		cout<<c<<" ";

		cout<<c+a<<endl;
	}
	return 0;
}
