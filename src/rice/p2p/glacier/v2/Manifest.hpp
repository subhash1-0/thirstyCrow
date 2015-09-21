// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/Manifest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

struct default_init_tag;

class rice::p2p::glacier::v2::Manifest
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-436805143199825662LL) };

public: /* protected */
    ::int8_tArray* objectHash {  };
    ::int8_tArrayArray* fragmentHash {  };
    ::int8_tArray* signature {  };
    int64_t expirationDate {  };
protected:
    void ctor(::int8_tArray* objectHash, ::int8_tArrayArray* fragmentHash, int64_t expirationDate);

public:
    virtual ::int8_tArray* getObjectHash();
    virtual ::int8_tArray* getFragmentHash(int32_t fragmentID);
    virtual ::int8_tArrayArray* getFragmentHashes();
    virtual ::int8_tArray* getSignature();
    virtual void setSignature(::int8_tArray* signature);
    virtual int64_t getExpiration();
    virtual void update(int64_t newExpirationDate, ::int8_tArray* newSignature);
    virtual bool validatesFragment(::rice::p2p::glacier::Fragment* fragment, int32_t fragmentID, ::rice::environment::logging::Logger* logger);

private:
    static ::java::lang::String* dump(::int8_tArray* data, bool linebreak);

public:
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* toStringFull();

private:
    void writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */;
    void readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */;

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

    // Generated

public:
    Manifest(::int8_tArray* objectHash, ::int8_tArrayArray* fragmentHash, int64_t expirationDate);
    Manifest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    Manifest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
