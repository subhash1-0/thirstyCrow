#include <rice/p2p/util/testing/IdBloomFilterUnit.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::rice::p2p::util::testing::IdBloomFilterUnit::main(make_args(argc, argv));
    
    return 0;
}
