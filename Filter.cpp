#include <iostream> 
#include "Filter.h"
#include <set>

using namespace std;


Filter::Filter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit):
field_(field), firstField_(field), selectCrit_(selectCrit)
{
	
   // TODO: Part 3. Modify or add code to perform the filtering based on the parameters given. Even the next line!
	pEmpVector_ = new vector <Employee *>;

	string begVal = get<0>(dataLimit);
	string endingVal = get<1>(dataLimit);

	while (begVal.find_first_of("_") != std::string::npos) {
		begVal.replace(begVal.find_first_of("_"), 1, " ");
	}// Replace starting range underscores with spaces

	while (endingVal.find_first_of("_") != std::string::npos) {
		begVal.replace(endingVal.find_first_of("_"), 1, " ");
	}// Replace ending range underscores with spaces

	if (selectCrit_ == IS_EQUAL) {
		string eqValueToCompare = get<0>(dataLimit);
		
		for (int i = 0; i < pEmpVector->size(); i++) {
			if (field_ == NAME) {
				if (begVal == pEmpVector->at(i)->name_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter equal names
			if (field_ == STATUS) {
				if (eqValueToCompare == pEmpVector->at(i)->status_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter equal statuses
			if (field_ == SALARY) {
				if (eqValueToCompare == to_string((int)pEmpVector->at(i)->salary_)) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter equal salaries SHOULD WORK NOW
			if (field_ == PAY_BASIS) {
				if (begVal == pEmpVector->at(i)->payBasis_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter equal pay basis
			if (field_ == POSITION) {
				if (begVal == pEmpVector->at(i)->positionTitle_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter equal pos
		}// Loop
	}// Add equal values to vector
	else if (selectCrit == BETWEEN) {
		string startVal = get<0>(dataLimit);
		string endVal = get<1>(dataLimit);

		for (int i = 0; i < pEmpVector->size(); i++) {
			if (field_ == NAME) {
				if (begVal <= pEmpVector->at(i)->name_ && endingVal >= pEmpVector->at(i)->name_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter between names
			if (field_ == STATUS) {
				if (startVal <= pEmpVector->at(i)->status_ && endVal >= pEmpVector->at(i)->status_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter between statuses
			if (field_ == SALARY) {
				if (stoi(startVal) <= (int)pEmpVector->at(i)->salary_ && stoi(endVal) >= (int)pEmpVector->at(i)->salary_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter between salaries SHOULD WORK NOW
			if (field_ == PAY_BASIS) {
				if (begVal <= pEmpVector->at(i)->payBasis_ && endingVal >= pEmpVector->at(i)->payBasis_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter between pay basis
			if (field_ == POSITION) {
				if (begVal <= pEmpVector->at(i)->positionTitle_ && endingVal >= pEmpVector->at(i)->positionTitle_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter between pos
		}// Loop
	} 
	else if (selectCrit == GREATER) {
		string gValToCompare = get<0>(dataLimit);

		for (int i = 0; i < pEmpVector->size(); i++) {
			if (field_ == NAME) {
				if (begVal < pEmpVector->at(i)->name_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter greater names
			if (field_ == STATUS) {
				if (gValToCompare < pEmpVector->at(i)->status_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter greater statuses
			if (field_ == SALARY) {
				if (stoi(gValToCompare) < (int)pEmpVector->at(i)->salary_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter greater salaries SHOULD WORK NOW
			if (field_ == PAY_BASIS) {
				if (begVal < pEmpVector->at(i)->payBasis_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter greater pay basis
			if (field_ == POSITION) {
				if (begVal < pEmpVector->at(i)->positionTitle_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter greater pos
		}// Loop
	}
	else if (selectCrit == LESS) {
		string lValToCompare = get<0>(dataLimit);

		for (int i = 0; i < pEmpVector->size(); i++) {
			if (field_ == NAME) {
				if (begVal > pEmpVector->at(i)->name_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter lesser names
			if (field_ == STATUS) {
				if (lValToCompare > pEmpVector->at(i)->status_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter lesser statuses
			if (field_ == SALARY) {
				if (stoi(lValToCompare) > (int)pEmpVector->at(i)->salary_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter lesser salaries SHOULD WORK NOW
			if (field_ == PAY_BASIS) {
				if (begVal > pEmpVector->at(i)->payBasis_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter lesser pay basis
			if (field_ == POSITION) {
				if (begVal > pEmpVector->at(i)->positionTitle_) {
					pEmpVector_->push_back(pEmpVector->at(i));
				}
			}// Filter great pos
		}// Loop
	}
		
}// Constructor

void Filter::printFilter()
{
   cout << getEmployeeFileHeader();
	for (size_t j = 0; j < pEmpVector_->size(); j++)
	{
		cout << *(pEmpVector_->at(j));
	}
}


void Filter::addFilter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit, FILTER_TYPE filterType)
{
	set<Employee*> employees;
	set<Employee*> anded;
	employees.insert(pEmpVector_->begin(), pEmpVector_->end());
	pEmpVector_->erase(pEmpVector_->begin(), pEmpVector_->end());
	pEmpVector_->resize(0);
	
	field_ = field;
	selectCrit_ = selectCrit;

	if (filterType == AND) {
		string begVal = get<0>(dataLimit);
		string endingVal = get<1>(dataLimit);

		while (begVal.find_first_of("_") != std::string::npos) {
			begVal.replace(begVal.find_first_of("_"), 1, " ");
		}// Replace starting range underscores with spaces

		while (endingVal.find_first_of("_") != std::string::npos) {
			begVal.replace(endingVal.find_first_of("_"), 1, " ");
		}// Replace ending range underscores with spaces

		if (selectCrit_ == IS_EQUAL) {
			string eqValueToCompare = get<0>(dataLimit);
			
			for (int i = 0; i < pEmpVector->size(); i++) {
					if (field_ == NAME) {
						if (begVal == pEmpVector->at(i)->name_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter equal names
					if (field_ == STATUS) {
						if (eqValueToCompare == pEmpVector->at(i)->status_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter equal statuses
					if (field_ == SALARY) {
						if (eqValueToCompare == to_string((int)pEmpVector->at(i)->salary_)) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter equal salaries SHOULD WORK NOW
					if (field_ == PAY_BASIS) {
						if (begVal == pEmpVector->at(i)->payBasis_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter equal pay basis
					if (field_ == POSITION) {
						if (begVal == pEmpVector->at(i)->positionTitle_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter equal pos
			}// Loop
		}// Add equal values to vector
		else if (selectCrit == BETWEEN) {
			string startVal = get<0>(dataLimit);
			string endVal = get<1>(dataLimit);

			for (int i = 0; i < pEmpVector->size(); i++) {
					if (field_ == NAME) {
						if (begVal <= pEmpVector->at(i)->name_ && endingVal >= pEmpVector->at(i)->name_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter between names
					if (field_ == STATUS) {
						if (startVal <= pEmpVector->at(i)->status_ && endVal >= pEmpVector->at(i)->status_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter between statuses
					if (field_ == SALARY) {
						if (stoi(startVal) <= (int)pEmpVector->at(i)->salary_ && stoi(endVal) >= (int)pEmpVector->at(i)->salary_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter between salaries SHOULD WORK NOW
					if (field_ == PAY_BASIS) {
						if (begVal <= pEmpVector->at(i)->payBasis_ && endingVal >= pEmpVector->at(i)->payBasis_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter between pay basis
					if (field_ == POSITION) {
						if (begVal <= pEmpVector->at(i)->positionTitle_ && endingVal >= pEmpVector->at(i)->positionTitle_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter between pos
			}// Loop
		}
		else if (selectCrit == GREATER) {
			string gValToCompare = get<0>(dataLimit);

			for (int i = 0; i < pEmpVector->size(); i++) {
					if (field_ == NAME) {
						if (begVal < pEmpVector->at(i)->name_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter greater names
					if (field_ == STATUS) {
						if (gValToCompare < pEmpVector->at(i)->status_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter greater statuses
					if (field_ == SALARY) {
						if (stoi(gValToCompare) < (int)pEmpVector->at(i)->salary_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter greater salaries SHOULD WORK NOW
					if (field_ == PAY_BASIS) {
						if (begVal < pEmpVector->at(i)->payBasis_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter greater pay basis
					if (field_ == POSITION) {
						if (begVal < pEmpVector->at(i)->positionTitle_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter greater pos
			}// Loop
		}
		else if (selectCrit == LESS) {
			string lValToCompare = get<0>(dataLimit);

			for (int i = 0; i < pEmpVector->size(); i++) {
					if (field_ == NAME) {
						if (begVal > pEmpVector->at(i)->name_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter lesser names
					if (field_ == STATUS) {
						if (lValToCompare > pEmpVector->at(i)->status_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter lesser statuses
					if (field_ == SALARY) {
						if (stoi(lValToCompare) > (int)pEmpVector->at(i)->salary_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter lesser salaries SHOULD WORK NOW
					if (field_ == PAY_BASIS) {
						if (begVal > pEmpVector->at(i)->payBasis_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter lesser pay basis
					if (field_ == POSITION) {
						if (begVal > pEmpVector->at(i)->positionTitle_) {
							anded.insert(pEmpVector->at(i));
						}
					}// Filter great pos
			}// Loop
		}

		
		set<Employee*>* intersectionOfSets = new set<Employee*>;
		for (set<Employee*>::const_iterator it = employees.begin();
		it != employees.end();
			it++) {
			if (anded.count(*it) == 1) {
				intersectionOfSets->insert(*it);
			}
		}

		vector<Employee *> copy1(intersectionOfSets->begin(), intersectionOfSets->end());
		*pEmpVector_ = copy1;

		CompareClass compareClass1(NAME, 1);//sorted by is chosen in arg 3 and isAscending is chosen in arg 4
		std::sort(pEmpVector_->begin(), pEmpVector_->end(), compareClass1);
	}
	else {
		string begVal = get<0>(dataLimit);
		string endingVal = get<1>(dataLimit);

		while (begVal.find_first_of("_") != std::string::npos) {
			begVal.replace(begVal.find_first_of("_"), 1, " ");
		}// Replace starting range underscores with spaces

		while (endingVal.find_first_of("_") != std::string::npos) {
			begVal.replace(endingVal.find_first_of("_"), 1, " ");
		}// Replace ending range underscores with spaces

		if (selectCrit_ == IS_EQUAL) {
			string eqValueToCompare = get<0>(dataLimit);

			for (int i = 0; i < pEmpVector->size(); i++) {
				if (field_ == NAME) {
					if (begVal == pEmpVector->at(i)->name_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter equal names
				if (field_ == STATUS) {
					if (eqValueToCompare == pEmpVector->at(i)->status_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter equal statuses
				if (field_ == SALARY) {
					if (eqValueToCompare == to_string((int)pEmpVector->at(i)->salary_)) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter equal salaries SHOULD WORK NOW
				if (field_ == PAY_BASIS) {
					if (begVal == pEmpVector->at(i)->payBasis_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter equal pay basis
				if (field_ == POSITION) {
					if (begVal == pEmpVector->at(i)->positionTitle_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter equal pos
			}// Loop
		}// Add equal values to vector
		else if (selectCrit == BETWEEN) {
			string startVal = get<0>(dataLimit);
			string endVal = get<1>(dataLimit);

			for (int i = 0; i < pEmpVector->size(); i++) {
				if (field_ == NAME) {
					if (begVal <= pEmpVector->at(i)->name_ && endingVal >= pEmpVector->at(i)->name_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter between names
				if (field_ == STATUS) {
					if (startVal <= pEmpVector->at(i)->status_ && endVal >= pEmpVector->at(i)->status_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter between statuses
				if (field_ == SALARY) {
					if (stoi(startVal) <= (int)pEmpVector->at(i)->salary_ && stoi(endVal) >= (int)pEmpVector->at(i)->salary_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter between salaries SHOULD WORK NOW
				if (field_ == PAY_BASIS) {
					if (begVal <= pEmpVector->at(i)->payBasis_ && endingVal >= pEmpVector->at(i)->payBasis_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter between pay basis
				if (field_ == POSITION) {
					if (begVal <= pEmpVector->at(i)->positionTitle_ && endingVal >= pEmpVector->at(i)->positionTitle_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter between pos
			}// Loop
		}
		else if (selectCrit == GREATER) {
			string gValToCompare = get<0>(dataLimit);

			for (int i = 0; i < pEmpVector->size(); i++) {
				if (field_ == NAME) {
					if (begVal < pEmpVector->at(i)->name_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter greater names
				if (field_ == STATUS) {
					if (gValToCompare < pEmpVector->at(i)->status_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter greater statuses
				if (field_ == SALARY) {
					if (stoi(gValToCompare) < (int)pEmpVector->at(i)->salary_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter greater salaries SHOULD WORK NOW
				if (field_ == PAY_BASIS) {
					if (begVal < pEmpVector->at(i)->payBasis_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter greater pay basis
				if (field_ == POSITION) {
					if (begVal < pEmpVector->at(i)->positionTitle_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter greater pos
			}// Loop
		}
		else if (selectCrit == LESS) {
			string lValToCompare = get<0>(dataLimit);

			for (int i = 0; i < pEmpVector->size(); i++) {
				if (field_ == NAME) {
					if (begVal > pEmpVector->at(i)->name_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter lesser names
				if (field_ == STATUS) {
					if (lValToCompare > pEmpVector->at(i)->status_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter lesser statuses
				if (field_ == SALARY) {
					if (stoi(lValToCompare) > (int)pEmpVector->at(i)->salary_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter lesser salaries SHOULD WORK NOW
				if (field_ == PAY_BASIS) {
					if (begVal > pEmpVector->at(i)->payBasis_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter lesser pay basis
				if (field_ == POSITION) {
					if (begVal > pEmpVector->at(i)->positionTitle_) {
						employees.insert(pEmpVector->at(i));
					}
				}// Filter great pos
			}// Loop
		}
		vector<Employee *> copy(employees.begin(), employees.end());
		*pEmpVector_ = copy;

		CompareClass compareClass(NAME, 1);//sorted by is chosen in arg 3 and isAscending is chosen in arg 4
		std::sort(pEmpVector_->begin(), pEmpVector_->end(), compareClass);
	}
} // Add filter to vecltor
