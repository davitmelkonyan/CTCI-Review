//implement void reverse(char* str) in C which reverses a null-terminating string
#include <iostream>
#include <fstream>
using namespace std;


void reverse( char* str){
    char* end = str;
    char temp;
    if(str){
        while(*end){++end;} //finding end of string
        --end;
    }
    while(str<end){       //swap from front and back untill meet in the middle
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

int main(){
    char p[30] = "String";
    reverse(p);
    cout<<p;
    return 0;
}