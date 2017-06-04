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
int BookList::AddBook(char mediaType[20], char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine, int bookCount, int refCount, int DVDCount, int botCount) {
    if (strcmp(mediaType, "Book") == 0) {
        bookCount++;
        if (bookCount == 1) {
            BookHead = new Book; //based on algorithm
            BookHead->NextBook = NULL; //based on algorithm
            BookTail = BookHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (bookCount > 1) {
            BookTail->NextBook = new Book; //based on algorithm
            BookTail = BookTail->NextBook; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        BookTail->EditBook(tempname1, tempgenre, tempstatus, loantime, tempfine);
        BookTail->bookID = bookCount;
        BookTail->month = 14;
        BookTail->day = 34;
        BookTail->year = 4000;
    
        return bookCount;
    }
    else if (strcmp(mediaType, "Reference") == 0) {
        refCount++;
        if (refCount == 1) {
            RefHead = new Reference; //based on algorithm
            RefHead->NextRef = NULL; //based on algorithm
            RefTail = RefHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (refCount > 1) {
            RefTail->NextRef = new Reference; //based on algorithm
            RefTail = RefTail->NextRef; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        RefTail->EditBook(tempname1, tempgenre, tempstatus, loantime, tempfine);
        RefTail->refID = bookCount;
        RefTail->month = 14;
        RefTail->day = 34;
        RefTail->year = 4000;
        
        return refCount;
    }
    else if (strcmp(mediaType, "DVD") == 0) {
        DVDCount++;
        if (DVDCount == 1) {
            DVDHead = new DVD; //based on algorithm
            DVDHead->NextDVD = NULL; //based on algorithm
            DVDTail =DVDHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (DVDCount > 1) {
            DVDTail->NextDVD = new DVD; //based on algorithm
            DVDTail = DVDTail->NextDVD; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        DVDTail->EditBook(tempname1, tempgenre, tempstatus, loantime, tempfine);
        DVDTail->DVDid = DVDCount;
        DVDTail->month = 14;
        DVDTail->day = 34;
        DVDTail->year = 4000;
        
        return DVDCount;
    }
    else if (strcmp(mediaType, "Book-on-Tape") == 0) {
        botCount++;
        if (botCount == 1) {
            BotHead = new BookonTape; //based on algorithm
            BotHead->NextBot = NULL; //based on algorithm
            BotTail = BotHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (botCount > 1) {
            BotTail->NextBot = new BookonTape; //based on algorithm
            BotTail = BotTail->NextBot; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        BotTail->EditBook(tempname1, tempgenre, tempstatus, loantime, tempfine);
        BotTail->botID = botCount;
        BotTail->month = 14;
        BotTail->day = 34;
        BotTail->year = 4000;
        
        return botCount;
    }

    return 0;
}

//completed
int BookList::RemoveBook(char mediaType[20], char tempname1[50]) {
    if (strcmp(mediaType, "Book") == 0) {
    BookWalk = BookHead; //based on algorithm
        while (BookWalk != NULL) { //based on algorithm
            if (BookWalk->RemoveMe(tempname1) == 1) {
                return 1;
            }
            else BookWalk = BookWalk->NextBook; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Reference") == 0) {
        RefWalk = RefHead; //based on algorithm
        while (RefWalk != NULL) { //based on algorithm
            if (RefWalk->RemoveMe(tempname1) == 1) {
                return 1;
            }
            else RefWalk = RefWalk->NextRef; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "DVD") == 0) {
        DVDWalk = DVDHead; //based on algorithm
        while (DVDWalk != NULL) { //based on algorithm
            if (DVDWalk->RemoveMe(tempname1) == 1) {
                return 1;
            }
            else DVDWalk = DVDWalk->NextDVD; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Book-on-Tape") == 0) {
        BotWalk = BotHead; //based on algorithm
        while (BotWalk != NULL) { //based on algorithm
            if (BotWalk->RemoveMe(tempname1) == 1) {
                return 1;
            }
            else BotWalk = BotWalk->NextBot; //based on algorithm
        }
    }

    return 0;
}

//completed
int BookList::StatusUpdate(char mediaType[20], char tempname1[50], char tempstatus[10]) {
    if (strcmp(mediaType, "Book") == 0) {
        BookWalk = BookHead; //based on algorithm
        while (BookWalk != NULL) { //based on algorithm
            if (BookWalk->Update(tempname1, tempstatus) == 1) {
                return 1;
            }
            else BookWalk = BookWalk->NextBook; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Reference") == 0) {
        RefWalk = RefHead; //based on algorithm
        while (RefWalk != NULL) { //based on algorithm
            if (RefWalk->Update(tempname1, tempstatus) == 1) {
                return 1;
            }
            else RefWalk = RefWalk->NextRef; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "DVD") == 0) {
        DVDWalk = DVDHead; //based on algorithm
        while (DVDWalk != NULL) { //based on algorithm
            if (DVDWalk->Update(tempname1, tempstatus) == 1) {
                return 1;
            }
            else DVDWalk = DVDWalk->NextDVD; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Book-on-Tape") == 0) {
        BotWalk = BotHead; //based on algorithm
        while (BotWalk != NULL) { //based on algorithm
            if (BotWalk->Update(tempname1, tempstatus) == 1) {
                return 1;
            }
            else BotWalk = BotWalk->NextBot; //based on algorithm
        }
    }

    return 0;
}

//completed
void BookList::PrintBook() {
    BookWalk = BookHead; //based on algorithm
    while (BookWalk != NULL) { //based on algorithm
        BookWalk->PrintEachBook();
        BookWalk = BookWalk->NextBook; //based on algorithm
    }
    RefWalk = RefHead; //based on algorithm
    while (RefWalk != NULL) { //based on algorithm
        RefWalk->PrintEachBook();
        RefWalk = RefWalk->NextRef; //based on algorithm
    }
    DVDWalk = DVDHead; //based on algorithm
    while (DVDWalk != NULL) { //based on algorithm
        DVDWalk->PrintEachBook();
        DVDWalk = DVDWalk->NextDVD; //based on algorithm
    }
    BotWalk = BotHead; //based on algorithm
    while (BotWalk != NULL) { //based on algorithm
        BotWalk->PrintEachBook();
        BotWalk = BotWalk->NextBot; //based on algorithm
    }

}

//completed
int BookList::CheckOut(char mediaType[20], char tempname1[50], char tempname2[20], char tempname3[50], int month, int day, int year) {
    if (strcmp(mediaType, "Book") == 0) {
        BookWalk = BookHead; //based on algorithm
        while (BookWalk != NULL) { //based on algorithm
            if (BookWalk->Update(tempname3, "checkedOut") == 1) {
                BookWalk->month = month;
                BookWalk->day = day;
                BookWalk->year = year;
                strcpy (BookWalk->firstnameCon, tempname1);
                strcpy (BookWalk->lastnameCon, tempname2);
                return 1;
            }
            else BookWalk = BookWalk->NextBook; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Reference") == 0) {
        RefWalk = RefHead; //based on algorithm
        while (RefWalk != NULL) { //based on algorithm
            if (RefWalk->Update(tempname3, "checkedOut") == 1) {
                RefWalk->month = month;
                RefWalk->day = day;
                RefWalk->year = year;
                strcpy (RefWalk->firstnameCon, tempname1);
                strcpy (RefWalk->lastnameCon, tempname2);
                return 1;
            }
            else RefWalk = RefWalk->NextRef; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "DVD") == 0) {
        DVDWalk = DVDHead; //based on algorithm
        while (DVDWalk != NULL) { //based on algorithm
            if (DVDWalk->Update(tempname3, "checkedOut") == 1) {
                DVDWalk->month = month;
                DVDWalk->day = day;
                DVDWalk->year = year;
                strcpy (DVDWalk->firstnameCon, tempname1);
                strcpy (DVDWalk->lastnameCon, tempname2);
                return 1;
            }
            else DVDWalk = DVDWalk->NextDVD; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Book-on-Tape") == 0) {
        BotWalk = BotHead; //based on algorithm
        while (BotWalk != NULL) { //based on algorithm
            if (BotWalk->Update(tempname3, "checkedOut") == 1) {
                BotWalk->month = month;
                BotWalk->day = day;
                BotWalk->year = year;
                strcpy (BotWalk->firstnameCon, tempname1);
                strcpy (BotWalk->lastnameCon, tempname2);
                return 1;
            }
            else BotWalk = BotWalk->NextBot; //based on algorithm
        }
    }

    return 0;
}

//completed
int BookList::ReturnBooks(char mediaType[20], char tempname1[50], char tempname2[20], char tempname3[50]) {
    if (strcmp(mediaType, "Book") == 0) {
        BookWalk = BookHead; //based on algorithm
        while (BookWalk != NULL) { //based on algorithm
            if (BookWalk->Update(tempname3, "checkedIn") == 1) {
                BookWalk->month = 14;
                BookWalk->day = 34;
                BookWalk->year = 4000;
                strcpy(BookWalk->firstnameCon, tempname1);
                strcpy(BookWalk->lastnameCon, tempname2);
                return 1;
            }
            else BookWalk = BookWalk->NextBook; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Reference") == 0) {
        RefWalk = RefHead; //based on algorithm
        while (RefWalk != NULL) { //based on algorithm
            if (RefWalk->Update(tempname3, "checkedIn") == 1) {
                RefWalk->month = 14;
                RefWalk->day = 34;
                RefWalk->year = 4000;
                strcpy (RefWalk->firstnameCon, tempname1);
                strcpy (RefWalk->lastnameCon, tempname2);
                return 1;
            }
            else RefWalk = RefWalk->NextRef; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "DVD") == 0) {
        DVDWalk = DVDHead; //based on algorithm
        while (DVDWalk != NULL) { //based on algorithm
            if (DVDWalk->Update(tempname3, "checkedIn") == 1) {
                DVDWalk->month = 14;
                DVDWalk->day = 34;
                DVDWalk->year = 4000;
                strcpy (DVDWalk->firstnameCon, tempname1);
                strcpy (DVDWalk->lastnameCon, tempname2);
                return 1;
            }
            else DVDWalk = DVDWalk->NextDVD; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Book-on-Tape") == 0) {
        BotWalk = BotHead; //based on algorithm
        while (BotWalk != NULL) { //based on algorithm
            if (BotWalk->Update(tempname3, "checkedIn") == 1) {
                BotWalk->month = 14;
                BotWalk->day = 34;
                BotWalk->year = 4000;
                strcpy (BotWalk->firstnameCon, tempname1);
                strcpy (BotWalk->lastnameCon, tempname2);
                return 1;
            }
            else BotWalk = BotWalk->NextBot; //based on algorithm
        }
    }

    return 0;
}

//complete
int BookList::OverdueBooks(char mediaType[20], int month, int day, int year, int loantime) {
    if (strcmp(mediaType, "Book") == 0) {
        BookWalk = BookHead; //based on algorithm
        while (BookWalk != NULL) { //based on algorithm
            if (BookWalk->month < month || BookWalk->day+loantime < day || BookWalk->year < year) {
            
                //print book
                BookWalk->PrintEachBook();
                return 1;
            }
            else BookWalk = BookWalk->NextBook; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Reference") == 0) {
        RefWalk = RefHead; //based on algorithm
        while (RefWalk != NULL) { //based on algorithm
            if (RefWalk->month < month || RefWalk->day+loantime < day || RefWalk->year < year) {
                
                //print book
                RefWalk->PrintEachBook();
                return 1;
            }
            else RefWalk = RefWalk->NextRef; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "DVD") == 0) {
        DVDWalk = DVDHead; //based on algorithm
        while (DVDWalk != NULL) { //based on algorithm
            if (DVDWalk->month < month || DVDWalk->day+loantime < day || DVDWalk->year < year) {
                
                //print book
                DVDWalk->PrintEachBook();
                return 1;
            }
            else DVDWalk = DVDWalk->NextDVD; //based on algorithm
        }
    }
    else if (strcmp(mediaType, "Book-on-Tape") == 0) {
        BotWalk = BotHead; //based on algorithm
        while (BotWalk != NULL) { //based on algorithm
            if (BotWalk->month < month || BotWalk->day+loantime < day || BotWalk->year < year) {
                
                //print book
                BotWalk->PrintEachBook();
                return 1;
            }
            else BotWalk = BotWalk->NextBot; //based on algorithm
        }
    }

    return 0;
}


int BookList::OverduePatrons(int month, int day, int year, int loantime) {
    BookWalk = BookHead; //based on algorithm
    while (BookWalk != NULL) { //based on algorithm
        if (BookWalk->month < month || BookWalk->day+loantime < day || BookWalk->year < year) {
            
            //print book
            cout << BookWalk->firstnameCon << " " << BookWalk->lastnameCon << " Fine: $" << BookWalk->fine << endl;
            return 1;
        }
        else BookWalk = BookWalk->NextBook; //based on algorithm
    }
    
    return 0;
    
}

int BookList::Edit(char mediaType[20], char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine) {
    if (strcmp(mediaType, "Book") == 0) {
        BookWalk = BookHead; //based on algorithm
        while (BookWalk != NULL) { //based on algorithm
            if (BookWalk->FindMe(tempname1) == 1) {
                cout << "Please enter the book's new data" << endl;
                cout << "Name: ";
                cin >> tempname1;
                cout << "Genre: ";
                cin >> tempgenre;
                cout << "Status: ";
                cin >> tempstatus;
                cout << "Loanable time: ";
                cin >> loantime;
                cout << "fine:";
                cin >> tempfine;
                BookWalk->EditBook(tempname1, tempgenre, tempstatus, loantime, tempfine);
                return 1;
            }
            else BookWalk = BookWalk->NextBook; //based on algorithm
        }
    }
    return 0;
}


int BookList::LoadDB(int bookCount) {
    int i;
    char z[50]; //name
    char y[10]; //genre
    int x; //checkout
    char w[10]; //status
    char v[20]; //fnc
    char u[20]; //lnc
    int t; //fine
    int s; //month
    int r; //day
    int q; //year
    ifstream dbFile1;
    dbFile1.open ("Book.txt", ios::in);
    dbFile1 >> bookCount;
    for (i=1; i <= bookCount; i++) {
        if (i == 1) {
            BookHead = new Book; //based on algorithm
            BookHead->NextBook = NULL; //based on algorithm
            BookTail = BookHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (i > 1) {
            BookTail->NextBook = new Book; //based on algorithm
            BookTail = BookTail->NextBook; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        dbFile1 >> z;
        dbFile1 >> y;
        dbFile1 >> x;
        dbFile1 >> w;
        dbFile1 >> v;
        dbFile1 >> u;
        dbFile1 >> t;
        dbFile1 >> s;
        dbFile1 >> r;
        dbFile1 >> q;
        
        BookTail->EditBook(z, y, w, x, t);
        BookTail->bookID = i;
        BookTail->month = s;
        BookTail->day = r;
        BookTail->year = q;
        strcpy(BookTail->firstnameCon, v);
        strcpy(BookTail->lastnameCon, u);
    }
    dbFile1.close();
    return bookCount;

}

int BookList::LoadDBr(int refCount) {
    int i;
    char z[50]; //name
    char y[10]; //genre
    int x; //checkout
    char w[10]; //status
    char v[20]; //fnc
    char u[20]; //lnc
    int t; //fine
    int s; //month
    int r; //day
    int q; //year
    ifstream dbFile2;
    dbFile2.open ("Reference.txt", ios::in);
    dbFile2 >> refCount;
    for (i=1; i <= refCount; i++) {
        if (i == 1) {
            RefHead = new Reference; //based on algorithm
            RefHead->NextRef = NULL; //based on algorithm
            RefTail = RefHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (i > 1) {
            RefTail->NextRef = new Reference; //based on algorithm
            RefTail = RefTail->NextRef; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        dbFile2 >> z;
        dbFile2 >> y;
        dbFile2 >> x;
        dbFile2 >> w;
        dbFile2 >> v;
        dbFile2 >> u;
        dbFile2 >> t;
        dbFile2 >> s;
        dbFile2 >> r;
        dbFile2 >> q;
        
        RefTail->EditBook(z, y, w, x, t);
        RefTail->refID = i;
        RefTail->month = s;
        RefTail->day = r;
        RefTail->year = q;
        strcpy(RefTail->firstnameCon, v);
        strcpy(RefTail->lastnameCon, u);
    }
    dbFile2.close();
    return refCount;
    
}

int BookList::LoadDBd(int DVDCount) {
    int i;
    char z[50]; //name
    char y[10]; //genre
    int x; //checkout
    char w[10]; //status
    char v[20]; //fnc
    char u[20]; //lnc
    int t; //fine
    int s; //month
    int r; //day
    int q; //year
    ifstream dbFile1;
    dbFile1.open ("DVD.txt", ios::in);
    dbFile1 >> DVDCount;
    for (i=1; i <= DVDCount; i++) {
        if (i == 1) {
            DVDHead = new DVD; //based on algorithm
            DVDHead->NextDVD = NULL; //based on algorithm
            DVDTail = DVDHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (i > 1) {
            DVDTail->NextDVD = new DVD; //based on algorithm
            DVDTail = DVDTail->NextDVD; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        dbFile1 >> z;
        dbFile1 >> y;
        dbFile1 >> x;
        dbFile1 >> w;
        dbFile1 >> v;
        dbFile1 >> u;
        dbFile1 >> t;
        dbFile1 >> s;
        dbFile1 >> r;
        dbFile1 >> q;
        
        DVDTail->EditBook(z, y, w, x, t);
        DVDTail->DVDid = i;
        DVDTail->month = s;
        DVDTail->day = r;
        DVDTail->year = q;
        strcpy(DVDTail->firstnameCon, v);
        strcpy(DVDTail->lastnameCon, u);
    }
    dbFile1.close();
    return DVDCount;
    
}

int BookList::LoadDBbot(int botCount) {
    int i;
    char z[50]; //name
    char y[10]; //genre
    int x; //checkout
    char w[10]; //status
    char v[20]; //fnc
    char u[20]; //lnc
    int t; //fine
    int s; //month
    int r; //day
    int q; //year
    ifstream dbFile1;
    dbFile1.open ("Book-on-Tape.txt", ios::in);
    dbFile1 >> botCount;
    for (i=1; i <= botCount; i++) {
        if (i == 1) {
            BotHead = new BookonTape; //based on algorithm
            BotHead->NextBot = NULL; //based on algorithm
            BotTail = BotHead; //based on algorithm
            //cout << "check1" << endl;
        }
        else if (i > 1) {
            BotTail->NextBot = new BookonTape; //based on algorithm
            BotTail = BotTail->NextBot; //based on algorithm
            //cout << "Altcheck1" << endl;
        }
        dbFile1 >> z;
        dbFile1 >> y;
        dbFile1 >> x;
        dbFile1 >> w;
        dbFile1 >> v;
        dbFile1 >> u;
        dbFile1 >> t;
        dbFile1 >> s;
        dbFile1 >> r;
        dbFile1 >> q;
        
        BotTail->EditBook(z, y, w, x, t);
        BotTail->botID = i;
        BotTail->month = s;
        BotTail->day = r;
        BotTail->year = q;
        strcpy(BotTail->firstnameCon, v);
        strcpy(BotTail->lastnameCon, u);
    }
    dbFile1.close();
    return botCount;
    
}


int BookList::SaveDB(int bookCount, int refCount, int DVDCount, int botCount) {
    ofstream dbFile1;
    dbFile1.open ("Book.txt", ios::trunc);
    dbFile1 << bookCount << endl;
    dbFile1.close();
    
    dbFile1.open ("Reference.txt", ios::trunc);
    dbFile1 << refCount << endl;
    dbFile1.close();
    
    dbFile1.open ("DVD.txt", ios::trunc);
    dbFile1 << DVDCount << endl;
    dbFile1.close();
    
    dbFile1.open ("Book-on-Tape.txt", ios::trunc);
    dbFile1 << botCount << endl;
    dbFile1.close();
    
    BookWalk = BookHead; //based on algorithm
    while (BookWalk != NULL) { //based on algorithm
        if (BookWalk->SaveBook() != 1) {
            return 0;
        }
        BookWalk = BookWalk->NextBook; //based on algorithm
    }

    RefWalk = RefHead; //based on algorithm
    while (RefWalk != NULL) { //based on algorithm
        if (RefWalk->SaveBook() != 1) {
            return 0;
        }
        RefWalk = RefWalk->NextRef; //based on algorithm
    }

    DVDWalk = DVDHead; //based on algorithm
    while (DVDWalk != NULL) { //based on algorithm
        if (DVDWalk->SaveBook() != 1) {
            return 0;
        }
        DVDWalk = DVDWalk->NextDVD; //based on algorithm
    }

    BotWalk = BotHead; //based on algorithm
    while (BotWalk != NULL) { //based on algorithm
        if (BotWalk->SaveBook() != 1) {
            return 0;
        }
        BotWalk = BotWalk->NextBot; //based on algorithm
    }

    return 1;
    
}
