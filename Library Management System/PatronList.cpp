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
#include <cstring>
#include <fstream>
#include "tempHeader.h"
using namespace std;



//completed
int PatronList::FindBook(char tempname1[50]) {
    PatronWalk = PatronHead; //based on algorithm
    while (PatronWalk != NULL) { //based on algorithm
        if (strcmp(PatronWalk->bookCon1, tempname1) == 0 || strcmp(PatronWalk->bookCon1, tempname1) == 0 || strcmp(PatronWalk->bookCon1, tempname1) == 0 || strcmp(PatronWalk->bookCon3, tempname1) == 0) {
            PatronWalk->PrintEachPatron();
            cout << "has this book" << endl;
            return 1;
        }
        else PatronWalk = PatronWalk->NextPatron; //based on algorithm
    }
    return 0;
}

//completed
int PatronList::CheckOut(char tempname1[50], char tempname2[20], char tempname3[50]) {
    PatronWalk = PatronHead; //based on algorithm
    while (PatronWalk != NULL) { //based on algorithm
        if (PatronWalk->FindMe(tempname1, tempname2) == 1) {
            if (strcmp(PatronWalk->bookCon1, "empty") == 0) {
                strcpy(PatronWalk->bookCon1, tempname3);
                return 1;
            }
            else {
                if (strcmp(PatronWalk->bookCon2, "empty") == 0) {
                    strcpy(PatronWalk->bookCon2, tempname3);
                    return 1;
                }
                else {
                    if (strcmp(PatronWalk->bookCon3, "empty") == 0) {
                        strcpy(PatronWalk->bookCon3, tempname3);
                        return 1;
                    }
                    else {
                        if (strcmp(PatronWalk->bookCon4, "empty") == 0) {
                            strcpy(PatronWalk->bookCon4, tempname3);
                            return 1;
                        }
                        else return 2;
                    }
                }
            }
            return 1;
        }
        else PatronWalk = PatronWalk->NextPatron; //based on algorithm
    }
    return 0;
}

//completed
int PatronList::ReturnBooks(char tempname1[50], char tempname2[20]) {
    PatronWalk = PatronHead; //based on algorithm
    while (PatronWalk != NULL) { //based on algorithm
        if (PatronWalk->FindMe(tempname1, tempname2) == 1) {
            strcpy(PatronWalk->bookCon1, "empty");
            strcpy(PatronWalk->bookCon2, "empty");
            strcpy(PatronWalk->bookCon3, "empty");
            strcpy(PatronWalk->bookCon4, "empty");
            return 1;
        }
        else PatronWalk = PatronWalk->NextPatron; //based on algorithm
    }
    return 0;
}

//completed
int PatronList::AddPatron(char tempname1[50], char tempname2[20], char tempadd[50], long long int tempphone, char tempemail[50], int patronCount) {
    if (patronCount == 1) {
        PatronHead = new Patron; //based on algorithm
        PatronHead->NextPatron = NULL; //based on algorithm
        PatronTail = PatronHead; //based on algorithm
        //cout << "check1" << endl;
    }
    else if (patronCount > 1) {
        PatronTail->NextPatron = new Patron; //based on algorithm
        PatronTail = PatronTail->NextPatron; //based on algorithm
        //cout << "Altcheck1" << endl;
    }
    PatronTail->EditPatron(tempname1, tempname2, tempadd, tempphone, tempemail);
    PatronTail->patronID = patronCount;
    strcpy(PatronTail->bookCon1, "empty");
    strcpy(PatronTail->bookCon2, "empty");
    strcpy(PatronTail->bookCon3, "empty");
    strcpy(PatronTail->bookCon4, "empty");
    
    return 1;
}

//completed
int PatronList::RemovePatron(char tempname1[50], char tempname2[20], long long int tempphone) {
    PatronWalk = PatronHead; //based on algorithm
    while (PatronWalk != NULL) { //based on algorithm
        if (PatronWalk->RemoveMe(tempname1, tempname2) == 1) {
            return 1;
        }
        else PatronWalk = PatronWalk->NextPatron; //based on algorithm
    }
    return 0;
}

//completed
void PatronList::PrintPatron() {
    PatronWalk = PatronHead; //based on algorithm
    while (PatronWalk != NULL) { //based on algorithm
        
        PatronWalk->PrintEachPatron(); //based on algorithm
        PatronWalk = PatronWalk->NextPatron; //based on algorithm
    }
}
int PatronList::Edit(char tempname1[20], char tempname2[20], char tempadd[50], long long int tempphone, char tempemail[50]) {
    
    PatronWalk = PatronHead; //based on algorithm
    while (PatronWalk != NULL) { //based on algorithm
        if (PatronWalk->FindMe(tempname1, tempname2) == 1) {
            PatronWalk->EditPatron(tempname1, tempname2, tempadd, tempphone, tempemail); //based on algorithm
            return 1;
        }
        else PatronWalk = PatronWalk->NextPatron; //based on algorithm
    }
    return 0;
}
int PatronList::LoadDB(int patronCount) {
    int i;
    char a[50];
    char b[20];
    char c[50];
    int d;
    char e[50];
    char f[50];
    char g[50];
    char h[50];
    char j[50];
    ifstream dbFile;
    dbFile.open ("Library.txt", ios::in);
    dbFile >> patronCount;
    for (i=1; i <= patronCount; i++) {
        if (i == 1) {
            PatronHead = new Patron; //based on algorithm
            PatronHead->NextPatron = NULL; //based on algorithm
            PatronTail = PatronHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (i > 1) {
            PatronTail->NextPatron = new Patron; //based on algorithm
            PatronTail = PatronTail->NextPatron; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        dbFile >> a;
        dbFile >> b;
        dbFile >> c;
        dbFile >> d;
        dbFile >> e;
        dbFile >> f;
        dbFile >> g;
        dbFile >> h;
        dbFile >> j;
        
        PatronTail->EditPatron(a, b, c, d, e);
        PatronTail->patronID = i;
        strcpy(PatronTail->bookCon1, f);
        strcpy(PatronTail->bookCon2, g);
        strcpy(PatronTail->bookCon3, h);
        strcpy(PatronTail->bookCon4, j);
    }
    dbFile.close();
    return patronCount;
    
}
int PatronList::SaveDB(int patronCount) {
    ofstream dbFile;
    dbFile.open ("Library.txt", ios::trunc);
    dbFile << patronCount << endl;
    dbFile.close();
    
    PatronWalk = PatronHead; //based on algorithm
    while (PatronWalk != NULL) { //based on algorithm
        if (PatronWalk->SavePatron() != 1) {
            return 0;
        }
        PatronWalk = PatronWalk->NextPatron; //based on algorithm
    }

    return 1;
    
}
