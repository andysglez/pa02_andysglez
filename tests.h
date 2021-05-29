// These files should contain test code for all the classes and methods for your implementation
#include "movies.h"
#include <iostream>
using namespace std;

void testOut(string testname, bool passed) {
    if (passed) {
        cout << "PASSED" << endl;
    }
    else {
        cout << testname << " FAILED" << endl;
    }
}

template<typename t>
void AssertEquals(t actual, t expected) {
    if (actual == expected) {
        cout << "PASSED" << endl;
    }
    else {
        cout << "Expected: " << expected << " != " << "Actual: " << actual << endl;
    }
}
void test_nodeconstructor();
void test_nodeconstructor2();
void test_constructor();
void test_getDepth();
void test_insert();
void test_highestrated();

void test_all(){
    test_nodeconstructor();
    test_nodeconstructor2();
    test_constructor();
    test_getDepth();
    test_insert();
    test_highestrated();
}