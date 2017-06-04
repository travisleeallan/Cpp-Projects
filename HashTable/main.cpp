/*
 *Name: Travis Allan
 *Date: 11/11/2014
 *Course: CSCE 3110
 *Assignment: Program 2
 */

#include <iostream>
#include "HashHeader.h"
using namespace std;

//main
int main() {
    int i, j, k, tempVal, location;
    char hop;
    int input = 0;
    Hash Table[TABLE_SIZE];
    
    for (i=0; i < TABLE_SIZE; i++) {
        Table[i].Initialize();
    }
    while (input != 5) {
        cout << "HOPSCOTCH HASHING MENU:\n1. Insert Value\n2. Delete Value\n3. Search Value\n4. Output Table\n5. Exit Program\nEnter Operation to perform: ";
        
        cin >> input;
        cout << endl;
        hop = 'a';
        if (input == 1) {
            //insert value
            cout << "Enter positive integer value to insert into Hopscotch Hash Table: ";
            cin >> tempVal;
            
            //hash function
            location = tempVal % TABLE_SIZE;
            //cout << location << endl; //test
            if (Table[location].InsertVal(tempVal) == 0) {
                //rehash
                hop = 'b';
                Table[location].ChangeHop(hop);
                location++;
                if (Table[location].InsertVal(tempVal) == 0) {
                    hop = 'c';
                    Table[location].ChangeHop(hop);
                    location++;
                    if (Table[location].InsertVal(tempVal) == 0) {
                        hop = 'd';
                        Table[location].ChangeHop(hop);
                        location++;
                    }
                    else cout << "Error2: hopsctoch failed" << endl;

                }
            }
            else Table[location].ChangeHop(hop);
            
        }
        else if(input == 2) {
            //delete value
            j = 0;
            cout << "Enter positive integer value to delete from Hopscotch Hash Table: ";
            cin >> tempVal;
            for (i=0; i < TABLE_SIZE; i++) {
                if (Table[i].CheckVal(tempVal)==1) {
                    Table[i].DeleteVal(tempVal);
                    k = i - 1;
                    hop = 'e';
                    Table[k].ChangeHop(hop);
                    cout << tempVal << " deleted from position " << i << "." << endl;
                }
                else j++;
            }
            if (j==TABLE_SIZE){
                cout << "Error3: Unable to delete " << tempVal << " from Hash Table: Not Found" << endl;
            }

        }
        else if(input == 3) {
            //search value
            j = 0;
            cout << "Enter positive integer value to search for in Hopscotch Hash Table: ";
            cin >> tempVal;
            for (i=0; i < TABLE_SIZE; i++) {
                if (Table[i].CheckVal(tempVal)==1) {
                    cout << tempVal << " found at position " << i << "." << endl;
                }
                else j++;
            }
            if (j==TABLE_SIZE){
                cout << "Error3: Unable to find " << tempVal << " in Hash Table: Not Found" << endl;
            }
        }
        else if(input == 4) {
            //output table
            cout << "+------------------+" << endl;
            cout << "|  # | item |  hop |" << endl;
            cout << "+------------------+" << endl;
            for (i=0; i < TABLE_SIZE; i++) {
                cout << '|';
                if (i == 0 || i < 10) cout << " ";
                Table[i].PrintVal(i);
                
            }
            cout << "+------------------+" << endl;
            cout << endl;
        }
        else if(input == 5) {
            //exit program
        }
        else cout << "Error1: Action is not supported" << endl;
    }
    return 0;
}

