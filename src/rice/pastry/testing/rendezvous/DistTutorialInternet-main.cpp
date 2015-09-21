#include <rice/pastry/testing/rendezvous/DistTutorialInternet.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::pastry::testing::rendezvous::DistTutorialInternet::main(make_args(argc, argv));
    
    return 0;
}
