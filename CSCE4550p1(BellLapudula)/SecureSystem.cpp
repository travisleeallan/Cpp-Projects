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
//#include "Subject.h"
//#include "Object.h"
#include "RefMon.h"
using namespace std;

int main(int argc, char* argv[]) {
	//declarations
    char command[10];
    char sName[20];
    char oName[20];
    char fileName[20];
    string line;
    int inputVal;
    ReferenceMonitor RefMon;
    
    //initiallization
    //cout << argc << endl;
    strcpy(fileName, argv[argc-1]);
    //cout << fileName << endl;
    RefMon.setCount();
    RefMon.createSubject("adam", 1);
    RefMon.createSubject("james", 2);
    RefMon.createSubject("tim", 3);
    RefMon.createSubject("sara", 1);
    RefMon.createSubject("kristy", 2);
    RefMon.createSubject("liz", 3);
    RefMon.createObject("aobj", 1);
    RefMon.createObject("jobj", 2);
    RefMon.createObject("tobj", 3);
    RefMon.createObject("sobj", 1);
    RefMon.createObject("kobj", 2);
    RefMon.createObject("lobj", 3);

    
    //input
    ifstream file (fileName);
    if (file.is_open()) {
        while (getline(file, line))
        {
            //cout << line << endl;; //test

            
            //line parsing using strtok
            char * cline = new char[line.size() + 1];
            copy(line.begin(), line.end(), cline);
            cline[line.size()] = '\0';
            char * cline2 = new char[line.size() + 1];
            strcpy(cline2, cline);
            
            //this is used to check the number of params in line for error handling
            char * lengthCheck = strtok(cline2, " ");
            //cout << lengthCheck << endl;
            int len = 0; //length of line counter
            while (lengthCheck != NULL) {
                len++;
                //cout << lengthCheck << endl;
                //cout << "len = " << len << endl;
                lengthCheck = strtok(NULL, " ");
            }
            delete [] cline2;
            
            //line parsing
            strcpy(command, strtok (cline, " "));
            
            if ((strcmp(command, "READ") == 0) || (strcmp(command, "read") == 0)) {
                int returnVal;
                if (len == 3) {
                    strcpy(sName, strtok (NULL, " "));
                    strcpy(oName, strtok (NULL, " "));
                    
                    //test
                    //cout << sName << endl;
                    //cout << oName << endl;
                    
                    //call read function
                    returnVal = RefMon.executeRead(sName, oName);
                    if (returnVal == 0) cout << "Bad Instruction : " << line << endl;
                    else if (returnVal == 1){
                        cout << line << endl;
                        
                        //print the state
                        RefMon.printState();
                    }
                    else cout << line << endl;
                }
                else {
                    cout << "Bad Instruction : " << line << endl;
                    //RefMon.printState();
                }
            }
            else if ((strcmp(command, "WRITE") == 0) || (strcmp(command, "write") == 0)) {
                int returnVal;
                if (len==4) {
                    strcpy(sName, strtok (NULL, " "));
                    strcpy(oName, strtok (NULL, " "));
                    char* temp = (strtok (NULL, " "));
                    //cout << temp << endl; //test
                    inputVal = atoi (temp);
                    
                    //test
                    //cout << sName << endl;
                    //cout << oName << endl;
                    //cout << inputVal << endl;
                    
                    //call write function
                    returnVal = RefMon.executeWrite(sName, oName, inputVal);
                    if (returnVal == 0) cout << "Bad Instruction : " << line << endl;
                    else if (returnVal == 1){
                        cout << line << endl;
                        
                        //print the state
                        RefMon.printState();
                    }
                    else cout << line << endl;
                }
                else {
                    cout << "Bad Instruction : " << line << endl;
                    //RefMon.printState();
                }
            }
            else {
                cout << "Bad Instruction : " << line << endl;
                //RefMon.printState();
            }
            //method calls
            
            delete[] cline;
        }
        file.close();
    }
    else cout << "File not opened" << endl;

	return 0;
}
