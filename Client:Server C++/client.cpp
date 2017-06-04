/*
 *Travis Allan
 *3/31/2016
 *CSCE 4050
 *Project 1
 *Client
 */

#include <iostream>
#include <sys/socket.h>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctime>
using namespace std;



int macFunction(char input[1024], int key) {
    int mac = key;
    char adder;
    for(int i=0; i<1024; i++) {
        adder = input[i];
        mac += mac + adder;
    }
    return mac;
}

int main() {
    int socket1, eh, mac;
    int key1 = 123456;
    int key2 = 654321;
    char buffer[1024] = "test";
    char buffer2[1024] = "test2";
    char choiceE, choiceM;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    
    socket1 = socket(AF_INET, SOCK_STREAM, 0);
    if (socket1 < 0) cout << "error1" << endl;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    addr_size = sizeof serverAddr;

    
    if ((connect(socket1, (struct sockaddr *) &serverAddr, addr_size)) < 0) {
        printf("error2\n");
        return 0;
    }
    
    eh = write(socket1, buffer, 1024);
    if (eh < 0) cout << "error3" << endl;
    
    bzero(buffer, 1024);
    bzero(buffer2, 1024);
    eh = read(socket1, buffer, 1024);   //encryption cipher options
    if (eh < 0) cout << "error4" << endl;
    cout << "choose an encryption cipher" << endl;
    cout << buffer << endl;
    cin >> choiceE;
    eh = read(socket1, buffer2, 1024);   //MAC cipher options
    if (eh < 0) cout << "error5" << endl;
    cout << "choose an MAC cipher" << endl;
    cout << buffer << endl;
    cin >> choiceM;
    
    //insert MAC for plaintext call here
    bzero(buffer, 1024);
    bzero(buffer2, 1024);
    
    eh = write(socket1, &choiceE, 1);      //encryption
    if (eh < 0) cout << "error6" << endl;
    eh = write(socket1, &choiceM, 1);      //MAC
    if (eh < 0) cout << "error7" << endl;
    cout << "Please enter the text to be encrypted without any spaces" << endl;
    cin >> buffer;
    eh = write(socket1, buffer, 1024);      //Plaintext
    if (eh < 0) cout << "error8" << endl;
    mac = macFunction(buffer, key1);
    eh = write(socket1, &mac, 1024);      //MAC of plaintext
    if (eh < 0) cout << "error9" << endl;
    cout << "MAC of plaintext: " << mac << endl;
    
    bzero(buffer, 1024);
    bzero(buffer2, 1024);
    eh = read(socket1, buffer, 1024);   //encrypted text
    if (eh < 0) cout << "error10" << endl;
    eh = read(socket1, &mac, 1024);   //MAC of encrypted text
    mac = macFunction(buffer, key1);
    if (eh < 0) cout << "error11" << endl;
    cout << "MAC of encrypted text: " << mac << endl;
    
    cout << "encrypted plaintext: " << buffer << endl;
    //cout << "MAC of plaintext: " << buffer2 << endl;
    close(socket1);
	return 0;
}
