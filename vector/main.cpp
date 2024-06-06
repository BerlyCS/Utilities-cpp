#include <iostream>
#include "vector.hpp"

using namespace std;

int main() {
    
    vect<int> p;
    p.push_back(5);
    p.push_back(6);
    p.print();
    cout<<p[0]<<endl;
    p[0] = 1;
    cout<<p[0]<<endl;
    p.remove(1);
    p.insert(0, 8);
    p.print();
}
