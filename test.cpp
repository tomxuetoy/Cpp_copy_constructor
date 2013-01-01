#include <iostream>
#include <string.h>

using namespace std;

class withCC
{
public:
    withCC() {}
    withCC(const withCC&) {
        cout<<"withCC(withCC&)"<<endl;
    }
};

class woCC
{
    enum {bsz = 100};
    char buf[bsz];
public:
    woCC(const char* msg = 0) {
        memset(buf, 0, bsz);
        if(msg) strncpy(buf, msg, bsz);
    }
    void print(const char* msg = 0)const {
        if(msg) cout<<msg<<":";
        cout<<buf<<endl;
    }
};

class composite
{
    withCC WITHCC;
    woCC WOCC;
public:
    composite() : WOCC("composite()") {}
    void print(const char* msg = 0) {
        cout<<"in composite:"<<endl;
        WOCC.print(msg);
    }
};

int main()
{
    composite c;
    c.print("contents of c");
    cout<<"calling composite copy-constructor"<<endl;
    composite c2 = c;
    c2.print("contents of c2");
}
/*
$ ./a.out 
in composite:
contents of c:composite()
calling composite copy-constructor
withCC(withCC&)
in composite:
contents of c2:composite()

 * */
