#include<iostream>
#include<vector>

// using namespace std;

int main()
{
	int i;
	std::vector<int> v;
	std::cout<<"Input a few elements:"<<std::endl;
	while(1)
	{
		std::cin>>i;
		if(i == 0)
			break;
		else
			v.push_back(i);
	}
	for(i=0;i<v.size();++i)
	{
		std::cout<<v.at(i)<<std::endl;
		// std::cout<<std::endl;
	}
	return 0;
}