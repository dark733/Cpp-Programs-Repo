#include <iostream>
class person{
	char name[30];
	int age;
public:
	void getData(void);
	void getDisplay(void);
};
int main(){
	person p;
	p.getData();
	p.getDisplay();
	return 0;
}
void person::getData(void){

	std::cout<<"Enter name"<<std::endl;
	std::cin>>name;

	std::cout<<"Enter age"<<std::endl;
	std::cin>>age;

}
void person::getDisplay(void){

	std::cout<<"Person's Name = " <<name<<std::endl;
	std::cout<<"Person's Age = "<<age<<std::endl;
}
