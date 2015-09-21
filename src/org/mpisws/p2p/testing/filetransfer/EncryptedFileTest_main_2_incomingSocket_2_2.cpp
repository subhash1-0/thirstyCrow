// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/EncryptedFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_2_incomingSocket_2_2.hpp>

#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_2.hpp>

org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_2_incomingSocket_2_2::EncryptedFileTest_main_2_incomingSocket_2_2(EncryptedFileTest_main_2 *EncryptedFileTest_main_2_this, ::java::lang::String* prefix)
    : super(*static_cast< ::default_init_tag* >(0))
    , EncryptedFileTest_main_2_this(EncryptedFileTest_main_2_this)
{
    clinit();
    ctor(prefix);
}

void org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_2_incomingSocket_2_2::fileTransferred(::org::mpisws::p2p::filetransfer::FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming)
{
    super::fileTransferred(receipt, bytesTransferred, total, incoming);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_2_incomingSocket_2_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_2_incomingSocket_2_2::getClass0()
{
    return class_();
}

