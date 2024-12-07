#include <iostream>
#include <string>
using namespace std;
class vehicle {
protected:
int id,yom,dr;
string name;
public:
vehicle(int id,int yom,int dr, string name) : id(id),yom(yom),dr(dr) name(name) {}
virtual double dr() {
return 0.0;
}
void displayDetails() {
cout << "vehicle Details:" << endl;
cout << "ID: " << id << endl;
cout << "Brand Name: " << name << endl;
cout << "Daily rental: $" << dr() << endl;
}
};
class attributes : public vehicle {
private:
double ;
public:
attributes(int id, string name, double monthlySalary) : vehicle(id, name),
monthlySalary(monthlySalary) {}
double getSalary() override {
return monthlySalary;
}
};
class PartTimeEmployee : public vehicle {
private:
double hourlyRate;
double hoursWorked;
public:
PartTimeEmployee(int id, string name, double hourlyRate, double hoursWorked) : vehicle(id, name),
hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}
double getSalary() override {
return hourlyRate * hoursWorked;
}
};
class Contractor : public vehicle {
private:
double dailyRate;
int daysWorked;
public:
Contractor(int id, string name, double dailyRate, int daysWorked) : vehicle(id, name),
dailyRate(dailyRate), daysWorked(daysWorked) {}
double getSalary() override {
return dailyRate * daysWorked;
}
};
int main() {
int vehicleType;
cout << "Enter the vehicle type (1 = Full Time, 2 = Part Time, 3 = Contractor): ";
cin >> vehicleType;
int vehicleId;
cout << "Enter the vehicle ID: ";
cin >> vehicleId;
string vehicleName;
cout << "Enter the vehicle name: ";
cin.ignore(); // Ignore the newline character from previous input
getline(cin, vehicleName);
Vehicle* vehicle;
if (vehicleType == 1) {
double monthlySalary;
cout << "Enter the monthly salary: ";
cin >> monthlySalary;
vehicle = new FullTimeEmployee(vehicleId, vehicleName, monthlySalary);
} else if (vehicleType == 2) {
double hourlyRate;
double hoursWorked;
cout << "Enter the hourly rate: ";
cin >> hourlyRate;
cout << "Enter the hours worked: ";
cin >> hoursWorked;
vehicle = new PartTimeEmployee(vehicleId, vehicleName, hourlyRate, hoursWorked);
} else if (vehicleType == 3) {
double dailyRate;
int daysWorked;
cout << "Enter the daily rate: ";
cin >> dailyRate;
cout << "Enter the days worked: ";
cin >> daysWorked;
vehicle = new Contractor(vehicleId, vehicleName, dailyRate, daysWorked);
} else {
cout << "Invalid vehicle type." << endl;
return 0;
}
vehicle->displayDetails();
delete vehicle;
return 0;
}