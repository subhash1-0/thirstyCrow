#include <rice/tutorial/lesson1/DistTutorial.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::tutorial::lesson1::DistTutorial::main(make_args(argc, argv));
    
    return 0;
}
