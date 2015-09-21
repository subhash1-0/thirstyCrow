// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/FileInputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/io/DataInputStream.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::FileInputBuffer
    : public ::java::io::DataInputStream
    , public virtual ::rice::p2p::commonapi::rawserialization::InputBuffer
{

public:
    typedef ::java::io::DataInputStream super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    ::java::io::File* file {  };
protected:
    void ctor(::java::io::File* f, ::rice::environment::logging::Logger* logger) /* throws(FileNotFoundException) */;
    void ctor(::java::lang::String* fileName, ::rice::environment::logging::Logger* logger) /* throws(FileNotFoundException) */;

public:
    int32_t bytesRemaining() override;
    ::java::lang::String* toString() override;

    // Generated
    FileInputBuffer(::java::io::File* f, ::rice::environment::logging::Logger* logger);
    FileInputBuffer(::java::lang::String* fileName, ::rice::environment::logging::Logger* logger);
protected:
    FileInputBuffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t read(::int8_tArray* b);
    virtual int32_t read(::int8_tArray* b, int32_t off, int32_t len);
    virtual bool readBoolean();
    virtual int8_t readByte();
    virtual char16_t readChar();
    virtual double readDouble();
    virtual float readFloat();
    virtual int32_t readInt();
    virtual int64_t readLong();
    virtual int16_t readShort();
    virtual ::java::lang::String* readUTF();
    static ::java::lang::String* readUTF(::java::io::DataInput* arg0);
    int32_t read();

private:
    virtual ::java::lang::Class* getClass0();
};
