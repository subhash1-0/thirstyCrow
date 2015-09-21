// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketInputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::SocketInputBuffer
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::InputBuffer
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::P2PSocket* socket {  };
    ::java::nio::ByteBuffer* readPtr {  };
    ::java::nio::ByteBuffer* writePtr {  };
    ::int8_tArray* cache {  };
    ::java::nio::ByteBuffer* one {  };
    ::java::nio::ByteBuffer* two {  };
    ::java::nio::ByteBuffer* four {  };
    ::java::nio::ByteBuffer* eight {  };
    int32_t initialSize {  };
    ::java::io::DataInputStream* dis {  };
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* socket);
    void ctor(::org::mpisws::p2p::transport::P2PSocket* socket, int32_t size);

private:
    void resetDis();

public:
    int32_t bytesRemaining() override;
    virtual void reset();
    virtual int32_t size();
    virtual int32_t readInternal(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */;
    virtual int32_t readInternal(::int8_tArray* b) /* throws(IOException) */;
    virtual int32_t readInternal() /* throws(IOException) */;
    int32_t read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ override;
    int32_t read(::int8_tArray* b) /* throws(IOException) */ override;
    int8_t readByte() /* throws(IOException) */ override;
    bool readBoolean() /* throws(IOException) */ override;
    char16_t readChar() /* throws(IOException) */ override;
    double readDouble() /* throws(IOException) */ override;
    float readFloat() /* throws(IOException) */ override;
    int32_t readInt() /* throws(IOException) */ override;
    int64_t readLong() /* throws(IOException) */ override;
    int16_t readShort() /* throws(IOException) */ override;
    ::java::lang::String* readUTF() /* throws(IOException) */ override;

private:
    int32_t needBytes(int32_t num, bool fail) /* throws(IOException) */;
    int32_t readBytesIntoCache(int32_t num) /* throws(IOException) */;

public:
    virtual void clear() /* throws(IOException) */;

private:
    void grow();

    // Generated

public:
    SocketInputBuffer(::org::mpisws::p2p::transport::P2PSocket* socket);
    SocketInputBuffer(::org::mpisws::p2p::transport::P2PSocket* socket, int32_t size);
protected:
    SocketInputBuffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SocketInputBuffer_resetDis_1;
};
