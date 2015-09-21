// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/TransferFailedException.java
#include <org/mpisws/p2p/filetransfer/TransferFailedException.hpp>

#include <org/mpisws/p2p/filetransfer/Receipt.hpp>

org::mpisws::p2p::filetransfer::TransferFailedException::TransferFailedException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::filetransfer::TransferFailedException::TransferFailedException(Receipt* receipt) 
    : TransferFailedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(receipt);
}

void org::mpisws::p2p::filetransfer::TransferFailedException::ctor(Receipt* receipt)
{
    super::ctor();
    this->receipt = receipt;
}

org::mpisws::p2p::filetransfer::Receipt* org::mpisws::p2p::filetransfer::TransferFailedException::getReceipt()
{
    return receipt;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::TransferFailedException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.TransferFailedException", 51);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::TransferFailedException::getClass0()
{
    return class_();
}

