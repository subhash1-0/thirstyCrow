// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <java/net/SocketAddress.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::ObjectStreamField, ::java::lang::ObjectArray, ::java::lang::ComparableArray > ObjectStreamFieldArray;
    } // io
} // java

struct default_init_tag;

class java::net::InetSocketAddress
    : public SocketAddress
{

public:
    typedef SocketAddress super;

private:
    static int64_t FIELDS_OFFSET_;
    static ::sun::misc::Unsafe* UNSAFE_;
    InetSocketAddress_InetSocketAddressHolder* holder {  };
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;
    static constexpr int64_t serialVersionUID { int64_t(5076001401234631237LL) };

protected:
    void ctor(int32_t arg0);
    void ctor(InetAddress* arg0, int32_t arg1);
    void ctor(::java::lang::String* arg0, int32_t arg1);
    /*void ctor(int32_t arg0, ::java::lang::String* arg1); (private) */
    /*static ::java::lang::String* checkHost(::java::lang::String* arg0); (private) */
    /*static int32_t checkPort(int32_t arg0); (private) */

public:
    static InetSocketAddress* createUnresolved(::java::lang::String* arg0, int32_t arg1);
    bool equals(::java::lang::Object* arg0) override;
    InetAddress* getAddress();
    ::java::lang::String* getHostName();
    ::java::lang::String* getHostString();
    int32_t getPort();
    int32_t hashCode() override;
    bool isUnresolved();
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    /*void readObjectNoData(); (private) */
    ::java::lang::String* toString() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    InetSocketAddress(int32_t arg0);
    InetSocketAddress(InetAddress* arg0, int32_t arg1);
    InetSocketAddress(::java::lang::String* arg0, int32_t arg1);
protected:
    InetSocketAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static int64_t& FIELDS_OFFSET();
    static ::sun::misc::Unsafe*& UNSAFE();
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();
    virtual ::java::lang::Class* getClass0();
};
