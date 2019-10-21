/*c++ program to calculate the EB bill for different types of consumers.*/
/*For Home consumers-there is a 100 free units and remaining units charges Rs.1.50/unit.*/
/*For Industrial consumers-there is no free units and charges Rs.3.50/unit*/
#include<iostream>
class consumers //creates a abstract base class
{
	protected:
		char name[20];
		int cid;
	public:
		consumers();
		void get_consumers();
		virtual void EB_bill_calculation()=0;//creates the pure virtual function
		~consumers();
};
consumers::consumers()
{
	cid=0;
}
void consumers::get_consumers()//gets the consumers details
{
	std::cout<<"\nEnter the Customer name:";
	std::cin>>name;
	std::cout<<"\nEnter the Customer id:";
	std::cin>>cid;
}
consumers::~consumers()
{
}
class home_consumers:public consumers//creates a derived class 
{
	private:
		char area_name[20];
		int number_of_units;
		float total;
	public:
		home_consumers();
		void EB_bill_calculation();
		~home_consumers();
};
home_consumers::home_consumers()
{
	number_of_units=0;
}
void home_consumers::EB_bill_calculation()//displays the Eb bill amount
{
	consumers::get_consumers();
	std::cout<<"\nEnter the area of the consumer:";
	std::cin>>area_name;
	std::cout<<"\nEnter the number of units used:";
	std::cin>>number_of_units;
	if(number_of_units>100)//for home consumers first 100 units free
	{
		total=1.5*(number_of_units-100);
	}
	else
	{
		total=1.5*number_of_units;
	}
	std::cout<<"\nThe EB bill amount for Home consumer is:"<<total;
}
home_consumers::~home_consumers()
{
}
class industry_consumers:public consumers//creates a derived class
{
	private:
		char area_name[20];
		int number_of_units;
		float total;
	public:
		industry_consumers();
		void EB_bill_calculation();
		~industry_consumers();
};
industry_consumers::industry_consumers()
{
	number_of_units=0;
}
void industry_consumers::EB_bill_calculation()//displays the EB bill amount
{
	consumers::get_consumers();
	std::cout<<"\nEnter the area of the consumers:";
	std::cin>>area_name;
	std::cout<<"\nEnter the number of units used:";
	std::cin>>number_of_units;
	total=3.5*number_of_units;
	std::cout<<"\nThe EB bill amount for industry consumer is:"<<total;
}
industry_consumers::~industry_consumers()
{
}
int main()
{
	int choice;
	std::cout<<"\n\t\tELECTRICITY BILL";
	std::cout<<"\n\t\t__________________";
	do
	{
		std::cout<<"\n1.HOME_CONSUMERS\n2.INDUSTRY_CONSUMERS\n3.EXIT";
		std::cout<<"\n\n\nWhich Type of consumer?\n(press 1 or 2 to choose else press 3 for exit):\n\n";
		std::cin>>choice;
		switch(choice)
		{
			case 1:
				{
					home_consumers h;//creates a derived class object
					h.EB_bill_calculation();//call the derived class(home_consumers) method
				}
				break;
			case 2:
				{
					industry_consumers i;//creates a derived class object
					i.EB_bill_calculation();//call the derived class(industry_consumers) method
				}
				break;
			case 3:
				break;
		}
	}while(choice<=2);
	return 0;
}
	

