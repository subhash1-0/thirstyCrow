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
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class java::lang::Runtime
    : public virtual Object
{

public:
    typedef Object super;

private:
    static Runtime* currentRuntime_;

    /*void ctor(); (private) */

public:
    virtual void addShutdownHook(Thread* arg0);
    virtual int32_t availableProcessors();
    virtual Process* exec(String* arg0);
    virtual Process* exec(StringArray* arg0);
    virtual Process* exec(String* arg0, StringArray* arg1);
    virtual Process* exec(StringArray* arg0, StringArray* arg1);
    virtual Process* exec(String* arg0, StringArray* arg1, ::java::io::File* arg2);
    virtual Process* exec(StringArray* arg0, StringArray* arg1, ::java::io::File* arg2);
    virtual void exit(int32_t arg0);
    virtual int64_t freeMemory();
    virtual void gc();
    virtual ::java::io::InputStream* getLocalizedInputStream(::java::io::InputStream* arg0);
    virtual ::java::io::OutputStream* getLocalizedOutputStream(::java::io::OutputStream* arg0);
    static Runtime* getRuntime();
    virtual void halt(int32_t arg0);
    virtual void load(String* arg0);

public: /* package */
    virtual void load0(Class* arg0, String* arg1);

public:
    virtual void loadLibrary(String* arg0);

public: /* package */
    virtual void loadLibrary0(Class* arg0, String* arg1);

public:
    virtual int64_t maxMemory();
    virtual bool removeShutdownHook(Thread* arg0);
    virtual void runFinalization();
    /*static void runFinalization0(); (private) */
    static void runFinalizersOnExit(bool arg0);
    virtual int64_t totalMemory();
    virtual void traceInstructions(bool arg0);
    virtual void traceMethodCalls(bool arg0);

    // Generated
    Runtime();
protected:
    Runtime(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static Runtime*& currentRuntime();
    virtual ::java::lang::Class* getClass0();
};
