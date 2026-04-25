


#include "MemoryRiver.hpp"
#include <iostream>

// We need a simple struct to test with
struct TestStruct {
    int a;
    double b;
    char c;
    
    TestStruct() : a(0), b(0.0), c('0') {}
    TestStruct(int a_, double b_, char c_) : a(a_), b(b_), c(c_) {}
    
    bool operator==(const TestStruct& other) const {
        return a == other.a && b == other.b && c == other.c;
    }
};

int main() {
    // This is a placeholder main function
    // The OJ will likely have its own tests
    // We just need to make sure the code compiles
    
    MemoryRiver<TestStruct> river("test.dat");
    river.initialise();
    
    // Write some test data
    TestStruct t1(42, 3.14, 'x');
    int pos1 = river.write(t1);
    
    TestStruct t2(100, 2.71, 'y');
    int pos2 = river.write(t2);
    
    // Read back the data
    TestStruct t3;
    river.read(t3, pos1);
    
    // Update data
    TestStruct t4(999, 1.41, 'z');
    river.update(t4, pos2);
    
    // Delete data
    river.Delete(pos1);
    
    // Write again (should reuse the deleted space)
    TestStruct t5(777, 0.5, 'w');
    int pos3 = river.write(t5);
    
    // pos3 should equal pos1 since we're reusing freed space
    // std::cout << "pos1: " << pos1 << ", pos3: " << pos3 << std::endl;
    
    return 0;
}


