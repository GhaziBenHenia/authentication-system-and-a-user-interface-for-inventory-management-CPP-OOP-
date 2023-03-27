#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <stdio.h>
#include<string>
#include"Admin.h"
#include"Moderator.h"
#include"Products.h"
#include"Seller.h"
char* put_password();
void home();
void clear_stock(Seller &xyz);
void logged_sel(Seller &xyz);
void save_prod(const Products& prod);
void logged_mod(Moderator &xyz);
void transp_prods(string n_file, string o_file){
    string p="";
    ifstream fn{o_file+".txt"};
    string prods{""};
    if (fn.is_open()){
    while(!fn.eof()){
            getline(fn,prods);
            p = p+"\n"+prods;}}
    ofstream c{o_file+".txt",ios::out|ios::trunc};
    c.close();
    ofstream f{n_file+".txt", ios::app};
    if(f.is_open()){
                f<<p;
    f.close();}
}


void mod_settings(Moderator &xyz){
int x;
char c;
cout<<"USER NAME: "<<xyz.User_name()<<"                 { Secret code:"<<xyz.s_code<<" }"<<endl;
cout<<"1.Show password\n";
cout<<"2.Modify User name\n";
cout<<"3.Modify Password\n";
cout<<"0.Back\n";

x=(c=_getch())-'0';
switch(x) {
  case 0:
    system("cls");
    logged_mod(xyz);
    break;
  case 1:
    {int s_c;
    cout<<"Secret code: ";
    cin>>s_c;
    if (s_c == xyz.s_code){
    cout<<"Password: ";cout<<xyz.get_pass();}
    else{cout<<"wrong code!";}
    x=(c=_getch())-'0';
    switch(x){default:system("cls");mod_settings(xyz);}
    break;}
  case 2:
      {int s_c ;
      string n_name;
      cout<<"Secret code: ";
      cin>>s_c;
      if (s_c == xyz.s_code){
      cout<<"New User Name: ";cin>>n_name;
    string o_name = xyz.User_name();
    string s="";
    ifstream fr{"MODS.txt"};
    string users{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,users);
            string user = users.substr(0,users.find("%"));
            string pass = users.substr(users.find("%")+1,10);
            char password [10] ;
            strcpy(password,pass.c_str());
            Seller xyq(user,password);
            bool b = xyz == xyq;
            if (!b){
            if(s=="\n"){s="";}
            s = s+"\n"+users;}}}
           {ofstream fw{"MODS.txt", ios::out | ios::trunc};
           if (fw.is_open()){
           fw<<s;
           fw.close();}}
           xyz.Modify_User(n_name);
           xyz.save();
}
      else{cout<<"wrong code!";}
      x=(c=_getch())-'0';
      switch(x){default:system("cls");mod_settings(xyz);}
      break;}
case 3:
      {
      int s_c;
      char* n_pass;
      cout<<"Secret code: ";
      cin>>s_c;
      if (s_c == xyz.s_code){
      cout<<"New password: ";n_pass=put_password();

    Seller del_sel(xyz.User_name(),xyz.get_pass());
    string s="";
    ifstream fr{"MODS.txt"};
    string users{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,users);
            string user = users.substr(0,users.find("%"));
            string pass = users.substr(users.find("%")+1,10);
            char password [10] ;
            strcpy(password,pass.c_str());
            Seller xyq(user,password);
            bool b = del_sel == xyq;
            if (!b){
            if(s=="\n"){s="";}
            s = s+"\n"+users;}}}
           {ofstream fw{"MODS.txt", ios::out | ios::trunc};
           if (fw.is_open()){
           fw<<s;
           fw.close();}
           }
           {xyz.Modify_Password(&n_pass);
            xyz.save();}
      }
      else{cout<<"wrong code!";}
      x=(c=_getch())-'0';
      switch(x){default:system("cls");mod_settings(xyz);}
    break;}
   default:
    system("cls");
    mod_settings(xyz);
}}

void settings(Seller &xyz){
int x;
char c;
cout<<"USER NAME: "<<xyz.User_name()<<"                 { Secret code:"<<xyz.s_code<<" }"<<endl;
cout<<"1.Show password\n";
cout<<"2.Modify User name\n";
cout<<"3.Modify Password\n";
cout<<"0.Back\n";

x=(c=_getch())-'0';
switch(x) {
  case 0:
    system("cls");
    logged_sel(xyz);
    break;
  case 1:
    {int s_c;
    cout<<"Secret code: ";
    cin>>s_c;
    if (s_c == xyz.s_code){
    cout<<"Password: ";cout<<xyz.get_pass();}
    else{cout<<"wrong code!";}
    x=(c=_getch())-'0';
    switch(x){default:system("cls");settings(xyz);}
    break;}
  case 2:
      {int s_c ;
      string n_name;
      cout<<"Secret code: ";
      cin>>s_c;
      if (s_c == xyz.s_code){
    cout<<"New User Name: ";cin>>n_name;
    string o_name = xyz.User_name();
    string s="";
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
            bool b = xyz == xyq;
            if (!b){
            if(s=="\n"){s="";}
            s = s+"\n"+users;}}}
           {ofstream fw{"SELLER.txt", ios::out | ios::trunc};
           if (fw.is_open()){
           fw<<s;
           fw.close();}}
           xyz.Modify_User(n_name);
           xyz.save();
           transp_prods(xyz.User_name(),o_name);
}
      else{cout<<"wrong code!";}
      x=(c=_getch())-'0';
      switch(x){default:system("cls");settings(xyz);}
      break;}
