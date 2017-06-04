class Book {
protected:
    char bookname[50];
    
    char genre[10];
    int checkoutperiod;
    
    
    char status[10];
public:
    int bookID;
    char firstnameCon[20];
    char lastnameCon[20];
    int fine;
    int month;
    int day;
    int year;
    Book* NextBook;
    
    virtual int EditBook(char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine);
    virtual int RemoveMe(char tempname1[50]);
    virtual int FindMe(char tempname3[50]);
    virtual void PrintEachBook();
    virtual int Update(char tempname1[50], char tempstatus[20]);
    virtual int SaveBook();
};

class DVD : public Book {
private:
    char DVDname[50];
    char genre[10];
    int checkoutperiod;
    char status[10];
public:
    int DVDid;
    char firstnameCon[50];
    char lastnameCon[20];
    int fine;
    int month;
    int day;
    int year;
    DVD* NextDVD;
    
    //int EditBook(char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine);
    //int RemoveMe(char tempname1[50]);
    //int FindMe(char tempname3[50]);
    //void PrintEachBook();
    //int Update(char tempname1[50], char tempstatus[20]);
    //int SaveBook();
    
};

class BookonTape : public Book {
private:
    char botname[50];
    char genre[10];
    int checkoutperiod;
    char status[10];
    
public:
    int botID;;
    char firstnameCon[50];
    char lastnameCon[20];
    int fine;
    int month;
    int day;
    int year;
    BookonTape* NextBot;
    
    /*int EditBook(char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine);
    int RemoveMe(char tempname1[50]);
    int FindMe(char tempname3[50]);
    void PrintEachBook();
    int Update(char tempname1[50], char tempstatus[20]);
    int SaveBook(); */

};

class Reference : public Book{
private:
    char refname[50];
    char genre[10];
    int checkoutperiod;
    char status[10];
    
public:
    int refID;
    char firstnameCon[50];
    char lastnameCon[20];
    int fine;
    int month;
    int day;
    int year;
    Reference* NextRef;
    
    /*
    int EditBook(char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine);
    int RemoveMe(char tempname1[50]);
    int FindMe(char tempname3[50]);
    void PrintEachBook();
    int Update(char tempname1[50], char tempstatus[20]);
    int SaveBook();*/

};
class Patron {
protected:
    char firstname[50];
    char lastname[20];
    char address[50];
    int phone;
    char email[50];
    
    
public:
    Patron* NextPatron;
    int patronID;
    char bookCon1[50];
    char bookCon2[50];
    char bookCon3[50];
    char bookCon4[50];
    
    int EditPatron(char tempname1[50], char tempname2[20], char tempadd[50], long long int tempphone, char tempemail[50]);
    int RemoveMe(char tempname1[50], char tempname2[20]);
    int FindMe(char tempname1[50], char tempname2[20]);
    int SavePatron();
    void PrintEachPatron();
};

class BookList {
protected:
public:
    Book* BookHead;
    Book* BookTail;
    Book* BookWalk;
    Reference* RefHead;
    Reference* RefTail;
    Reference* RefWalk;
    DVD* DVDHead;
    DVD* DVDTail;
    DVD* DVDWalk;
    BookonTape* BotHead;
    BookonTape* BotTail;
    BookonTape* BotWalk;
    
    int AddBook(char mediaType[20], char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine, int bookCount, int refCount, int DVDcount, int botCount);
    int RemoveBook(char mediaType[20], char tempname1[50]);
    int StatusUpdate(char mediaType[20], char tempname1[50], char tempstatus[10]);
    void PrintBook();
    int OverdueBooks(char mediaType[20], int month, int day, int year, int loantime);
    int CheckOut(char mediaType[20], char tempname1[50], char tempname2[20], char tempname3[50], int month, int day, int year);
    int ReturnBooks(char mediaType[20], char tempname1[50], char tempname2[20], char tempname3[50]);
    int OverduePatrons(int month, int day, int year, int loantime);
    int Edit(char mediaType[20], char tempname1[50], char tempgenre[10], char tempstatus[10], int loantime, int tempfine);
    int LoadDB(int bookCount);
    int SaveDB(int bookCount, int refCount, int DVDCount, int botCount);
    int LoadDBr(int refCount);
    int LoadDBd(int DVDCount);
    int LoadDBbot(int botCount);
};

class PatronList {
protected:
public:
    Patron* PatronHead;
    Patron* PatronTail;
    Patron* PatronWalk;
    int AddPatron(char tempname1[50], char tempname2[20], char tempadd[50], long long int tempphone, char tempemail[50], int patronCount);
    int RemovePatron(char tempname1[50], char tempname2[20], long long int tempphone);
    void PrintPatron();
    
    int CheckOut(char tempname1[50], char tempname2[20], char tempname3[50]);
    int ReturnBooks(char tempname1[50], char tempname2[20]);
    int FindBook(char tempname1[50]);
    int Edit(char tempname1[20], char tempname2[20], char tempadd[50], long long int tempphone, char tempemail[50]);
    int LoadDB(int patronCount);
    int SaveDB(int patronCount);
};

