#include <iostream>
#include <ostream>
#include <utility>
#include "vector.hpp"
#include "array.hpp"

using namespace std;

class point {
    private:
        int x,y;
    public:
        point(int a, int b) : x(a), y(b) {}
        point() : x(0), y(0) {}

        friend ostream& operator<<(ostream& os, point val);
};

ostream& operator<<(ostream& os, point val) {
    os<<'(' << val.x << ',' << val.y << ')' << ' ';
    return os;
}

int main() {
    vect<point> a;
    a.push_back(point(1,2));
    a.push_back(point(3,4));

    vect<point> b(2, point(1,1));

    a.print();
    b.print();

    vect<point> c = a + b;
    c.print();

    c = std::move(b);
    cout<<"b: "; b.print();
    cout<<"c: ";c.print();

    vect<point> d(std::move(a));
    cout<<"a: "; a.print();
    cout<<"d: "; d.print();

    c = c*2;
    cout<<"c*2: "; c.print();

    point tmp = c.pop_back();
    cout<<"tmp point: "<<tmp<<endl;
    c += tmp;

    cout<<"c size: "<<c.getsize()<<endl; 
    cout<<"d size: "<<d.getsize()<<endl; 
    (c<d) ? cout<<"true\n" : cout<<"false\n";
    (c>d) ? cout<<"true\n" : cout<<"false\n";
    (c==d) ? cout<<"true\n" : cout<<"false\n";
    (c<=d) ? cout<<"true\n" : cout<<"false\n";
    (c>=d) ? cout<<"true\n" : cout<<"false\n";

    cout<<"-------Arrays--------\n";
    Array<point, 3> x(point(2,2));
    x.print();
    
    Array<point, 5> y;
    y.set(0, point(1,2));
    y.print();

    Array<point, 3> z = std::move(x);
    
    /* vect<test> a; */
    /* a.push_back(test(4)); */
    /* a.push_back(test(5)); */
    /* a.push_back(test(4)); */
    /* cout<<a.getsize()<<endl; */
    /* cout<<a[0].a<<endl; */

    /* vect<test> b; */
    /* b.push_back(test(6)); */
    /* b.push_back(test(4)); */
    /* b.push_back(test(7)); */
    /* cout<<b.getsize()<<endl; */
    /* cout<<b[0].a<<endl; */

    /* vect<test> c = std::move(a); */
    /* cout<<c.getsize()<<' '<<a.getsize()<<endl; */

    /* Array<test, 4> x; */
    /* cout<<x[0].a<<endl; */

    /* Array<test, 3> y; */
    /* cout<<y[0].a<<endl; */

    /* Array<test, 3> z = std::move(y); */
    /* cout<<z[0].a<<' '<<endl; */
        /* y[0].a<<endl; */ //Genera un error

}
