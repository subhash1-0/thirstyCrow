// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::ObjectInputStream_HandleTable_HandleList, ::java::lang::ObjectArray > ObjectInputStream_HandleTable_HandleListArray;
    } // io
} // java

struct default_init_tag;

class java::io::ObjectInputStream_HandleTable
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int8_t STATUS_EXCEPTION { int8_t(3) };
    static constexpr int8_t STATUS_OK { int8_t(1) };
    static constexpr int8_t STATUS_UNKNOWN { int8_t(2) };

public: /* package */
    ObjectInputStream_HandleTable_HandleListArray* deps {  };
    ::java::lang::ObjectArray* entries {  };
    int32_t lowDep {  };
    int32_t size_ {  };
    ::int8_tArray* status {  };

protected:
    void ctor(int32_t arg0);

public: /* package */
    virtual int32_t assign(::java::lang::Object* arg0);
    virtual void clear();
    virtual void finish(int32_t arg0);
    /*void grow(); (private) */
    virtual ::java::lang::ClassNotFoundException* lookupException(int32_t arg0);
    virtual ::java::lang::Object* lookupObject(int32_t arg0);
    virtual void markDependency(int32_t arg0, int32_t arg1);
    virtual void markException(int32_t arg0, ::java::lang::ClassNotFoundException* arg1);
    virtual void setObject(int32_t arg0, ::java::lang::Object* arg1);
    virtual int32_t size();

    // Generated
    ObjectInputStream_HandleTable(int32_t arg0);
protected:
    ObjectInputStream_HandleTable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
