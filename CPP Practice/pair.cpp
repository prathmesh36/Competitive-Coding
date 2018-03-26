#include <iostream>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;
pair<int,string>  g( pair<int,string>);

int main() {
	//declaring and accesing lements of pair
	pair<int,const char*> p(1,"Mandar");
	cout<<"Roll no: "<<p.first<<" is "<<p.second<<"\n";

	//usng tuple funcitons for pair
	cout<<tuple_size<pair<int,string>>::value<<"\n";
	//cout<<tuple_element<1,pair<int,string>>::type<<"\n";

	//passing pair to a function and return a pair
	pair<int,string> p1=g(p);
	cout<<"Modified and return pair is "<<p1.second<<"\n"; 

	//Storing tuple inside a pair
	tuple<int,float,string> t(1,91.48,"Mandar Mhapsekar");
	tuple<int,float,string> t2(2,89.65,"Prathmesh Mhapsekar");
	pair<int,tuple<int,float,string>> p3(2,t);
	cout<<"Pair:"<<p3.first<<"\n";

	//Displaying tuple elements inside a pair
	pair<tuple<int,float,string>,tuple<int,float,string>> p4(piecewise_construct,t,t2);
	tuple<int,float,string> t3= p4.first;
	cout<<"Tuple ELement: "<<get<2>(t3)<<"\n";

	//Using Ref and make_pair
	int i=10;
	auto p5 =make_pair(ref(i),ref(i)); //ref() and move() only works with auto
	//pair<int&,int&> p5(i,i);         //Instead of ref() and move() we can use reference operator
	cout<<"Before Mod: "<<p5.first<<" "<<p5.second<<"\n";
	p5.first=p5.first+5;
	cout<<"After Mod: "<<p5.first<<" "<<p5.second<<"\n";

	//fucntions of pair
	pair<int,const char*> p2(2,"Prathmesh");
	swap(p,p2);
	cout<<"After Swapping p is "<<p.second<<"\n";
	if(p>p2)
	{
		cout<<"p is greater than p2"<<"\n";
	}
	p.first=1;
	if(p>p2)
	{
		cout<<"p is greater than p2"<<"\n";
	}

	return 0;

}

//implicit type conversion of pair
pair<int,string> g( pair<int,string> temp )
{
	cout<<temp.second<<" is Inside the function"<<"\n";
	temp.second="Mandar Mhapsekar";
	return temp;
}
