#include "Employee.h"



// TODO: Part 1. Debug the following constructor that takes a line
//       in the format similar to "2014.cvs" and populates an Employee object
//       You may need to fix multiple lines
Employee::Employee(std::string lineFromFile)
{
	std::string tempString = lineFromFile;
	int foundFirst = tempString.find_first_of("\"");
	int foundLast = tempString.find_first_of("\"", foundFirst + 1);
	name_ = tempString.substr(foundFirst + 1, foundLast - 1); //Value of name

	tempString = tempString.substr(foundFirst + 1 + foundLast);

	int	foundStatus1 = tempString.find_first_of(",");
	int	foundStatus2 = tempString.find_first_of(",", foundStatus1 + 1);// Skipiing the next ,
	status_ = tempString.substr(foundStatus1 + 1, foundStatus2 - 1); //Value of status

	tempString = tempString.substr(foundStatus2);

	int	foundSalary1 = tempString.find_first_of(",");
	int	foundSalary2 = tempString.find_first_of(",", foundSalary1 + 1);
	std::string salaryStr = tempString.substr(foundSalary1 + 1, foundSalary2 - 1);
	salary_ = stod(salaryStr.erase(0, 1)); // Value of salary

	tempString = tempString.substr(foundSalary2);


	int	foundPayBasis1 = tempString.find_first_of(",");
	int	foundPayBasis2 = tempString.find_first_of(",", foundPayBasis1 + 1);
	payBasis_ = tempString.substr(foundPayBasis1 + 1, foundPayBasis2 - 1);// Value of pay basis

	tempString = tempString.substr(foundPayBasis2);

	int	foundPositionTitle1 = tempString.find_first_of(",");
	positionTitle_ = tempString.substr(foundPositionTitle1 + 1);

}

Employee::Employee():name_(""),
status_(""),
salary_(0),
payBasis_(""),
positionTitle_("")
{}

void Employee::setField(DATA_FIELDS dataField, std::string value)
{
   // Replace '_' by space
   std::replace(value.begin(), value.end(), '_', ' '); // replace all '_' to ' ' (space)

   switch (dataField)
   {
      case NAME:
         name_ = value;
         break;
      case STATUS:
         status_ = value;
         break;
      case SALARY:
         salary_ = stof(value);
         break;
      case PAY_BASIS:
         payBasis_ = value;
         break;
      case POSITION:
         positionTitle_ = value;
         break;
   }
}

std::ostream& operator<<(std::ostream &strm, const Employee &emp) {
	std::ostringstream oss;
	oss << std::left << std::setw(30) << emp.name_ << " ";
	oss << std::left << std::setw(10) << emp.status_ << " ";
	oss << std::right << std::setw(10) << emp.salary_ << " ";
	oss << std::left << std::setw(10) << emp.payBasis_ << " ";
	oss << std::left << std::setw(10) << emp.positionTitle_ << std::endl;
	return strm << oss.str();
}

std::string getEmployeeFileHeader()
{
   std::string str = "";
   str += "Name                           Status         Salary Pay Basis  Position Title\n";
   str += "====================================================================================================================================\n";
   return str;
}


