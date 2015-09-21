#include <org/mpisws/p2p/testing/transportlayer/peerreview/LogSnippitTest.hpp>

extern void init_jvm();
extern java::lang::StringArray* make_args(int args, char** argv);

int main(int argc, char** argv)
{
    init_jvm();
    
    ::org::mpisws::p2p::testing::transportlayer::peerreview::LogSnippitTest::main(make_args(argc, argv));
    
    return 0;
}