case 3:
      {
      int s_c;
      char* n_pass;
      cout<<"Secret code: ";
      cin>>s_c;
      if (s_c == xyz.s_code){
      cout<<"New password: ";n_pass=put_password();
    Seller del_sel(xyz.User_name(),xyz.get_pass());
    string s="";
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
            bool b = del_sel == xyq;
            if (!b){
            if(s=="\n"){s="";}
            s = s+"\n"+users;}}}
           {ofstream fw{"SELLER.txt", ios::out | ios::trunc};
           if (fw.is_open()){
           fw<<s;
           fw.close();}
           }
           {xyz.Modify_Password(&n_pass);
            xyz.save();}
      }
      else{cout<<"wrong code!";}
      x=(c=_getch())-'0';
      switch(x){default:system("cls");settings(xyz);}
    break;}
   default:
    system("cls");
    settings(xyz);
}}

void list_all(Seller &xyz){
    string s;
    string f_name = xyz.User_name();//+static_cast<string>(xyz.s_code);
    ifstream fr{f_name+".txt"};
    string prods{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,prods);
            string name = prods.substr(0,prods.find("%"));
            string brand = prods.substr(prods.find("%")+1,prods.find("@")-prods.find("%")-1);
            s = s+"\n"+"name:"+name+" | "+"brand:"+brand;}
            fr.close();}
    cout<<"0.Back"<<endl;
    cout<<"YOUR PORODUCTS:"<<endl;
    cout<<s;
    char c;
    int x=( c=_getch())-'0';
    switch(x) {
        case 0:
            system("cls");
            logged_sel(xyz);
            break;
        default:
        system("cls");
        list_all(xyz);
        }
    }

void del_prod(Seller &xyz){
    string name1,brand1 ;
    cout<<"Name of the product: ";
    cin>>name1;
    cout<<"Brand: ";
    cin>>brand1;
    string s="";
    ifstream fr{(xyz.User_name())+".txt"};
    string prods{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,prods);
            string name = prods.substr(0,prods.find("%"));
            string brand = prods.substr(prods.find("%")+1,prods.find("@")-prods.find("%")-1);
            Products xyq(name,brand);
            Products prod(name1,brand1);
            bool b = (prod == xyq);
            if (!b){
            if(s=="\n"){s="";};
            s = s+"\n"+prods;}}
           {ofstream f{(xyz.User_name())+".txt", ios::out|ios::trunc};
           if(f.is_open()){
                f<<s;
           f.close();}
}
           logged_sel(xyz);
}}
void del_prod(Moderator &xyz,string s_name){
    string name1,brand1 ;
    cout<<"Name of the product: ";
    cin>>name1;
    cout<<"Brand: ";
    cin>>brand1;
    string s="";
    ifstream fr{s_name+".txt"};
    string prods{""};
    if (fr.is_open()){
    while(!fr.eof()){
            getline(fr,prods);
            string name = prods.substr(0,prods.find("%"));
            string brand = prods.substr(prods.find("%")+1,prods.find("@")-prods.find("%")-1);
            Products xyq(name,brand);
            Products prod(name1,brand1);
            bool b = (prod == xyq);
            if (!b){
            if(s=="\n"){s="";};
            s = s+"\n"+prods;}}
           {ofstream f{s_name+".txt", ios::out|ios::trunc};
           if(f.is_open()){
                f<<s;
           f.close();}
}
           logged_mod(xyz);
}}

void add_prod(Seller &xyz){
string name,brand ;
cout<<"Name of the product: ";
cin>>name;
cout<<"Brand: ";
cin>>brand;
Products xyq(name,brand);
xyz.save_prod(xyq);
system("cls");
logged_sel(xyz);
}

