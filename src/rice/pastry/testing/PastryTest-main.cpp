#include <rice/pastry/testing/PastryTest.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::pastry::testing::PastryTest::main(make_args(argc, argv));
    
    return 0;
}
