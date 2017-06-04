/*
 *Travis Allan
 *11/10/2016
 *CSCE 4550.001
 *Project 1
 *Description: This project is an implementation of the Bell-LaPadula security model.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
//#include "Subject.h"
//#include "Object.h"
#include "RefMon.h"
using namespace std;

void ReferenceMonitor::setCount() {
    sCount = 0;
    oCount = 0;
}
void ReferenceMonitor::createSubject(const char name[20], int security) {
    strcpy(SubjectArray[sCount].subName, name);
    SubjectArray[sCount].temp = 0;
    sSecurity[sCount] = security;
    sCount++;
}
void ReferenceMonitor::createObject(const char name[20], int security) {
    strcpy(ObjectArray[oCount].objName, name);
    ObjectArray[oCount].value = 0;
    oSecurity[oCount] = security;
    oCount++;
}
int ReferenceMonitor::executeRead(const char sname[20], const char oname[20]) {
    for (int i=0; i<6; i++) {
        if (strcmp(sname, SubjectArray[i].subName) == 0) {
            for(int j=0; j<6; j++) {
                if (strcmp(oname, ObjectArray[j].objName) == 0) {
                    //cout << "sS: " << sSecurity[i] << "oS: " << oSecurity[j] << endl;
                    if ((sSecurity[i] == oSecurity[j]) || (sSecurity[i] > oSecurity[j])){
                        SubjectArray[i].temp = ObjectArray[j].value;
                        cout << "Access Granted : ";
                        return 1;
                    }
                    else {
                        cout << "Access Denied : ";
                        return 2;
                    }
                }
            }
        }
    }
    return 0;
}
int ReferenceMonitor::executeWrite(const char sname[20], const char oname[20], int tempVal) {
    for (int i=0; i<6; i++) {
        if (strcmp(sname, SubjectArray[i].subName) == 0) {
            for(int j=0; j<6; j++) {
                if (strcmp(oname, ObjectArray[j].objName) == 0) {
                    //cout << "sS: " << sSecurity[i] << "oS: " << oSecurity[j] << endl;
                    if ((sSecurity[i] == oSecurity[j]) || (sSecurity[i] < oSecurity[j])){
                        ObjectArray[j].value = tempVal;
                        //cout << "objval: " << ObjectArray[j].value << endl;
                        cout << "Access Granted : ";
                        return 1;
                    }
                    else {
                        cout << "Access Denied : ";
                        return 2;
                    }
                }
            }
        }
    }
    return 0;
}
void ReferenceMonitor::printState() {
    /*cout << "The current state is:" << endl;
    cout << " | Subject | Value |" << endl;
    for(int i =0; i < 6; i++) {
        cout << "   " << SubjectArray[i].subName << "\t\t" << SubjectArray[i].temp << endl;
    }
    cout << endl;
    cout << " | Object | Value |" << endl;
    for(int i =0; i < 5; i++) {
        cout << "   " << ObjectArray[i].objName << "\t\t" << ObjectArray[i].value << endl;
    }
    cout << endl;
     */
    
    cout << "+------------------------The current state is-------------------------+" << endl;
    cout << "| Subject |";
    for(int i =0; i < 6; i++) {
        cout << setw(8) << SubjectArray[i].subName << " |";
    }
    cout << endl;
    cout << "| Value   |";
    for(int i =0; i < 6; i++) {
        cout << setw(8) << SubjectArray[i].temp << " |";
    }
    cout << endl;
    cout << "+---------------------------------------------------------------------+" << endl;
    
    cout << "| Object  |";
    for(int i =0; i < 6; i++) {
        cout << setw(8) << ObjectArray[i].objName << " |";
    }
    cout << endl;
    cout << "| Value   |";
    for(int i =0; i < 6; i++) {
        cout << setw(8) << ObjectArray[i].value << " |";
    }
    cout << endl;
    cout << "+---------------------------------------------------------------------+" << endl;
    cout << endl;
}


    
    
    
    
    
    
    
