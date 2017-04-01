#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

enum DATA_FIELDS
{
	NAME, STATUS, SALARY, PAY_BASIS, POSITION
};

class Employee{
	public:
		Employee();
		Employee(std::string  fileLine);
		
		void setField(DATA_FIELDS dataField, std::string value);

		std::string name_;
		std::string status_;
		double salary_;
		std::string payBasis_;
		std::string positionTitle_;

	friend std::ostream& operator<<(std::ostream&, const Employee&);

};

class CompareClass
{
public:
   CompareClass(DATA_FIELDS dataField, bool isAscending=true) : dataField_(dataField), isAscending_(isAscending){}
   // TODO: Part2: implement the overloaded () operator. 
   bool operator() (Employee *pX, Employee *pY) {
	   if (isAscending_ == true) {
		   if (dataField_ == NAME) {
			   return pX->name_ < pY->name_;
		   }
		   else if (dataField_ == STATUS) {
			   return pX->status_ < pY->status_;
		   }
		   else if (dataField_ == SALARY) {
			   return pX->salary_ < pY->salary_;
		   }
		   else if (dataField_ == PAY_BASIS) {
			   return pX->payBasis_ < pY->payBasis_;
		   }
		   else if (dataField_ == POSITION) {
			   return pX->positionTitle_ < pY->positionTitle_;
		   }
	   }
	   else {
		   if (dataField_ == NAME) {
			   return pX->name_ > pY->name_;
		   }
		   else if (dataField_ == STATUS) {
			   return pX->status_ > pY->status_;
		   }
		   else if (dataField_ == SALARY) {
			   return pX->salary_ > pY->salary_;
		   }
		   else if (dataField_ == PAY_BASIS) {
			   return pX->payBasis_ > pY->payBasis_;
		   }
		   else if (dataField_ == POSITION) {
			   return pX->positionTitle_ > pY->positionTitle_;
		   }
	   }
   }
private:
   DATA_FIELDS dataField_;
   bool isAscending_;
};

std::ostream& operator<<(std::ostream &strm, const Employee &emp);

std::string getEmployeeFileHeader();
#endif
