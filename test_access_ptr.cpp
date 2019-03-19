#include "access_ptr.hpp"
#include <assert.h>

void test_access_ptr_default_constructs_to_null() {
    jss::access_ptr<int> ap;
    assert(ap.get() == nullptr);
}

void test_access_ptr_can_be_constructed_from_nullptr() {
    jss::access_ptr<int> ap(nullptr);
    assert(ap.get() == nullptr);

    jss::access_ptr<int> ap2=nullptr;
    assert(ap2.get() == nullptr);
    
    [](jss::access_ptr<int> ap3) { assert(ap3.get() == nullptr); }(nullptr);
}

int main() {
    test_access_ptr_default_constructs_to_null();
    test_access_ptr_can_be_constructed_from_nullptr();
}
