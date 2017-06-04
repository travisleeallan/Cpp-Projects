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
#include "Subject.h"
#include "Object.h"

using namespace std;

class ReferenceMonitor: public Subject, public Object {
private:
    Subject SubjectArray[6];
    Object ObjectArray[6];
    int sSecurity[6];
    int oSecurity[6];
    int sCount; //number of subjects initialized
    int oCount; //number of objects initialized
    
public:
    void setCount();
    void createSubject(const char name[20], int security);
    void createObject(const char name[20], int security);
    int executeRead(const char sname[20], const char oname[20]);
    int executeWrite(const char sname[20], const char oname[20], int tempVal);
    void printState();
};

