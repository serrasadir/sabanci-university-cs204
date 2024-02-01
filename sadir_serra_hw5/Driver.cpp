//
//  Driver.cpp
//  204.4
//
//  Created by Serra SADIR on 9.12.2021.
//
#include <iostream>
#include "Car.h"
#include "Driver.h"
using namespace std;

Driver::Driver(Car &c, int b)
 : car(c), budget(b)
{ }
void Driver::repairCar(string accident){

    if(accident == "SMALL") {
        budget -= 50;
    }
    else if (accident == "MEDIUM") {
        budget -= 150;
    }
    else if (accident == "LARGE") {
        budget -= 300;
    }
    car.repair(accident);
}
void Driver::drive(int km){
    car.drive(km);
}
void Driver::fullFuel() {
    budget -= car.Fuel();
    cout << "Fuel is full" << endl;
}
void Driver:: display() {
    cout << "Driver Budget: " << budget << endl;
}
