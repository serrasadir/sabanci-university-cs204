//
//  Car.cpp
//  204.4
//
//  Created by Serra SADIR on 9.12.2021.
//
#include <iostream>
#include "Car.h"
using namespace std;

Car::Car(int f, int i, int k)
 : fuel(f), insurance(i), totalkm(k)
{ }

void Car::drive(int km){
    totalkm += km;
    fuel -= km/4;
}
void Car::display(){
    cout << "Fuel Level: " << fuel << endl << "Insurance Fee: " << insurance << endl << "Total distance that the car has travelled:" << totalkm << endl;
}
void Car::repair(string accident) {
    if(accident == "SMALL") {
        insurance += insurance*0.05;
        cout << "50$ is reduced from the driver's budget because of the MEDIUM accident " << endl <<  "Yearly insurance fee is increased to "<< insurance <<" because of the SMALL accident" << endl;

    }
    else if (accident == "MEDIUM") {
        insurance += insurance*0.1;
        cout << "150$ is reduced from the driver's budget because of the MEDIUM accident " << endl <<  "Yearly insurance fee is increased to "<< insurance <<" because of the MEDIUM accident" << endl;
    }
    else if (accident == "LARGE") {
        insurance += insurance*0.2;
        cout << "300$ is reduced from the driver's budget because of the MEDIUM accident " << endl <<  "Yearly insurance fee is increased to "<< insurance <<" because of the LARGE accident" << endl;
    }
}

int Car::Fuel() {
    int x = 300 - fuel;

    return x;
}

