#include"Products.h"

ofstream& operator<<(ofstream& f,const Products& prod)
{       f<<prod.name<<"%";
        f<<prod.brand<<"@";
        f<<prod.price<<"&";
        f<<prod.qtt<<endl;
        return f;}
bool operator==(const Products& prod1,const Products& prod2){
        return (prod1.name==prod2.name && prod1.brand==prod2.brand ); }


Products::Products(string name,string brand,double price){
        this->name = name;
        this->brand = brand;
        this->price = price;
        qtt = 0;
        }
Products::Products(string name,string brand){
        this->name = name;
        this->brand = brand;
        this->price = 0.0;
        qtt = 0;
        }
