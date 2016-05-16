#include"HugeInt.h"

HugeInt::HugeInt(){
    for(int i = 0; i < 200; i++)
        big[i] = 0;
}

HugeInt::HugeInt(int a){
    for(int i = 0; i < 200; i++)
        big[i] = 0;
    int j =0;
    while(a != 0){
        big[j] = a % 10;
        a /= 10;
        j++;
    }
}

HugeInt::HugeInt(const char* a){
    for(int i = 0; i < 200; i++)
        big[i] = 0;
    int len = strlen(a);
    for(int i = len - 1; i >= 0; --i)
        big[len - i - 1] = a[i] - '0';
}

HugeInt& HugeInt::operator=(const HugeInt& a){
    for(int i = 0; i < 200; i++)
        big[i] = a.big[i];
    return *this;
}

HugeInt HugeInt::operator+(const HugeInt& a){
    int i = 0;
    int carry = 0;
    HugeInt result;
    while(i < 200){
        result.big[i] = big[i] + a.big[i] + carry;
        carry = result.big[i] / 10;
        result.big[i]%=10;
        i++;
    }
    return result;
}

HugeInt HugeInt::operator-(const HugeInt& a){
    int i = 0;
    int borrow = 0;
    HugeInt result;
    while(i < 200){
        result.big[i] = big[i] - a.big[i] - borrow;
        if(result.big[i] < 0){
            borrow = 1;
            result.big[i] += 10; 
        }
        else
            borrow = 0;

        i++;
    }
    return result;
}

istream& operator>>(istream& in, HugeInt& a){
    int temp[200] = {0};
    /*in.get(temp,200);*/
    int k = 0;
    char pp;
    in.get(pp);
    while(pp != '\n'){
        temp[k] = pp - '0';
        k++;  
        in.get(pp);
    }
    k--;
    int j =k;
    while(k >= 0){
        a.big[k] = temp[0 + j - k];
        k--;
    }
    
    return in;
}

ostream& operator<<(ostream& out, const HugeInt& a){
    int i = 199;
    while(a.big[i] == 0)
        i--;
    if(i <= 0)
        out<<0;
    while(i >= 0){
        out<<a.big[i];
        i--;
    }
    return out;
}
