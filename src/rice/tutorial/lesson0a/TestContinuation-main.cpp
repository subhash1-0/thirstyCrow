#include <rice/tutorial/lesson0a/TestContinuation.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::tutorial::lesson0a::TestContinuation::main(make_args(argc, argv));
    
    return 0;
}
