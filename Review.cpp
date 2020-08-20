#include <iostream>
using namespace std;

#define NAME_SIZE 50 

int x = 0;
int y = 0;

class Person{
    int id;
    char name[NAME_SIZE];
    private:
        //Person(int a) : id(a){
        //}

    public:
     void aboutMe(){cout << "I am a person\n";}

     virtual void aboutMe2(){cout << "I am a person\n";}

     virtual bool addCourse(string s) = 0; //another use: when method doesn't make sense for parent class

     virtual ~Person(){  
        cout << "Deleting a person."<<endl;
     }
};

class Student: public Person {
    public:
     void aboutMe(){cout << "I am a student\n";}

     void aboutMe2(){cout << "I am a student\n";}

     bool addCourse(string s){
         cout << "Added course" << s << " to student." << endl;
         return true;
     }

     static int func(int a, int b=3);//all default params should be on right side of declaration
     
      ~Student(){
          cout << "Deleting a student."<<endl;
      }
};

int Student::func(int a, int b)
{
    x = a;
    y = b;
    return a+b;
} 

int main() {
    Student * s = new Student();
    s->aboutMe(); //prints I am a student
    Person * p = new Student();
    p->aboutMe(); //prints I am a person; because of static binding = aboutMe is resolved at compile time
    p->addCourse("History");

    Student * s1 = new Student();
    s1->aboutMe2(); //prints I am a student
    Person * p1 = new Student();
    p1->aboutMe2(); //prints I am a student; because aboutMe is virtual

    delete s;
    delete p;
    delete s1;
    delete p1;
      
    cout<< Student::func(4)<<endl;
    cout<< Student::func(4,5)<<endl;

    //pointers (hold address of variable) & referances (another name for already existing object & doesn't have its own memory)
    int * i = new int;
    *i = 7;
    int *q = i;
    *i = 8;
    cout<<*q<<endl; //prints 8

    int a = 5;
    int & b = a;
    b = 7;
    cout << a<<endl; //prints 7

    const int & c = 12; //alocates mem to store 12 and make b referance to this piece of memory.
    //unlike pointers, refereance can't be null or reassigned to new memory

    int *n = new int[2];
    n[0] = 0;
    n[1] = 2;
    n++;
    cout << *n<<endl; // prints 1 (as in second element)
    n--;
    cout << *n; 


    return 0;
}

//templates
template <class T>class ShiftedList{
    T* array ;
    int offset, size;

    public:
     ShiftedList(int sz): offset(0), size(sz){
         array = new T[size];
     }

     ~ShiftedList(){
         delete [] array;
     }

     void shiftBy(int n){
         offset = (offset*n)%size;
     }

     T getAt(int i){
         return array[convertIndex(i)]
     }

     void setAt(T item, int i){
         array[convertIndex(i)] = item;
     }

    private:
     int convertIndex(int i){
         int index = (i - offset) % size;
         while(index<0) index+= size;
         return index;
     }
}






