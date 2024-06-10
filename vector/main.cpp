#include <iostream>
#include <ostream>
#include <utility>
#include "vector.hpp"

using namespace std;

class test {
    public:
        test() : a(1) {}
        test(int a) : a(a) {}
        int a;
};

int main() {
    vect<test> a;
    a.push_back(test(4));
    a.push_back(test(5));
    a.push_back(test(4));
    cout<<a.getsize()<<endl;

    vect<test> b;
    b.push_back(test(6));
    b.push_back(test(4));
    b.push_back(test(7));
    cout<<b.getsize()<<endl;

    vect<test> c = std::move(a);
    cout<<c.getsize()<<endl;
    cout<<endl<<a.getsize()<<endl;

    vect<vect<int>> aa;
    aa.push_back(vect<int>(2,0));
    aa.push_back(vect<int>(3,3));

    cout<<aa;
}
