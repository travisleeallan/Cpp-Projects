/*
 *Travis Allan
 *3/31/2016
 *CSCE 4050
 *Project 1
 *Server
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
#include <string>
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


//source: rosettacode.org
class Vigenere
{
public:
    string key;
    
    Vigenere(string key)
    {
        for(int i = 0; i < key.size(); ++i)
        {
            if(key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if(key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }
    
    string encrypt(string text)
    {
        string out;
        
        for(int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];
            
            if(c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if(c < 'A' || c > 'Z')
                continue;
            
            out += (c + key[j] - 2*'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }
        
        return out;
    }
    
    string decrypt(string text)
    {
        string out;
        
        for(int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];
            
            if(c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if(c < 'A' || c > 'Z')
                continue;
            
            out += (c - key[j] + 26) % 26 + 'A'; 
            j = (j + 1) % key.length();
        }
        
        return out;
    }
};



int main() {
    int socket1, socket2, eh, mac;
    int key1 = 123456;
    int key2 = 654321;
    char buffer[1024];
    char buffer2[1024];
    char buffer3[1024];
    char choiceE, choiceM;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size, client_size;
    Vigenere cipher("VIGENERECIPHER"); //source: rosettacode.org
    string encrypted, input;
    
    socket1 = socket(AF_INET, SOCK_STREAM, 0);
    if (socket1 < 0) cout << "error1" << endl;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    addr_size = sizeof serverAddr;

    if (bind(socket1, (struct sockaddr *) &serverAddr, addr_size) < 0) {
        cout << "error2" << endl;
        return 0;
    }
    
    listen(socket1, 3);
    client_size = sizeof clientAddr;
    
    socket2 = accept(socket1, (struct sockaddr *) &clientAddr, &client_size);
    if (socket2 < 0) cout << "error3" << endl;
    
    eh = read(socket2, buffer3, 1024);   //establishing
    if (socket2 < 0) cout << "error4" << endl;
    cout << buffer << endl;
    
    eh = write(socket2, "A. Vigenere Cypher", 1024);  //encryption cipher options
    if (socket2 < 0) cout << "error5" << endl;
    eh = write(socket2, "A. HMAC", 1024);  //MAC cipher options
    if (socket2 < 0) cout << "error6" << endl;
    
    bzero(buffer, 1024);
    bzero(buffer2, 1024);
    eh = read(socket2, &choiceE, 1);   //encryption
    if (socket2 < 0) cout << "error7" << endl;
    eh = read(socket2, &choiceM, 1);   //MAC
    if (socket2 < 0) cout << "error8" << endl;
    eh = read(socket2, buffer, 1024);   //Plaintext
    if (socket2 < 0) cout << "error9" << endl;
    eh = read(socket2, &mac, 1024);   //MAC of plaintext
    if (socket2 < 0) cout << "error10" << endl;
    cout << "MAC of plaintext: " << mac << endl;
    //computation
    if (choiceE == 'A' && choiceM == 'A') {
        string input(buffer);
        encrypted = cipher.encrypt(input);
        strcpy(buffer2, encrypted.data());
        mac = macFunction(buffer2, key1);
        cout << "MAC of encrypted text: " << mac << endl;
        //char temp[1024] = encrypted.data();
        //strcpy(temp, buffer);
    }
    //be sure to include false mac end state
    
    bzero(buffer, 1024);
    bzero(buffer2, 1024);
    eh = write(socket2, encrypted.data(), 1024);  //encrypted text
    if (socket2 < 0) cout << "error11" << endl;
    eh = write(socket2, &mac, 1024);  //MAC of encrypted text
    if (socket2 < 0) cout << "error12" << endl;
    
    close(socket2);
    close(socket1);
    return 0;
}

