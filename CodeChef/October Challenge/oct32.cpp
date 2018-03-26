#include<iostream>
using namespace std;
int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
		unsigned int b=4294967294;
		int n;
		cin>>n;
		int a=b%(n-1),c=b/(n-1);
		cout<<1<<" ";
		for(int i=0;i<n-2;i++)
        {
            if(a>0)
            {
                cout<<c+1<<" ";
                a--;
            }
            else
            {
                cout<<c<<" ";
            }
        }
        cout<<c-1<<endl;
	}
	return 0;
}
