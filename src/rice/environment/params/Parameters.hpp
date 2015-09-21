// Generated from /pastry-2.1/src/rice/environment/params/Parameters.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

struct rice::environment::params::Parameters
    : public virtual ::java::lang::Object
{
    virtual void remove(::java::lang::String* name) = 0;
    virtual bool contains(::java::lang::String* name) = 0;
    virtual void store() /* throws(IOException) */ = 0;
    virtual ::java::lang::String* getString(::java::lang::String* paramName) = 0;
    virtual ::java::lang::StringArray* getStringArray_(::java::lang::String* paramName) = 0;
    virtual int32_t getInt(::java::lang::String* paramName) = 0;
    virtual double getDouble(::java::lang::String* paramName) = 0;
    virtual float getFloat(::java::lang::String* paramName) = 0;
    virtual int64_t getLong(::java::lang::String* paramName) = 0;
    virtual bool getBoolean(::java::lang::String* paramName) = 0;
    virtual ::java::net::InetAddress* getInetAddress(::java::lang::String* paramName) /* throws(UnknownHostException) */ = 0;
    virtual ::java::net::InetSocketAddress* getInetSocketAddress(::java::lang::String* paramName) /* throws(UnknownHostException) */ = 0;
    virtual ::java::net::InetSocketAddressArray* getInetSocketAddressArray_(::java::lang::String* paramName) /* throws(UnknownHostException) */ = 0;
    virtual void setString(::java::lang::String* paramName, ::java::lang::String* val) = 0;
    virtual void setStringArray_(::java::lang::String* paramName, ::java::lang::StringArray* val) = 0;
    virtual void setInt(::java::lang::String* paramName, int32_t val) = 0;
    virtual void setDouble(::java::lang::String* paramName, double val) = 0;
    virtual void setFloat(::java::lang::String* paramName, float val) = 0;
    virtual void setLong(::java::lang::String* paramName, int64_t val) = 0;
    virtual void setBoolean(::java::lang::String* paramName, bool val) = 0;
    virtual void setInetAddress(::java::lang::String* paramName, ::java::net::InetAddress* val) = 0;
    virtual void setInetSocketAddress(::java::lang::String* paramName, ::java::net::InetSocketAddress* val) = 0;
    virtual void setInetSocketAddressArray_(::java::lang::String* paramName, ::java::net::InetSocketAddressArray* val) = 0;
    virtual void addChangeListener(ParameterChangeListener* p) = 0;
    virtual void removeChangeListener(ParameterChangeListener* p) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
