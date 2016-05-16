#ifndef HUGEINT_H_
#define HUGEINT_H_

#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>

using namespace std;

class HugeInt{
    private:
        int big[200];
    public:
        HugeInt();
        HugeInt(int a);
        HugeInt(const char* a);
       /* string& gets(){return s;}*/
        HugeInt& operator=(const HugeInt& a);
        HugeInt operator+(const HugeInt& a);
        HugeInt operator-(const HugeInt& a);
        friend istream& operator>>(istream& in, HugeInt& a);
        friend ostream& operator<<(ostream& out, const HugeInt& a);
};
#endif


