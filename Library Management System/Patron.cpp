/*
 *Name: Travis Allan
 *Date: 7/27/2014
 *Course: CSCE 1040
 *Title: Program 6
 *Description: Library Database
 *References: CSCE1040 Lab Handout "List It, Stack It, Queue it" Handout 2014
 *I used the algorithm for making a list as the basis for all of my list operations. All list operations derived or taken from that algorithm are denoted with the comment "//based on algorithm".
 */

//headers
#include <iostream>
#include <fstream>
#include <cstring>
#include "tempHeader.h"
using namespace std;


//completed
int Patron::EditPatron(char tempname1[20], char tempname2[20], char tempadd[50], long long int tempphone, char tempemail[50]) {
    
    //firstname = NULL;
    strcpy (firstname, tempname1);
    //lastname = NULL;
    strcpy (lastname, tempname2);
    //address =  NULL;
    strcpy (address, tempadd);
    phone = tempphone;
    //email = NULL;
    strcpy (email, tempemail);
    
    return 1;
}
//completed
void Patron::PrintEachPatron() {
    if (patronID != -1) {
        cout << firstname << " " << lastname << "\nID:" << patronID << "\naddress: " << address << "\nphone#: "<< phone << "\nemail: "<< email << endl;
    }
}

//completed
int Patron::RemoveMe(char tempname1[50], char tempname2[20]) {
    if (strcmp(firstname, tempname1) == 0 && strcmp(lastname, tempname2) == 0) {
        patronID = -1;
        return 1;
    }
    else return 0;
}

//completed
int Patron::FindMe(char tempname1[50], char tempname2[20]) {
    if (strcmp(firstname, tempname1) == 0 && strcmp(lastname, tempname2) == 0) {
        return 1;
    }
    else return 0;
}

int Patron::SavePatron() {
    ofstream dbFile;
    dbFile.open ("Library.txt", ios::ate | ios::app);
    
    dbFile << firstname << endl;
    dbFile << lastname << endl;
    dbFile << address << endl;
    dbFile << phone << endl;
    dbFile << email << endl;
    dbFile << bookCon1 << endl;
    dbFile << bookCon2 << endl;
    dbFile << bookCon3 << endl;
    dbFile << bookCon4 << endl;
    
    dbFile.close();
    
    return 1;
}


