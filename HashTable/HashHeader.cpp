/*
 *Name: Travis Allan
 *Date: 11/11/2014
 *Course: CSCE 3110
 *Assignment: Program 2
 */

#include <iostream>
#include <iomanip>
#include "HashHeader.h"
using namespace std;

void Hash::Initialize(){
    item = -1;
    hop1 = 0;
    hop2 = 0;
    hop3 = 0;
    hop4 = 0;
}
int Hash::ChangeHop(char hop) {
    if (hop == 'a') hop4 = 1;
    else if (hop == 'b') hop3 = 1;
    else if (hop == 'c') hop2 = 1;
    else if (hop == 'd') hop1 = 1;
    else {
        if (hop1 == 1) hop1 = 0;
        else {
            if (hop2 == 1) hop2 = 0;
            else {
                if (hop3 ==1) hop3 = 0;
                else {
                    if (hop4 == 1) hop4 = 0;
                    else return 0;
                }
            }
        }
    }
    return 1;
}
int Hash::InsertVal(int tempVal){
    if (item == -1) {
        item = tempVal;
        return 1;
    }
    else return 0;
}
int Hash::DeleteVal(int tempVal){
    item = -1;
    return 1;
}
int Hash::CheckVal(int tempVal){
    if (tempVal == item) return 1;
    else return 0;
}
int Hash::PrintVal(int tempVal){
    if (item == -1){
        cout << " " << tempVal << " " << "|" << "      " << "|" << " " << hop4 << hop3 << hop2 << hop1 << " " << "|" << endl;
    }
    else {
        cout << " " << tempVal << " " << "|" << "  " << item << "  " << "|" << " " << hop4 << hop3 << hop2 << hop1 << " " << "|" << endl;
    }
    
    return 1;
}