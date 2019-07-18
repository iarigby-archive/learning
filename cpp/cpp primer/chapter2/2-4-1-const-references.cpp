#include <type_traits>
void foo1() {

}

void foo2() {

}
int main() {
    // int i = 42;
    // const int &r1 = i;
    // const int &r2 = 42;
    // const int &r3 = r1 * 2;    
    
    // double dval = 3.14;
    // const int &ri = dval;
    std::is_void<decltype(foo1())>::value;// a = foo2();
}
