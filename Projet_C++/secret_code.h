#ifndef SECRET_CODE_H_INCLUDED
#define SECRET_CODE_H_INCLUDED
#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;
class secret_code{
public:
    int x;
    secret_code(){srand((unsigned) time(NULL));
                  x = 1000 + (rand() % 1001);}


};


#endif // SECRET_CODE_H_INCLUDED
