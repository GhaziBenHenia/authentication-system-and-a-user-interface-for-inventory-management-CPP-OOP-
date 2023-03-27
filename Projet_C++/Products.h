#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
class Products{

string name,brand;
double price;
int qtt;
public:
    friend class Sellers;
    Products();
    Products(string name,string brand,double price);
    Products(string name,string brand);
    friend ofstream& operator<<(ofstream& f,const Products &prod);
    friend bool operator==(const Products& prod1,const Products& prod2);
    ~Products(){};
    };

#endif // PRODUCTS_H_INCLUDED
