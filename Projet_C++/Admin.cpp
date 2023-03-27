#include "Admin.h"

using namespace std;

char* put_password(){
        char c;
        char * s = new char[10];
        for(int i= 0;i<10 ;i++){
            c=_getch();
            if ( c != '\r' )
                {*(s+i) = c;
            _putch('*');}
            else {
            for(int j= i;j<10;j++){*(s+j)='\0';}
            break;
            }
            }
            return s;}

bool check_password(char pass1[10],char pass2[10]){
    bool b=true;
    string str1(pass1);
    string str2(pass2);
    //for(int i=0;i<6;i++){
        b =( str1==str2);//b&&(pass1[i]==pass2[i]);
    //}
            return b;}


Admin::Admin(){num++;
}


Admin::Admin(string user){
        this->user = user;
        *password ="";
        num ++;
        }
Admin::Admin(string user, char *password[10]){
        this->user = user;
        *this->password = *password;
        num ++;
        }

Admin::Admin(string user, char pass[10]){
        this->user = user;
        *password = pass;
        num ++;
        }

Admin::Admin(const Admin &admin){ user = admin.user;
                               *password = *admin.password;
                               num++;
                               }

string Admin::User_name() const{
        return user;}

void Admin::Modify_User(string user){
        this->user=user;}

void Admin::Modify_Password(char *password[10]){
                    *this->password=*password;}

ostream& operator<<(ostream& out,const Admin &admin){
                                                  out<<"\n\n**** Account Info *****\n";
                                                  out<<"\nUser Name: "<<admin.user;
                                                  out<<"\nPassword: "<<*admin.password;
                                                  out<<"\n"<<admin.num<<"\n";
                                                  out<<"\n**************************\n";
                                                  return out;}

Admin Admin::operator=(const Admin &admin){  if (this != &admin)
                                            {user = admin.user;
                                            *password = *admin.password;}
                                            return *this; }


bool operator==(const Admin &admin,const Admin &admin1){
        return (admin.user == admin1.user && check_password(*admin.password,*admin1.password )); }

bool operator!=(const Admin &admin,const Admin &admin1){
        return (admin.user != admin1.user || !check_password(*admin.password,*admin1.password )); }

ofstream& operator<<(ofstream& f,const Admin &admin)
{       f<<admin.user;
        f<<"%"<<*admin.password<<"\n";
        return f;}
char* Admin::get_pass()const{return (*password);}
