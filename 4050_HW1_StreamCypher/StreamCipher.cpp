/*
 *Travis Allan
 *2/4/2016
 *CSCE 4050
 *Homework 1
 *Stream Ciphers
 */

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//int PRIME = 23;
//int OFFSET = 5;

char* transform(char thing[10]) {
    return thing;
}

int main() {
    
    //varaible declaration
    int i, temp, PRIME, OFFSET;
    int fd1; //fd1 = input.txt, fd3 = prime.txt
    int intbuffer[2000];
    int primebuffer[129];
    FILE * fd3;
    
    //set the offset
    srand(time(NULL));
    OFFSET = (rand() % 8) + 1;
    
    //set the prime
    fd3 = fopen("prime.txt", "r");
    for (i=0; i<=129; i++) {
        fscanf(fd3, "%d", &primebuffer[i]);
    }
    //for (i=0; i <= 129; i++) {
    //    cout << primebuffer[i] << endl;
    //}
    i = rand() % 129;
    PRIME = primebuffer[i];
    fclose(fd3);
    
    //buffer initialization
    char buffer[2000];
    for (i = 0; i <= 2000; i++) {
        buffer[i] = '\0';
        intbuffer[i] = -25;
    }
    
    //file reading
    fd1 = open("input.txt", O_RDONLY);
    read(fd1, buffer, 2000);
    
    //lowercase conversion
    for (i=0; i<=2000; i++) {
        buffer[i] = tolower(buffer[i]);
        //cout << buffer[i] << endl;
    }
    //method
    for (i=0; i<=2000; i++) {
        switch (buffer[i]) {
            case ' ':
                temp = ((26 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
                
            case 'a' :
                temp = ((25 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'b' :
                temp = ((0 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'c' :
                temp = ((24 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'd' :
                temp = ((1 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'e' :
                temp = ((23 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'f' :
                temp = ((2 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'g' :
                temp = ((22 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'h' :
                temp = ((3 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'i' :
                temp = ((21 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'j' :
                temp = ((4 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'k' :
                temp = ((20 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'l' :
                temp = ((5 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'm' :
                temp = ((19 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'n' :
                temp = ((6 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'o' :
                temp = ((18 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'p' :
                temp = ((7 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'q' :
                temp = ((17 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'r' :
                temp = ((8 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 's' :
                temp = ((16 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 't' :
                temp = ((9 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'u' :
                temp = ((15 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'v' :
                temp = ((10 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'w' :
                temp = ((14 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'x' :
                temp = ((11 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'y' :
                temp = ((13 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case 'z' :
                temp = ((12 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case '.' :
                temp = ((27 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case ',' :
                temp = ((28 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case '?' :
                temp = ((29 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case '!' :
                temp = ((30 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case ';' :
                temp = ((31 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case ':' :
                temp = ((32 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case '"' :
                temp = ((33 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case '(' :
                temp = ((34 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
            case ')' :
                temp = ((35 * PRIME) - OFFSET);
                //buffer[i] = temp;
                //cout << temp << endl;
                intbuffer[i] = temp;
                break;
        }
    }
    
    //file writing
    FILE * fd2;
    fd2 = fopen ("output.txt", "w");
    for (i=0; i<=2000; i++) {
        if (intbuffer[i] != -25) {
            fprintf (fd2, "%d\n", intbuffer[i]);
        }
    }
    
    //returning the prime and offset
    cout << "Prime: " << PRIME << endl;
    cout << "Offset: " << OFFSET << endl;
    
    //cleanup
    close(fd1);
    fclose(fd2);

    return 1;
}

