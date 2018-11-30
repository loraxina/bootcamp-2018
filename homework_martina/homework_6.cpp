/*
Homework

Write code supporting two or more minimization methods.

The abstract interface is:

struct minimizer {
    virtual double operator()( ... ) = 0;
    virtual ~minimizer() {}
};

The main function contains:

unique_ptr<minimizer> my_minimizer;
switch(minimizer_choice){
    case 1: my_minimizer = make_unique<method1>(new method1); break;
    case 2: my_minimizer = make_unique<method2>(new method2); break;
}
(*my_minimizer)( … );


Note: no need to actually implement a proper minimization.  Just print that it was called.
*/

#include <iostream>
#include <memory>



struct minimizer {
    virtual double operator()( ... ) = 0;
    ~minimizer() {};
};


struct method1 : minimizer {
    method1() {};
    method1(method1* my_min) {*this = *my_min;};
    virtual double operator()( ... ) {
        std::cout << "method1 is running" << std::endl;
        return 42.;
    }
};

struct method2 : minimizer {
    method2() {};
    method2(method2* my_min) {*this = *my_min;};
    virtual double operator()( ... ) {
        std::cout << "method2 is running" << std::endl;
        return 42.;
    }
};

int main() {
    int minimizer_choice;
    std::cout << "Which minimizer?" << std::endl;
    std::cin >> minimizer_choice;
    std::unique_ptr<minimizer> my_minimizer;

    switch(minimizer_choice){
        case 1: my_minimizer = std::make_unique<method1>(new method1); break;
        case 2: my_minimizer = std::make_unique<method2>(new method2); break;
        default: std::cout << "This minimizer is not yet defined, choose 1 or 2" << std::endl; return 1;
    }
    (*my_minimizer)( 42 );
    
    return 0;
}