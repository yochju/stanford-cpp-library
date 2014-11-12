/*
 * Test file for verifying the Stanford C++ autograder lib functionality.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "platform.h"
#include "simpio.h"
#include "private/version.h"
#include "exceptions.h"
using namespace std;

/*
 * Code that autograderMain() runs before it starts the autograding test cases.
 */
void before() {
    cout << "THIS IS BEFORE!" << endl;
    cout << "THIS IS BEFORE!" << endl;
    cout << "THIS IS BEFORE!" << endl;
}

/*
 * Code that autograderMain() runs after it ends the autograding test cases.
 */
void after() {
    cout << "THIS IS AFTER!" << endl;
    cout << "THIS IS AFTER!" << endl;
    cout << "THIS IS AFTER!" << endl;
}

namespace MyNS {
    class LoL {
    public:
        static int cCcCc_cCcCc(int, char*, double, char, bool) {
            cout << "function c start" << endl;
            cout << endl;
            // error("blargh!");
            Vector<int> v;
            v.get(42);  // lolol
            cout << "function c end" << endl;
            return 0;
        }
    };
}

void b() {
    cout << "function b start" << endl;
    MyNS::LoL::cCcCc_cCcCc(0, NULL, 0, 0, false);
    cout << "function b end" << endl;
}

void a() {
    cout << "function a start" << endl;
    b();
    cout << "function a end" << endl;
}

void exceptionTest() {
    a();
}

void coutCerrMixTest() {
    cout << "Hello, world! This is main!" << endl;
    cerr << "This message comes from cerr" << endl;
    cout << "Another one from cout!" << endl;
    cerr << "This message ALSO comes from cerr" << endl;
    cout << "A third one from cout!" << endl;
    cerr << "HOW ";
    cout << "about ";
    cerr << "A ";
    cout << "mixed ";
    cerr << "LINE??";
    cout << endl;
}

void stackOverflowTest(int n = 0) {
    int a[100] = {0};
    if (a[0] || n % 1000 == 0) {
        cout << "stack overflow n=" << n << endl;
    }
    stackOverflowTest(n+1);
}

void segC() {
    // divide by 0 (generate SIGFPE)
//     int a = 1;
//     int b = 0;
//     cout << (a/b) << endl;
    
    // dereference a NULL pointer (generate SIGSEGV)
    int* foo = 0;
    cout << *foo << endl;
}

void segB() {
    segC();
}

void segA() {
    segB();
}

void segfaultTest() {
    cout << "Hello, world!" << endl;
    segA();
}

#include "platform.h"

/*
 * This just needs to be here to become 'studentMain' so program will compile
 */
int main() {
//    cout << "Hello, world! This is main!" << endl;
//    for (int i = 0; i < 100; i++) {
//        cout << "hello" << endl;
//    }

//    getPlatform()->setStackSize(1024*1024*128);
    
//    coutCerrMixTest();
    
//    exceptionTest();
    
    segfaultTest();
//    stackOverflowTest();

//    string input = getLine("How are you doing? ");
//    cout << "You said, \"" << input << "\"." << endl;
//    cout << "The end." << endl;
    
    return 0;
}
