/*
 *Name: Travis Allan
 *Date: 6/9/2014
 *Course: CSCE 2110
 *Title: Program 1
 *Description: This program uses classes and methods to impplement an  example of comparing ssets..
 */

//headers
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


//classes
class Set
{
private:
public:
    int content[13]; //= "2 3 4 5 6 7 8 9 10 J Q K A";
    //= '2','3','4','5','6','7','8','9','10','J','Q','K','A';
    
    int assignset(int tempset[13])
    {
        int i;
        for (i=0; i < 13; i++) {
            content[i] = tempset[i];
        }
        //test
        //cout << endl << "assign: ";
        //for (i=0; i < 13; i++) {
        //    cout << content[i];
        //}

        return content[12];
    }
    int clearset() {
        int i;
        for (i=0; i < 13; i++){
            content[i] = 0;
        }
        //test
        return content[12];
    }
    void printset() {
        //cout << "Print: ";
        int i;
        for (i=0; i < 13; i++) {
            cout << content[i] << " ";
        }
        cout << endl;
    }
};



//main
int main()
{
    //value declarations
    char action[30];
    char quit[5] = "quit";
    char assign[7] = "assign";
    char unio[6] = "union";
    char clear[6] = "clear";
    char print[7] = "print";
    char inter[13] = "intersection";
    char diff[11] = "difference";
    int tempset[13];
    int i, ect1, ect2;
    char key1, key2, next;
    
    //instances of Set
    Set S;
    Set R;
    Set T;
    Set U;
    Set I;
    Set D;
    
    do {
        cout << "Program1> ";
        cin >> action;
        
        //quit
        if (strcmp(action, quit) == 0) {
            return 0;
        }
        
        //assign
        else if(strcmp(action, assign) == 0) {
            cin >> key1;
            ect1 = 0; //error counter for negetive
            ect2 = 0; //error counter for non boolean positive

            for(i=0;i != 13;i++) {
                cin >> tempset[i];
                
                if (tempset[i] < 0) {
                    ect1++;
                }
                else if (tempset[i] > 1) {
                    ect2++;
                }
            }
            //cin >> over;
            
            if(ect1 > 0) cout << "Error: " << ect1 << " of the values are negetive." << endl;
            if(ect2 > 0) cout << "Error: " << ect2 << " of the values are non-boolean positive integers" << endl;
                //if(over != 1000) cout << "Error: Value recieved from user exceeds required length";

            //class call
            if (key1 == 'S') {
                S.assignset(tempset);
            }
            if (key1 == 'R') {
                R.assignset(tempset);
            }
            if (key1 == 'T') {
                T.assignset(tempset);
            }
            if (key1 == 'U') {
                U.assignset(tempset);
            }
            if (key1 == 'I') {
                I.assignset(tempset);
            }
            if (key1 == 'D') {
                D.assignset(tempset);
            }//end of assign
        }
        
        //union
        else if(strcmp(action, unio) == 0) {
            cin >> key1 >> key2;
            //cout << endl;
            if ((key1 == 'S' && key2 == 'R') || (key1 == 'R' && key2 == 'S')) {
                for (i=0; i < 13; i++) {
                    if ((S.content[i] || R.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            
            else if ((key1 == 'S' && key2 == 'T') || (key1 == 'T' && key2 == 'S')) {
                for (i=0; i < 13; i++) {
                    if ((S.content[i] || T.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if ((key1 == 'R' && key2 == 'T') || (key1 == 'T' && key2 == 'R')) {
                for (i=0; i < 13; i++) {
                    if ((R.content[i] || T.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
        }
        
        //clear
        else if(strcmp(action, clear) == 0) {
            cin >> key1;
            //cout << endl;
            //function call
            if (key1 == 'S') {
                S.clearset();
            }
            else if (key1 == 'R') {
                R.clearset();
            }
            else if (key1 == 'T') {
                T.clearset();
            }
            else if (key1 == 'U') {
                U.clearset();
            }
            else if (key1 == 'I') {
                I.clearset();
            }
            else if (key1 == 'D') {
                D.assignset(tempset);
            }
            else cout << "Error input not supported.";
        }
        
        //print
        else if(strcmp(action, print) == 0) {
            cin >> key1;
            //cout << endl;
            //function call
            if (key1 == 'S') {
                S.printset();
            }
            else if (key1 == 'R') {
                R.printset();
            }
            else if (key1 == 'T') {
                T.printset();
            }
            else cout << "Error input not supported.";
        }
        
        //intersection
        else if(strcmp(action, inter) == 0) {
            cin >> key1 >> key2;
            //cout << endl;
            if ((key1 == 'S' && key2 == 'R') || (key1 == 'R' && key2 == 'S')) {
                for (i=0; i < 13; i++) {
                    if ((S.content[i] && R.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if ((key1 == 'S' && key2 == 'T') || (key1 == 'T' && key2 == 'S')) {
                for (i=0; i < 13; i++) {
                    if ((S.content[i] && T.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if ((key1 == 'R' && key2 == 'T') || (key1 == 'T' && key2 == 'R')) {
                for (i=0; i < 13; i++) {
                    if ((R.content[i] && T.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else cout << "Error input not supported.";
        }
        
        //difference
        else if(strcmp(action, diff) == 0) {
            cin >> key1 >> key2;
            //cout << endl;
            //function call
            if (key1 == 'S' && key2 == 'R') {
                for (i=0; i < 13; i++) {
                    if ((S.content[i] && R.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if (key1 == 'S' && key2 == 'T') {
                for (i=0; i < 13; i++) {
                    if (T.content[i] == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if (key1 == 'R' && key2 == 'T') {
                for (i=0; i < 13; i++) {
                    if ((T.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if (key1 == 'R' && key2 == 'S') {
                for (i=0; i < 13; i++) {
                    if ((S.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if (key1 == 'T' && key2 == 'S') {
                for (i=0; i < 13; i++) {
                    if ((S.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else if (key1 == 'T' && key2 == 'R') {
                for (i=0; i < 13; i++) {
                    if ((R.content[i]) == 1) {
                        U.content[i] = 1;
                    }
                    else U.content[i] = 0;
                    
                }
                for (i=0; i < 13; i++) {
                    cout << U.content[i] << ",";
                }
                cout << key1 << "," << key2 << endl;
            }
            else cout << "Error input not supported.";
        }//end of diffeence
        
        //catches overflow from assign
        else if ((action[1] == 1) || (action[1] == 0)) {
            cout << "Error: Most likely, you have recieved this error because your array of ints was too long" << endl;
        }
        else cout << "Error: The action you requested isn't supported." << endl;
        
        
        
        //for testing purposes only
        //cout <<"input> " << action << " "  << key1;
        //for(i=0; i != 13; i++) {
       //     cout << " " << tempset[i];
        //}
        
        //cout << endl;
        
    } while(strcmp(action,quit) != 0);
    
    //end of main
    return 0;
}

