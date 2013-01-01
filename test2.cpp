#include <iostream>

class A
{
    int a;
public:
    A() {
        std::cout << "A::Default constructor" << std::endl;
    }

    A(const A& rhs) {
        std::cout << "A::Copy constructor" << std::endl;
    }
};

class B : public A
{
    int b;
public:
    B() {
        std::cout << "B::Default constructor" << std::endl;
    }
};

class C
{
    int c;
    A a;
public:
    C() {
        std::cout << "C::Default constructor" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    std::cout << "Creating B" << std::endl;
    B b1;
    std::cout << "Creating B by copy" << std::endl;
    B b2(b1);
    std::cout << "Creating B by assign" << std::endl;
    B b3 = b1;
    std::cout << "Creating C by assign" << std::endl;
    C c1;
    C c2 = c1;
    return 0;
}
/*
$ ./a.out 
Creating B
A::Default constructor
B::Default constructor
Creating B by copy
A::Copy constructor
Creating B by assign
A::Copy constructor
Creating C by assign
A::Default constructor
C::Default constructor
A::Copy constructor
 * */
