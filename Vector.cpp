#include<iostream>
#include<vector>

// using namespace std;

int main()
{
	int i;
	std::vector<int> v;
	std::cout<<"Input a few elements(Enter 0 after entering the last element to show the last element is the one before 0):"<<std::endl;
	while(1)
	{
		std::cin>>i;
		if(i == 0)
			break;
		else
			v.push_back(i);
	}
	std::cout<<"The vector you have input is :"<<std::endl;
	for(i=0;i<v.size();++i)
	{
		std::cout<<v.at(i)<<std::endl;
	}
	return 0;
}