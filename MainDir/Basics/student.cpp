#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class student{

char name[10];
int age;

	public:
	void disp_take_input(void);
	void disp_(void);
};
int main(){
	student s;
	s.disp_take_input();
	s.disp_();

	return 0;
}
void student::disp_take_input(void){
	srand(time(NULL));
    int random_val=rand();
	cout<<"Random Unique ID = "<<random_val<<endl;
	cout<<"Enter name"<<endl;
	cin>>name;
	cout<<"enter age"<<endl;
	cin>>age;
	
}
void student::disp_(void){
	cout<<"Name= "<<name<<" , "<<"age= "<<age<<endl;
	
}