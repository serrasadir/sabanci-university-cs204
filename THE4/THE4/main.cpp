//  THE4
//  Created by Serra SADIR on 9.05.2021.
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct boats{
    unsigned int bid;
    string bname, bcolor;
};
struct sailors{
    unsigned int sid;
    string sname;
    double srating, sage;
};
struct reserve{
    int sid, bid;
    string rdate, sname, bname, bcolor;
    double srating, sage;
};
void sortdays(vector<reserve> &reservev, int part, int count){
    int minindex;
    reserve temp;
    for(int k=0; k < count-1 ; k++){
            minindex = k;
        for(int j=k+1; j < count; j++) {
            if (((reservev[j].rdate).substr(0, (part)) == (reservev[minindex].rdate).substr(0, (part))) && (reservev[j].rdate)[part] < (reservev[minindex].rdate)[part]) {
                minindex = j;
            }
            if (((reservev[j].rdate) == (reservev[k].rdate) && (reservev[j].sname) < (reservev[k].sname))) {
                minindex = j;
            }
        }
        temp = reservev[k];
        (reservev[k]) = (reservev[minindex]);
        (reservev[minindex]) = temp;
  }
}
int main() {
    vector<boats> boatv(5);
    vector<sailors> sailorv(10);
    string boatf = "Boat.txt", sailorf = "Sailor.txt" , file, lineb, lines, liner;
    ifstream boat, sailor, reserv;
    boat.open(boatf.c_str());
    sailor.open(sailorf.c_str());
    cout << "Enter filename for reservation database: ";
    cin >> file;
    reserv.open(file.c_str());
    if ( reserv.fail()) {
        cout << "Cannot open the files. Exiting..." << endl;
    }
    int count = 0;
    while(getline(reserv, liner)) {
        count ++;
    }
    reserv.clear();
    reserv.seekg(0);
    vector<reserve> reservev(count);
    if (! reserv.fail()) {
        for (int b = 0; b < 6; b++) {
           getline(boat, lineb);
            if (b>0) {
             istringstream lineBoat(lineb);
             lineBoat >> boatv[b-1].bid >> boatv[b-1].bname >> boatv[b-1].bcolor;
             string name = boatv[b-1].bname;
            }
      }
        boat.clear();
        boat.seekg(0);
        for (int s = 0; s < 11; s++) {
           getline(sailor, lines);
            if (s>0) {
             istringstream lineSailor(lines);
             lineSailor >> sailorv[s-1].sid >> sailorv[s-1].sname >> sailorv[s-1].srating >> sailorv[s-1].sage;
        }
      }
        sailor.clear();
        sailor.seekg(0);
        for (int r = 0; r < count; r++) {
            getline(reserv,liner);
            if (r > 0) {
            istringstream lineReserv(liner);
            lineReserv >> reservev[r].sid >> reservev[r].bid >> reservev[r].rdate;
            for ( int y = 0; y<5; y++) {
              if ( reservev[r].bid == boatv[y].bid ) {
                  reservev[r].bname = boatv[y].bname;
                  reservev[r].bcolor = boatv[y].bcolor;
               }
            }
            for ( int x = 0; x<10; x++) {
              if ( reservev[r].sid == sailorv[x].sid ) {
                  reservev[r].sname = sailorv[x].sname;
                  reservev[r].sage = sailorv[x].sage;
                  reservev[r].srating = sailorv[x].srating;
               }
            }
                boat.clear();
                boat.seekg(0);
                sailor.clear();
                sailor.seekg(0);
            }
        }
        boat.close();
        sailor.close();
        sortdays(reservev, 2, count);
        sortdays(reservev, 3, count);
        sortdays(reservev, 5, count);
        sortdays(reservev, 6, count);
        sortdays(reservev, 8, count);
        sortdays(reservev, 9, count);
  
        for (int r = 1; r < count; r++) {
            cout << reservev[r].rdate << " -> " << reservev[r].sname << "(" << reservev[r].sage << "," << reservev[r].srating << ")" << " has reserved " << reservev[r].bname << "(" << reservev[r].bcolor << ")" << endl;
        }
        reserv.close();
    }
    return 0;
}

