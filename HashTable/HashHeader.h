/*
 *Name: Travis Allan
 *Date: 11/11/2014
 *Course: CSCE 3110
 *Assignment: Program 2
 */

#define TABLE_SIZE 17
#define MAX_DIST 4

class Hash {
    int item, hop4, hop3, hop2, hop1;
public:
    void Initialize();
    int ChangeHop(char hop);
    int InsertVal(int tempVal);
    int DeleteVal(int tempVal);
    int CheckVal(int tempVal);
    int PrintVal(int tempVal);
};
