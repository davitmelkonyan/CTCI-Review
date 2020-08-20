//12.1: Write a method to print the last K lines of input file using c++

//use circular array so we replace oldest item whcih is tracked in separate variable
//each time we read new line, we purge oldest line from array
#include <iostream>
#include <fstream>
using namespace std;

void printLast10Lines(char* fileName){
    const int K = 10;
    ifstream file (fileName);
    string L[K];
    int size = 0;

    while (file.peek()!= EOF) //so line ending is not considered a separate line
    {
        getline(file, L[size % K]);
        size++;
    }

    int start = size > K ? (size % K) : 0;
    int count = min(K, size);

    //print elems in order they were read
    for(int i=0;i<count;i++){
        cout<< L[(start + i)%K]<<endl;
    }
}

int main(){
    char * p = "text";
    printLast10Lines(p);
    return 0;
}