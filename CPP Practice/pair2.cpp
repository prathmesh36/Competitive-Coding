#include <iostream>
#include<utility>
using namespace std;

int main() {
	pair<int,string> p(5,"Prathamesh");
	cout<<p.first<<" "<<p.second<<endl;
	pair <int,string> p1=make_pair(4,"Mandar");
	cout<<p1.first<<" "<<p1.second<<endl;
	//cout<<get<0>(p1)<<" "<<get<1>(p1)<<endl;
	if(p>p1)
	{
		cout<<"Prathameshs Roll No is greater than Mandars\n";
	}
	else
	{
		cout<<"Mandars Roll No is greater than Prathmeshs";
	}
	
	swap(p,p1);
	
	if(p>p1)
	{
		cout<<"Prathameshs Roll No is greater than Mandars\n";
	}
	else
	{
		cout<<"Mandars Roll No is greater than Prathmeshs";
	}	
	return 0;
}