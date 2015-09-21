#include <rice/tutorial/scribe/ScribeTutorial.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::tutorial::scribe::ScribeTutorial::main(make_args(argc, argv));
    
    return 0;
}
