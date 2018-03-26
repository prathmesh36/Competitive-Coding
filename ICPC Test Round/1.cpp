#include<iostream>
using namespace std;
int count=0;

void subArray(int arr[], int n)
{
	int sums=0,muls=1;

    for (int i=0; i <n; i++)
    {
        for (int j=i; j<n; j++)
        {

            for (int k=i; k<=j; k++)
	{
		sums=sums+arr[k];
		muls=muls*arr[k];
	}
            if(sums==muls)
            	count++;
            muls=1;
            sums=0;
        }
    }
}


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
    	count=0;
    	int n;
	cin>>n;
	int arr[100000];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	subArray(arr, n);
	cout<<count<<endl;
    }
    return 0;
}
