#include <iostream>

float first_num,second_num,average_num,res;

float average(float first_num,float second_num);

int main(){
	std::cout<<"Average of two numbers"<<std::endl;

	std::cout<<"enter first number"<<std::endl;
	std::cin>>first_num;

	std::cout<<"enter first number"<<std::endl;
	std::cin>>second_num;
	
	res=average(first_num,second_num);
	std::cout<<"Average="<<res<<std::endl;

	return 0;
}
float average(float first_num,float second_num){
	average_num=(first_num+second_num)/2;
	return average_num;
}