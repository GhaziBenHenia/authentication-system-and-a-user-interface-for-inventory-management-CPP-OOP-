#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include<cstring>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Admin{
protected:
    string user;
    char* password [10];
    public:
    static int num ;
    Admin();
    Admin (string user);
    Admin(string user, char *password[10]);
    Admin(string user, char pass[10]);
    Admin(const Admin &admin);
    ~Admin(){num --;
        delete[] password;}
    string User_name()const;
    char* get_pass()const;
    void Modify_User(string user);
    void Modify_Password(char *password[10]);
    friend ostream& operator<<(ostream& out,const Admin &admin);
    Admin operator=(const Admin &admin);
    friend bool operator==(const Admin &admin,const Admin &admin1);
    friend bool operator!=(const Admin &admin,const Admin &admin1);
    friend ofstream& operator<<(ofstream& f,const Admin &admin);
};

//ostream& operator<<(ostream& out,const Admin &admin);
//bool operator==(const Admin &admin,const Admin &admin1);
bool operator!=(const Admin &admin,const Admin &admin1);
ofstream& operator<<(ofstream& f,const Admin &admin);

#endif // ADMIN_H_INCLUDED
