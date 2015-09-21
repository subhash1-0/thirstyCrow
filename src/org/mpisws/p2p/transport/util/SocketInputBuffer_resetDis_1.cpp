// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketInputBuffer.java
#include <org/mpisws/p2p/transport/util/SocketInputBuffer_resetDis_1.hpp>

#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>

org::mpisws::p2p::transport::util::SocketInputBuffer_resetDis_1::SocketInputBuffer_resetDis_1(SocketInputBuffer *SocketInputBuffer_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketInputBuffer_this(SocketInputBuffer_this)
{
    clinit();
    ctor();
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer_resetDis_1::read(::int8_tArray* b) /* throws(IOException) */
{
    return SocketInputBuffer_this->readInternal(b);
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer_resetDis_1::read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    return SocketInputBuffer_this->readInternal(b, off, len);
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer_resetDis_1::read() /* throws(IOException) */
{
    return SocketInputBuffer_this->readInternal();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::SocketInputBuffer_resetDis_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::SocketInputBuffer_resetDis_1::getClass0()
{
    return class_();
}

