#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct courseNode {
  string courseCode, courseName;
  vector<int> studentsAttendingIDs;
  courseNode * next;
  courseNode () {}
    courseNode (string cC , string cN , courseNode * link )
        : courseCode(cC), next (link) ,courseName(cN)
    {}
};
bool check(courseNode * head, string code, int & i) {
    courseNode * ptr = head;
    
     while (ptr != nullptr) {
        if (ptr -> courseCode == code) {
            return true;
        }
         i++;
         ptr = ptr->next;
    }
    return false;
};
bool checkID(int id, vector<int> vec){ // will use i id sorting function for option 1 to display message
    for (int j = 0; j < vec.size(); j++){
        if (vec[j]== id){
            return true;
        }
    }
    return false;
};


courseNode* sortID( int ids, courseNode * & head, int i, int opt) {
    int x = 0;
    courseNode * temp = head;
    while (x != i) {
        temp = temp->next;
        x++;
    }
    if (checkID(ids, temp -> studentsAttendingIDs) && opt == 1){
        cout << "Student with id " << ids << "already is enrolled to "<< temp -> courseCode <<". No action taken." << endl;
        return head;
    }
    temp -> studentsAttendingIDs.push_back(ids);
    for (int x = 0; x < temp -> studentsAttendingIDs.size(); x++) {
        int min = x;  //store the current index
        for (int y = x+1; y < temp -> studentsAttendingIDs.size(); y++) {
            if (temp -> studentsAttendingIDs[y] < temp -> studentsAttendingIDs[x]) {
                min = y;
            }
        }
        int store = temp -> studentsAttendingIDs[min];
        temp -> studentsAttendingIDs[min] = temp -> studentsAttendingIDs[x];
        temp -> studentsAttendingIDs[x] = store;// switch the min and current
    }
    return head;
};

courseNode* sortName(courseNode * & head, string code,string name, int ids, int opt) {
    courseNode * ptr = head;
    if (name < head -> courseName) {
        courseNode * store = new courseNode(code, name, head);  //node to be inserted
        head = store;
        return head;
    }
    else if (head -> next == nullptr) {
        head -> next = new courseNode(code, name, nullptr);
        return head;
    }
    while (ptr->next != NULL && ptr->next->courseName < name) {
        ptr = ptr-> next;
    }
    courseNode * store = new courseNode(code, name, ptr->next);  //node to be inserted
    ptr->next = store;
    if (opt == 1) {
        cout << "Student with id " << ids << " is enrolled to " << code << "." << endl;
    }
    return head;
};
int main() {
    string fname, line, code, name;
    int ids;
    cout << "Please enter file name: ";
    cin >> fname;
    ifstream cstream;
    cstream.open(fname.c_str());
    cout << "Successfully opened file " << fname << endl;
    cout << "The linked list is created." << endl << "The initial list is:" << endl;
    int count = 0;
    while(getline(cstream, line)) {
        count ++;
    }
    cstream.clear();
    cstream.seekg(0);
    courseNode *head = NULL;

    for (int l = 0; l < count; l++) {
        getline(cstream,line); //getting lines from file
        istringstream linec(line); // spliting lines
        linec >> code >> name >> ids;
        if (l == 0) {
           head = new courseNode(code, name, NULL);
           head ->studentsAttendingIDs.push_back(ids);
        }
        else {
            int i = 0;
            if( check(head, code, i)) { //if course is already in the list sort them
                sortID(ids, head, i, 0);
                
            }
            else if (check(head, code, i) == false ) { //if the course had not created in list yet sort according to the course name
                sortName(head, code, name, ids, 0);
            }
        }
        linec.clear();
    }
    courseNode * courselist = head;
    while (courselist != nullptr) {
        cout << courselist -> courseCode << " " << courselist -> courseName << ": " ;
        for (int u = 0; u < courselist -> studentsAttendingIDs.size(); u++ ) {
            cout << courselist -> studentsAttendingIDs[u] << " ";
        }
        cout << endl;
        courselist = courselist -> next;
    }
    cstream.close();
    cout << "1. Add to List" << endl << "2. Drop from List" << endl << "3. Display List" << endl << "4.Finish Add/Drop and Exit" << endl;
    int option;
    string options;
    cin >> option;
    while (option != 4) {
        if (option == 1) {
            cout << "Give the student ID and the course names and course codes that he/she wants to add:" << endl;
            string info;
            cin.ignore();
            getline(cin, info);
            int id2;
            string code2, name2;
            istringstream infoline(options);
            int i = 0;
            while( infoline >> code2 >> name2) {
                while (infoline >> id2) {
                    if (check(head, code2 ,i)) {
                        sortID(id2 , head, i, 1);
                    }
                    else {
                        cout << code2 << " does not exist in the list of Courses. It is added up." << endl;
                        sortName(head, code2, name2, id2 , 1);
                    }
                }
                infoline.clear();
            }
        }
        if (option == 3) {
            courseNode * currentlist = head;
            while (currentlist != nullptr) {
                cout << currentlist -> courseCode << " " << currentlist -> courseName << ": " ;
                for (int u = 0; u < currentlist -> studentsAttendingIDs.size(); u++ ) {
                    cout << currentlist -> studentsAttendingIDs[u] << " ";
                }
                cout << endl;
                currentlist = currentlist -> next;
            }
        }
        cin >> option;
    }
    
    
    
    return 0;
}

