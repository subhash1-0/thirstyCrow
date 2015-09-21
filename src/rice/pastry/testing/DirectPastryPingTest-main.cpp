#include <rice/pastry/testing/DirectPastryPingTest.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::pastry::testing::DirectPastryPingTest::main(make_args(argc, argv));
    
    return 0;
}