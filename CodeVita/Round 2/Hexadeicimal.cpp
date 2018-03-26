#include <iostream>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;
string ithex( int i )
{
  stringstream stream;
  stream << hex << i;
  return stream.str();
}
int main() {
	int num;
	cin>>num;
	int flag=0;
	string hexa = ithex(num*2);
	int i=3;
	while(hexa.length()<=7)
	{
		int count=0;
		for(unsigned int j=1;j<hexa.length();j++)
		{
		  if(hexa[j]!=hexa[j-1])
		  {
		  	count++;
		  }
		  if(count==2)
		  {
		  	break;
		  }
		}
		if(count<2)
		{
			locale loc;		
			for (string::size_type k=0; k<hexa.length(); ++k)
			    cout <<toupper(hexa[k],loc);	
			cout<<"\n";    
			flag=1;
			break;
		}
		hexa=ithex(num*i);
		i++;
	}
	if(flag==0)
	{
		cout<<"NOTFOUND\n";
	}
	return 0;
}