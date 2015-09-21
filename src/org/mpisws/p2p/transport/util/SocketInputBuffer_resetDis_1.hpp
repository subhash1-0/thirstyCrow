// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketInputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/io/InputStream.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::SocketInputBuffer_resetDis_1
    : public ::java::io::InputStream
{

public:
    typedef ::java::io::InputStream super;
    int32_t read(::int8_tArray* b) /* throws(IOException) */ override;
    int32_t read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ override;
    int32_t read() /* throws(IOException) */ override;

    // Generated
    SocketInputBuffer_resetDis_1(SocketInputBuffer *SocketInputBuffer_this);
    static ::java::lang::Class *class_();
    SocketInputBuffer *SocketInputBuffer_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SocketInputBuffer;
};
