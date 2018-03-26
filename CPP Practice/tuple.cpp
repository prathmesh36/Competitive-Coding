#include <iostream>
#include <tuple>
#include <utility>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	//create tuple
	tuple<int,string,float> t1(1,"Mandar Mhapsekar",91.48);
	tuple<int,string,float> t2(2,"Prathmesh Mhapsekar",89.65);

	//displaying elements in the tuple
	cout<<"Roll No: "<<get<0>(t1)<<" Name: "<<get<1>(t1)<<" Marks: "<<get<0>(t1)<<"\n";
	cout<<"Roll No: "<<get<0>(t2)<<" Name: "<<get<1>(t2)<<" Marks: "<<get<0>(t2)<<"\n";

	//creating tuple using make_pair
	auto t3=make_tuple(3,"John Smith",87.90);

	//comparison between tuples
	if(t1>t3)
		cout<<"t1 is greater than t3"<<"\n";
	else
		cout<<"t3 is greater than t1"<<"\n";

	//referencing in the tuple using ref
	int i;
	string s;
	float j;
	auto t4=make_tuple(ref(i),ref(s),ref(j));
	get<0>(t4)=4;
	get<1>(t4)="Tim Cook";
	get<2>(t4)=85.50;
	cout<<"Roll No: "<<get<0>(t4)<<" Name: "<<get<1>(t4)<<" Marks: "<<get<0>(t4)<<"\n";
	cout<<"Roll No: "<<i<<" Name: "<<s<<" Marks: "<<j<<"\n";

	//referencing in the tuple using tie
	tie(i,ignore,j)=t3;
	cout<<"Roll No: "<<i<<" Name: "<<s<<" Marks: "<<j<<"\n";

	//referencing in the tuple using &
	string stemp="Wayne Rooney";
	tuple<int,string&,float> t5(5,s,80);
	cout<<"Before Referencing: "<<get<1>(t5)<<" ";
	get<1>(t5)="Wazza Rooney";
	cout<<"After Referencing: "<<get<1>(t5)<<"\n";

	//Initializer List
	vector<tuple<int,string,float>> vec;
	vec={make_tuple(6,"Dele Alli", 88), make_tuple(7,"Harry Kane",85), t3};
	vec.push_back(make_tuple(6,"Dele Alli", 88));

	//Iniitializer List for pair
	vector<pair<int,string>> vec1 {{1,"Mandar"},{2,"Prathmesh"}};

	//Vector elements (Refer Book)
	cout<<"Vector Elements are:\n";
	for(int k=0;k<vec.size();k++)
	{
		//cout<<vec[k]<<"\n";
	}

	//Vector 2 Elements
	cout<<"Vector Elements are:\n";
	for(int k=0;k<vec2.size();k++)
	{
		//cout<<vec2[k]<<"\n";
	}


	return 0;
}	
