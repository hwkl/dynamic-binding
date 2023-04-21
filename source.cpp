#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

/*
	refactored!!
*/

class Driver {
private:
	int driverAge;
	char driverName[10];
public:
	Driver(const char* driverName, int driverAge) { this->driverAge = driverAge, strcpy_s(this->driverName, driverName); }
	const char* getDriverName() const { return driverName; }
	int getDriverAge() const { return driverAge; }
	virtual int getSalary() const = 0;
	virtual void showDriverInfo() const = 0;
};

class TaxiDriver : public Driver {
private:
	int baseSalary;
	int bonusMoney;

public:
	TaxiDriver(const char* driverName, int driverAge, int baseSalary, int bonusMoney) : Driver(driverName, driverAge), baseSalary(baseSalary), bonusMoney(bonusMoney) {}
	// other functions and data members

	virtual int getSalary() const {
		return baseSalary + bonusMoney;
	}

	virtual void showDriverInfo() const {
		cout << "driverName = " << getDriverName() << " " << "driverAge = " << getDriverAge() << " "
			<< "baseSalary = " << baseSalary << " " << "bonusMoney = " << bonusMoney << endl;
	};
};

class BusDriver : public Driver {
private:
	int workingHours;
	int payPerHour;
public:
	BusDriver(const char* driverName, int driverAge, int workingHours, int payPerHour) : Driver(driverName, driverAge), workingHours(workingHours), payPerHour(payPerHour) {}
	virtual int getSalary() const {
		return workingHours * payPerHour;
	}
	virtual void showDriverInfo() const {
		cout << "driverName = " << getDriverName() << " " << "driverAge = " << getDriverAge() << " "
			<< "workingHours = " << workingHours << " " << "payPerHour = " << payPerHour << endl;
	};
};

class DriverList {
private:
	Driver* driverList[50];
	int numDrivers;

public:
	DriverList() : numDrivers(0) {}

	void addDriver(Driver* driver) {
		driverList[numDrivers++] = driver;
	}

	void showAllDriverInfo()  {
		for (int i = 0; i < numDrivers; i++) {
			driverList[i]->showDriverInfo();
		}
	}

	void showTotalSalary()  {
		int sum = 0;
		for (int i = 0; i < numDrivers; i++) {
			sum += driverList[i]->getSalary();
		}
		cout << "total salary = " << sum << endl;
	}

	~DriverList() {
		for (int i = 0; i < numDrivers; i++) {
			delete driverList[i];
		}
	}
};



int main() {
	
	DriverList drivers;
	Driver* pNewDriver = NULL;

	pNewDriver = new TaxiDriver("Kim", 33, 300, 50);
	drivers.addDriver(pNewDriver);

	pNewDriver = new TaxiDriver("Lee", 45, 350, 60);
	drivers.addDriver(pNewDriver);

	pNewDriver = new BusDriver("Park", 36, 40, 5);
	drivers.addDriver(pNewDriver);

	pNewDriver = new BusDriver("Yoo", 40, 30, 6);
	drivers.addDriver(pNewDriver);

	drivers.showAllDriverInfo();
	drivers.showTotalSalary();
	

	return 0;
}