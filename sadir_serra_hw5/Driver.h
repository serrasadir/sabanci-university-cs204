//
//  Driver.h
//  204.4
//
//  Created by Serra SADIR on 9.12.2021.
//

#ifndef Driver_h
#define Driver_h

using namespace std;


class Driver {
public:
    Driver(Car &c, int b);
    void repairCar(string);
    void fullFuel();
    void display();
    void drive(int);
private:
    Car &car;
    int budget;
};


#endif /* Driver_h */
