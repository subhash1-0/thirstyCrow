// Generated from /pastry-2.1/src/rice/environment/params/simple/SimpleParameters.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/params/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/params/Parameters.hpp>

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

struct default_init_tag;

class rice::environment::params::simple::SimpleParameters
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::params::Parameters
{

public:
    typedef ::java::lang::Object super;

private:
    SimpleParameters_MyProperties* properties {  };
    SimpleParameters_MyProperties* defaults {  };
    ::java::util::Set* changeListeners {  };
    ::java::lang::String* configFileName {  };
    static ::java::lang::String* FILENAME_EXTENSION_;
    static ::java::lang::String* ARRAY_SPACER_;
    static ::java::lang::String* defaultParamsFile_;
protected:
    void ctor(::java::lang::StringArray* orderedDefaults, ::java::lang::String* mutableConfigFileName);

public:
    virtual ::java::util::Enumeration* enumerateDefaults();
    virtual ::java::util::Enumeration* enumerateNonDefaults();

public: /* protected */
    virtual ::java::net::InetSocketAddress* parseInetSocketAddress(::java::lang::String* name) /* throws(UnknownHostException) */;
    virtual ::java::lang::String* getProperty(::java::lang::String* name);
    virtual void setProperty(::java::lang::String* name, ::java::lang::String* value);

public:
    void remove(::java::lang::String* name) override;
    bool contains(::java::lang::String* name) override;
    int32_t getInt(::java::lang::String* name) override;
    double getDouble(::java::lang::String* name) override;
    float getFloat(::java::lang::String* name) override;
    int64_t getLong(::java::lang::String* name) override;
    bool getBoolean(::java::lang::String* name) override;
    ::java::net::InetAddress* getInetAddress(::java::lang::String* name) /* throws(UnknownHostException) */ override;
    ::java::net::InetSocketAddress* getInetSocketAddress(::java::lang::String* name) /* throws(UnknownHostException) */ override;
    ::java::net::InetSocketAddressArray* getInetSocketAddressArray_(::java::lang::String* name) /* throws(UnknownHostException) */ override;
    ::java::lang::String* getString(::java::lang::String* name) override;
    ::java::lang::StringArray* getStringArray_(::java::lang::String* name) override;
    void setInt(::java::lang::String* name, int32_t value) override;
    void setDouble(::java::lang::String* name, double value) override;
    void setFloat(::java::lang::String* name, float value) override;
    void setLong(::java::lang::String* name, int64_t value) override;
    void setBoolean(::java::lang::String* name, bool value) override;
    void setInetAddress(::java::lang::String* name, ::java::net::InetAddress* value) override;
    void setInetSocketAddress(::java::lang::String* name, ::java::net::InetSocketAddress* value) override;
    void setInetSocketAddressArray_(::java::lang::String* name, ::java::net::InetSocketAddressArray* value) override;
    void setString(::java::lang::String* name, ::java::lang::String* value) override;
    void setStringArray_(::java::lang::String* name, ::java::lang::StringArray* value) override;
    void store() /* throws(IOException) */ override;
    void addChangeListener(::rice::environment::params::ParameterChangeListener* p) override;
    void removeChangeListener(::rice::environment::params::ParameterChangeListener* p) override;

private:
    void fireChangeEvent(::java::lang::String* name, ::java::lang::String* val);

    // Generated

public:
    SimpleParameters(::java::lang::StringArray* orderedDefaults, ::java::lang::String* mutableConfigFileName);
protected:
    SimpleParameters(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& FILENAME_EXTENSION();
    static ::java::lang::String*& ARRAY_SPACER();
    static ::java::lang::String*& defaultParamsFile();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimpleParameters_MyProperties;
    friend class SimpleParameters_MyProperties_keys_1;
};
