#include"Seller.h"

bool check_pass(char pass1[10],char pass2[10]){
    bool b=true;
    string str1(pass1);
    string str2(pass2);
    //for(int i=0;i<6;i++){
        b =(str1==str2);//b&&(pass1[i]==pass2[i]);
    //}
            return b;}
bool Seller::check_prod(const Products& prod){
 bool b;
    ifstream fr{user+".txt"};
    string prods{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,prods);
            string name = prods.substr(0,prods.find("%"));
            string brand = prods.substr(prods.find("%")+1,prods.find("@")-prods.find("%")-1);
            Products xyq(name,brand);
            b = prod == xyq;
            if (b){return true;}
        }
        fr.close();}
        return false;
}
void Seller::save_prod(const Products& prod){
     if(!(this)->check_prod(prod)){
     ofstream fw{user+".txt",ios::app};
     if (fw.is_open()){
     fw<<prod;}
     fw.close();}
}
void Seller::clear_stock(){
     ofstream fw{user+".txt", ios::out | ios::trunc};
     }

bool Seller::check_account(int &a){
    bool b;
    a=1;
    ifstream fr{"SELLER.txt"};
    string users{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,users);
            string user = users.substr(0,users.find("%"));
            string pass = users.substr(users.find("%")+1,10);
            char password [10] ;
            strcpy(password,pass.c_str());
            Seller xyq(user,password);
            if (this->User_name() == xyq.User_name()){a=0;}
            b = *this == xyq;
            if(b){ return b;}
        }
    fr.close();}
            return b;}

void Seller::save(){
    int a;
    if(!(*this).check_account(a)){
     ofstream fw{"SELLER.txt",ios::app};
     if (fw.is_open()){
     fw<<*this;
     fw.close();}}
}


bool operator==(const Seller &admin,const Seller &admin1){
        return (admin.user == admin1.user && check_pass(*admin.password,*admin1.password )); }
Seller::Seller(string user){
        this->user = user;
        *password = " ";
        num ++;
        }
ofstream& operator<<(ofstream& f,const Seller &admin)
{       f<<admin.user;
        f<<"%"<<*admin.password<<"\n";
        return f;}
