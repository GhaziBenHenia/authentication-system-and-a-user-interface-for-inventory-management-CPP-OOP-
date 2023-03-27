#ifndef SELLER_H_INCLUDED
#define SELLER_H_INCLUDED
#include "secret_code.h"
#include"Admin.h"
#include"Products.h"
class Seller:virtual public Admin{
public:
    secret_code s_c;
    int s_code=s_c.x;
    friend class Products;
    Seller(string user);
    Seller(string user, char *password[10]):Admin(user,password){};
    using Admin::Admin;
    bool check_prod(const Products& prod);
    void save_prod(const Products& prod);
    void remove_product(const Products& prod);
    void clear_stock();
    bool check_account(int &a);
    void save();
    friend bool operator==(const Seller &admin,const Seller &admin1);
    friend ofstream& operator<<(ofstream& f,const Seller &admin);
    virtual ~Seller(){num--;delete[] password;}

};
//bool operator==(const Seller &admin,const Seller &admin1);
#endif // SELLER_H_INCLUDED
