#include <iostream>
#include<tuple>
using namespace std;
typedef tuple<int,string,float> footballer;
int main() {
	tuple<int,string,float> t(1,"Wayne Rooney",90.5);
	cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<endl;
	tuple<int,string,float> t1 = make_tuple(2,"Frank Lampard",89.5);
	cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)<<endl;
	if(t>t1)
	{
		cout<<"Wayne Rooney greater than Lampard\n";
	}
	else
	{
		cout<<"Frank Lampard greater than Rooney\n";
	}
	
	swap(t,t1);

	if(t>t1)
	{
		cout<<"Wayne Rooney greater than Lampard\n";
	}
	else
	{
		cout<<"Frank Lampard greater than Rooney\n";
	}	
	
	cout<<tuple_size<footballer>::value<<endl;
	//cout<<tuple_element<0,tuple<int,string,float>>::type<<endl;
	auto t2=tuple_cat(t,t1);
	cout<<get<1>(t2)<<" "<<get<4>(t2)<<endl;
	return 0;
}