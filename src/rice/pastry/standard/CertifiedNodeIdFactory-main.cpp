#include <rice/pastry/standard/CertifiedNodeIdFactory.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::pastry::standard::CertifiedNodeIdFactory::main(make_args(argc, argv));
    
    return 0;
}
