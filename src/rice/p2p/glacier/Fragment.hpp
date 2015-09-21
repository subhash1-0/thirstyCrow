// Generated from /pastry-2.1/src/rice/p2p/glacier/Fragment.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::glacier::Fragment
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-809948154556539350LL) };

public:
    ::int8_tArray* payload {  };
protected:
    void ctor(int32_t _size);

public:
    virtual ::int8_tArray* getPayload();

private:
    void writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */;
    void readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

    // Generated
    Fragment(int32_t _size);
    Fragment(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    Fragment(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
