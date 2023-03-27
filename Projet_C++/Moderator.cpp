#include "Moderator.h"
bool Moderator::check_account(){
    bool b;
    ifstream fr{"MODS.txt"};
    string users{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,users);
            string user = users.substr(0,users.find("%"));
            string pass = users.substr(users.find("%")+1,10);
            char password [10] ;
            strcpy(password,pass.c_str());
            Admin xyq(user,password);
            b = *this == xyq;
            if (b){return true;}
        }
        }
                          return false;}

void Moderator::save(){
    if(!(*this).check_account()){
     ofstream fw{"MODS.txt",ios::app};
     if (fw.is_open()){
     fw<<*this;}}
}

Moderator::Moderator(string user, char *password[10]){
        this->user = user;
        *this->password = *password;
        num ++;
        }
