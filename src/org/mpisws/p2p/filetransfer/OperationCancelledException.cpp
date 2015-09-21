// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/OperationCancelledException.java
#include <org/mpisws/p2p/filetransfer/OperationCancelledException.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>

org::mpisws::p2p::filetransfer::OperationCancelledException::OperationCancelledException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::filetransfer::OperationCancelledException::OperationCancelledException(Receipt* receipt) 
    : OperationCancelledException(*static_cast< ::default_init_tag* >(0))
{
    ctor(receipt);
}

void org::mpisws::p2p::filetransfer::OperationCancelledException::ctor(Receipt* receipt)
{
    super::ctor(::java::lang::StringBuilder().append(u"Remote connection cancelled transfer of "_j)->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

org::mpisws::p2p::filetransfer::Receipt* org::mpisws::p2p::filetransfer::OperationCancelledException::getReceipt()
{
    return receipt;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::OperationCancelledException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.OperationCancelledException", 55);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::OperationCancelledException::getClass0()
{
    return class_();
}

