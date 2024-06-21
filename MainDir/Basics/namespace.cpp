#include <iostream>
namespace demo{
	void greet(){
		std::cout<<"Greet Function called from within global namespace scope using scope resolution operator in main function to cal this"<<std::endl;
	}
}
int main(){
	std::cout<<"Namespace Program in C++"<<std::endl;
	demo::greet();
	return 0;
}