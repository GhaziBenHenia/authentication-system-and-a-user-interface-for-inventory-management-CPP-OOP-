#ifndef MODERATOR_H_INCLUDED
#define MODERATOR_H_INCLUDED

#include"Admin.h"
#include"Seller.h"
class Moderator:virtual public Admin
{

public:
    secret_code s_c;
    int s_code=s_c.x;
    Moderator(string user, char *password[10]);
    //void clear_stock();
    //void clear_stock(const Seller& seller);
    //void clear_stock(const Seller& seller,string prod);
    //void delete_all();
    //void delete_seller(const Seller& seller);
    //int count_products();
    //int count_products(const Admin& admin);
    virtual bool check_account();//
    void save();//
    virtual ~Moderator(){num--;}
};

#endif // MODERATOR_H_INCLUDED