void logged_mod(Moderator &xyz){system("cls");cout<<"*****WELCOME*****";
int x;
char c;
cout<<"\n1.Add a new Moderator\n";
cout<<"2.Delete a Seller\n";
cout<<"3.Delete a product\n";
cout<<"4.Clear a stock\n";
cout<<"5.Settings\n";
cout<<"0.LOG OUT\n";

x=(c=_getch())-'0';
switch(x) {
  case 1:
    {system("cls");
    string user_name ;
    char* s = new char[10];
    cout<<"User Name: ";
    cin>>user_name;
    cout<<"password: ";
    s = put_password();
    Moderator xyq(user_name,&s);
    bool b = xyq.check_account();
    if (b){
    system("cls");
    cout<<"\nCHANGE USERNAME OR PASSWORD!"<<endl;
    logged_mod(xyz);
    }
else {xyq.save();logged_mod(xyz);}
    break;}
  case 2:
    {system("cls");
    string n_name;
    cout<<"Name of the Seller: ";cin>>n_name;
    string s="";
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
            bool b = n_name == xyq.User_name();
            if (!b){
            if(s=="\n"){s="";}
            s = s+"\n"+users;}}
            fr.close();}
           {ofstream fw{"SELLER.txt", ios::out | ios::trunc};
           if (fw.is_open()){
           fw<<s;
           fw.close();}}
           logged_mod(xyz);
    break;}
  case 3:
    {system("cls");
    string s_name;
    cout<<"Name of the Seller: ";
    cin>>s_name;
    del_prod(xyz,s_name);
    logged_mod(xyz);
    break;}
  case 4:
    {system("cls");
    string s_name;
    cout<<"Name of the Seller: ";
    cin>>s_name;
    Seller xyq(s_name);
    xyq.clear_stock();
    logged_mod(xyz);
    break;}
  case 5:
    system("cls");
    mod_settings(xyz);
    break;
  case 0:
      system("cls");
      int fcloseall();
      home();
    break;
  default:
    system("cls");
    logged_mod(xyz);
}
}

void logged_sel(Seller &xyz){system("cls");cout<<"***** WELCOME *****";
int x;
char c;
cout<<"\n1.Add a product\n";
cout<<"2.Delete a product\n";
cout<<"3.List all the products\n";
cout<<"4.Clear the stock\n";
cout<<"5.Settings\n";
cout<<"6.LOG OUT\n";

x=(c=_getch())-'0';
switch(x) {
  case 1:
    system("cls");
    add_prod(xyz);
    break;
  case 2:
    system("cls");
    del_prod(xyz);
    break;
  case 3:
    system("cls");
    list_all(xyz);
    break;
  case 4:
    system("cls");
    xyz.clear_stock();
    cout<<"done";
    logged_sel(xyz);
    break;
  case 5:
    system("cls");
    settings(xyz);
    break;
  case 6:
      system("cls");
      int fcloseall();
      home();
    break;
  default:
    system("cls");
    logged_sel(xyz);
}
}

char* put_password();
void log_mod(){
cout<<"****LOG IN AS A MODERATOR****"<<endl;
string user_name ;
char* s = new char[10];
cout<<"User Name: ";
cin>>user_name;
cout<<"password: ";
s = put_password();
Moderator xyz(user_name,&s);
if (!(xyz.check_account())){
    system("cls");
    cout<<"\nTHERE IS NO ACCOUNT WITH THESE INFORMATIONS!"<<endl;
    log_mod();
}
else {logged_mod(xyz);}
}

void home();

void reg_sel(){cout<<"****REGISTER AS A SELLER****"<<endl;
string user_name ;
char* s = new char[10];
cout<<"User Name: ";
cin>>user_name;
cout<<"password: ";
s = put_password();
Seller xyz(user_name,&s);
int a=1;
bool b = xyz.check_account(a);
if (b || a==0){
    system("cls");
    cout<<"\nCHANGE USERNAME OR PASSWORD!"<<endl;
    reg_sel();
}
else {xyz.save();logged_sel(xyz);}
}

void log_sel(){
cout<<"****LOG IN AS A SELLER****"<<endl;
string user_name ;
char* s = new char[10];
cout<<"User Name: ";
cin>>user_name;
cout<<"password: ";
s = put_password();
Seller xyz(user_name,&s);
int a;
if (!(xyz.check_account(a))){
    system("cls");
    cout<<"\nTHERE IS NO ACCOUNT WITH THESE INFORMATIONS!"<<endl;
    log_sel();
}
else {logged_sel(xyz);}
}

void log0(){
    int x;
    char c;
cout<<"Are you..."<<endl;
cout<<"1.A Seller\n";
cout<<"2.A Moderator\n";
cout<<"3.Back\n";
x=(c=_getch())-'0';
switch(x) {
  case 1:
    system("cls");
    log_sel();
    break;
  case 2:
    system("cls");
    log_mod();
    break;
  case 3:
    system("cls");
    home();
  default:
    system("cls");
    log0();

}}
void home(){
int x;
    char c;

cout<<"*********HELLO*******"<<endl;
cout<<"1.LOG IN\n";
cout<<"2.REGISTER\n";
cout<<"3.QUIT";
x=(c=_getch())-'0';
switch(x) {
  case 1:
    system("cls");
    log0();
    break;
  case 2:
    system("cls");
    reg_sel();
    break;
  case 3:
    system("cls");
    cout<<"GOODBYE";
    break;
  default:
    system("cls");
    home();
}
}
#endif // INTERFACE_H_INCLUDED
