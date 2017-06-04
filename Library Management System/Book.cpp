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
int Book::EditBook(char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine) {
    //cout << "check2" << endl;
    strcpy (bookname, tempname1);
    strcpy (genre, tempgenre);
    strcpy (status, tempstatus);
    checkoutperiod = loantime;
    fine = tempfine;
    return 1;
}

//completed
void Book::PrintEachBook() {
    if (bookID != -1) {
        cout  << "ID:" << bookID << " " << bookname << " " << status << endl;
    }
}
//completed
int Book::RemoveMe(char tempname1[50]) {
    if (strcmp(bookname, tempname1) == 0) {
        bookID = -1;
        return 1;
    }
    else return 0;
}

//completed
int Book::FindMe(char tempname3[50]) {
    if (strcmp(bookname, tempname3) == 0) {
        return 1;
    }
    else return 0;
}
//completed
int Book::Update(char tempname1[50], char tempstatus[20]){
    if (strcmp(bookname, tempname1) == 0) {
        strcpy(status, tempstatus);
        return 1;
    }
    else return 0;
}

int Book::SaveBook() {
    ofstream dbFile1;
    dbFile1.open ("Book.txt", ios::ate | ios::app);
    
    dbFile1 << bookname << endl;
    dbFile1 << genre << endl;
    dbFile1 << checkoutperiod << endl;
    dbFile1 << status << endl;
    dbFile1 << firstnameCon << endl;
    dbFile1 << lastnameCon << endl;
    dbFile1 << fine << endl;
    dbFile1 << month << endl;
    dbFile1 << day << endl;
    dbFile1 << year << endl;
    
    dbFile1.close();
    
    return 1;
}

