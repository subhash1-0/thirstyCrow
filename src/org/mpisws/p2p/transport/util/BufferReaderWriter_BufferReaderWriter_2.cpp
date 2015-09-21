// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/BufferReaderWriter.java
#include <org/mpisws/p2p/transport/util/BufferReaderWriter_BufferReaderWriter_2.hpp>

#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/util/BufferReaderWriter.hpp>

org::mpisws::p2p::transport::util::BufferReaderWriter_BufferReaderWriter_2::BufferReaderWriter_BufferReaderWriter_2(BufferReaderWriter *BufferReaderWriter_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , BufferReaderWriter_this(BufferReaderWriter_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::util::BufferReaderWriter_BufferReaderWriter_2::receiveException(::java::lang::Exception* exception)
{
    BufferReaderWriter_this->failed = true;
    BufferReaderWriter_this->done(exception);
}

void org::mpisws::p2p::transport::util::BufferReaderWriter_BufferReaderWriter_2::receiveResult(::org::mpisws::p2p::transport::P2PSocket* result)
{
    BufferReaderWriter_this->doneWriting = true;
    BufferReaderWriter_this->done(nullptr);
}

void org::mpisws::p2p::transport::util::BufferReaderWriter_BufferReaderWriter_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::BufferReaderWriter_BufferReaderWriter_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::BufferReaderWriter_BufferReaderWriter_2::getClass0()
{
    return class_();
}

