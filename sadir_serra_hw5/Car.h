//
//  Car.h
//  204.4
//
//  Created by Serra SADIR on 9.12.2021.
//

#ifndef Car_h
#define Car_h

using namespace std;
class Car{
  public:
    Car(int f, int i, int t);
    void drive(int);
    void repair(string);
    int Fuel();
    void display();
  private:
    int fuel;
    int insurance;
    int totalkm;
};

#endif /* Car_h */
