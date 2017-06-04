/*
 *Name: Travis Allan
 *Date: 7/27/2014
 *Course: CSCE 1040
 *Title: Program 5
 *Description: Library Database
 */

//headers
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "tempHeader.h"
using namespace std;


//main
int main() {

    //value declarations
    int comm, month, day, year, loantime, tempfine, bookCount, patronCount, refCount, DVDCount, botCount;
    char tempname1[50];
    char tempname2[20];
    char tempname3[50];
    char tempstatus[10];
    char tempgenre[10];
    long long int tempphone;
    char tempadd[50];
    char tempemail[50];
    char mediaType[20];
    
    PatronList Patrons;
    BookList Books;
    
    //title information
    cout << "Travis Allan" << endl;
    cout << "7/27/2014" << endl;
    cout << "CSCE1040" << endl;
    cout << "Homework 6" << endl;
    cout << "Library Management System " << endl;
    
    //setting statistics
    cout << "These are default settings. They can be changed for specific items with the edit media command" << endl;
    cout << "What is the loan period for media?(days)" << endl;
    cin >> loantime;
    cout << "What is the fine for late media?" << endl;
    cin >> tempfine;
    cout << "What is today's date?(month day year)" << endl;
    cin >> month >> day >> year;
    
    //menu printout
    cout << "------Menu------" << endl;
    cout << "0. change Date" << endl;
    cout << "1. Add Media" << endl;
    cout << "2. Remove Media" << endl;
    cout << "3. Status Update" << endl;
    cout << "4. Print Media" << endl;
    cout << "5. Print Overdue Media" << endl;
    cout << "6. Find an item" << endl;
    cout << "7. Check Out Media" << endl;
    cout << "8. Edit Media" << endl;
    cout << "9. Add a Patron" << endl;
    cout << "10. Remove a Patron" << endl;
    cout << "11. Print a List of Patrons" << endl;
    cout << "12. Print All Patrons with Fines" << endl;
    cout << "13. Return Media" << endl;
    cout << "14. Edit a Patron's Personal Information" << endl;
    cout << "15. Log Off" << endl;
    
    
    //may be automated
    //cout << "Load Database" << endl;
    //cout << "Save Database" << endl;
    bookCount = 0;
    patronCount = 0;
    refCount = 0;
    DVDCount = 0;
    botCount = 0;
    
    patronCount = Patrons.LoadDB(patronCount);
    bookCount = Books.LoadDB(bookCount);
    refCount = Books.LoadDBr(refCount);
    DVDCount = Books.LoadDBd(DVDCount);
    botCount = Books.LoadDBbot(botCount);
    
    do {
        cout << "LibraryDB>";
        cin >> comm;
        if (comm == 0) {
            cout << "what is the date?(month day year)" << endl;
            cin >> month >> day >> year;

        }
        else if (comm == 1) {
            cout << "What is the media type?" << endl;
            cin >> mediaType;
            cout << "Please enter name(no spaces in name) and genre" << endl;
            cin >> tempname1 >> tempgenre;
            strcpy (tempstatus, "new");
            //cout << "check0" << endl;
            if (Books.AddBook(mediaType, tempname1, tempgenre, tempstatus, loantime, tempfine, bookCount, refCount, DVDCount, botCount) == 0) {
                cout << "Error3: Media not added" << endl;
            }
        }
        else if (comm == 2) {
            cout << "What is the media type?" << endl;
            cin >> mediaType;
            cout << "Please enter name(no spaces in name)" << endl;
            cin >> tempname1;
            if (Books.RemoveBook(mediaType, tempname1) != 1) {
                cout << "Error2: Media not removed" << endl;
            }
        }
        else if (comm == 3) {
            cout << "What is the media type?" << endl;
            cin >> mediaType;
            cout << "Please enter the name of the book(no spaces in name) and status" << endl;
            cin >> tempname1 >> tempstatus;
            if (Books.StatusUpdate(mediaType, tempname1, tempstatus) != 1) {
                cout << "Error4: Media not found" << endl;
            }
        }
        else if (comm == 4) {
            Books.PrintBook();
        }
        else if (comm == 5) {
            cout << "What is the media type?" << endl;
            cin >> mediaType;
            if (Books.OverdueBooks(mediaType, month, day, year, loantime) != 1) {
                cout << "There are no items overdue." << endl;
            }
        }
        else if (comm == 6) {
            //cout << "What is the media type?" << endl;
            //cin >> mediaType;
            
            cout << "Please enter the name of the media(no spaces)." << endl;
            cin >> tempname1;
            if (Patrons.FindBook(tempname1) == 1) {
                //cout << "Process completed successfully." << endl;
            }
            else cout << "checked in" << endl;
        }
        else if (comm == 7) {
            cout << "Please enter the Patron's data" << endl;
            cout << "firstname:";
            cin >> tempname1;
            cout << "lastname:";
            cin >> tempname2;
            cout << "media name:";
            cin >> tempname3;
            cout << "What is the media type?" << endl;
            cin >> mediaType;
            if (Patrons.CheckOut(tempname1, tempname2, tempname3) == 1 && Books.CheckOut(mediaType, tempname1, tempname2, tempname3, month, day, year) != 1) {
                cout << "patron or book isnt registered" << endl;
            }
        }
        else if (comm == 8) {
            cout << "What is the media type?" << endl;
            cin >> mediaType;
            
            cout << "Please enter the name of the book(no spaces)" << endl;
            cin >> tempname1;
            if (Books.Edit(mediaType, tempname1, tempgenre, tempstatus, loantime, tempfine) != 1) {
                cout << "Error4: Media not found" << endl;
            }

        }
        else if (comm == 9) {
            patronCount++;
            cout << "Please enter the following" << endl;
            cout << "first name:" << endl;
            cin >> tempname1;
            cout << "last name:" << endl;
            cin >> tempname2;
            cout << "address(no spaces):" << endl;
            cin >> tempadd;
            cout << "phone#:" << endl;
            cin >> tempphone;
            cout << "email:" << endl;
            cin >> tempemail;
            if (Patrons.AddPatron(tempname1, tempname2, tempadd, tempphone, tempemail, patronCount) != 1) {
                cout << "Error5: Patron not added" << endl;
            }
        }
        else if (comm == 10) {
            cout << "Please enter the following" << endl;
            cout << "first name:" << endl;
            cin >> tempname1;
            cout << "last name:" << endl;
            cin >> tempname2;
            cout << "phone#:" << endl;
            cin >> tempphone;
            if (Patrons.RemovePatron(tempname1, tempname2, tempphone) != 1) {
                cout << "Error6: Patron not found" << endl;
            }
        }
        else if (comm == 11) {
            Patrons.PrintPatron();
        }
        else if (comm == 12) {
            
            if (Books.OverduePatrons(month, day, year, loantime) != 1) {
                cout << "There are no patrons with outstanding fines" << endl;
            }
        }
        else if (comm == 13) {
            cout << "Please enter the Patron's data" << endl;
            cout << "firstname:";
            cin >> tempname1;
            cout << "lastname:";
            cin >> tempname2;
            cout << "media name:";
            cin >> tempname3;
            cout << "What is the media type?" << endl;
            cin >> mediaType;
            if (Patrons.ReturnBooks(tempname1, tempname2) == 1 && Books.ReturnBooks(mediaType, tempname1, tempname2, tempname3) != 1) {
                cout << "Error7: Process couldn't be completed" << endl;
            }
        }
        else if (comm == 14) {
            cout << "Please enter the following" << endl;
            cout << "first name:" << endl;
            cin >> tempname1;
            cout << "last name:" << endl;
            cin >> tempname2;
            cout << "address(no spaces):" << endl;
            cin >> tempadd;
            cout << "phone#:" << endl;
            cin >> tempphone;
            cout << "email:" << endl;
            cin >> tempemail;
            if (Patrons.Edit(tempname1, tempname2, tempadd, tempphone, tempemail) != 1) {
                cout << "Error6: Patron not found" << endl;
            }
        }

        else if (comm == 15) {
            if (Patrons.SaveDB(patronCount) == 1 && Books.SaveDB(bookCount,refCount, DVDCount, botCount) == 1) {
                cout << "Database saved successfully." << endl;
            }
            else cout << "Error8: database did not save, and all data was lost." << endl;
        }
        else cout << "Error#1: The command recieved is not supported." << endl;

    }while (comm != 15);
    
    return 0;
}
