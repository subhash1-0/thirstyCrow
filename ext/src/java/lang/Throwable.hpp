// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::java::lang::StackTraceElement, ObjectArray, ::java::io::SerializableArray > StackTraceElementArray;
typedef ::SubArray< ::java::lang::Throwable, ObjectArray, ::java::io::SerializableArray > ThrowableArray;
    } // lang
} // java

struct default_init_tag;

class java::lang::Throwable
    : public virtual Object
    , public virtual ::java::io::Serializable
{

public:
    typedef Object super;

private:
    static bool $assertionsDisabled_;
    static String* CAUSE_CAPTION_;
    static ThrowableArray* EMPTY_THROWABLE_ARRAY_;
    static String* NULL_CAUSE_MESSAGE_;
    static String* SELF_SUPPRESSION_MESSAGE_;
    static String* SUPPRESSED_CAPTION_;
    static ::java::util::List* SUPPRESSED_SENTINEL_;
    static StackTraceElementArray* UNASSIGNED_STACK_;
    Object* backtrace {  };
    Throwable* cause {  };
    String* detailMessage {  };
    static constexpr int64_t serialVersionUID { int64_t(-3042686055658047285LL) };
    StackTraceElementArray* stackTrace {  };
    ::java::util::List* suppressedExceptions {  };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(Throwable* arg0);
    void ctor(String* arg0, Throwable* arg1);
    void ctor(String* arg0, Throwable* arg1, bool arg2, bool arg3);

public:
    void addSuppressed(Throwable* arg0);
    virtual Throwable* fillInStackTrace();
    /*Throwable* fillInStackTrace(int32_t arg0); (private) */
    virtual Throwable* getCause();
    virtual String* getLocalizedMessage();
    virtual String* getMessage();
    /*StackTraceElementArray* getOurStackTrace(); (private) */
    virtual StackTraceElementArray* getStackTrace();

public: /* package */
    virtual int32_t getStackTraceDepth();
    virtual StackTraceElement* getStackTraceElement(int32_t arg0);

public:
    ThrowableArray* getSuppressed();
    virtual Throwable* initCause(Throwable* arg0);
    /*void printEnclosedStackTrace(Throwable_PrintStreamOrWriter* arg0, StackTraceElementArray* arg1, String* arg2, String* arg3, ::java::util::Set* arg4); (private) */
    virtual void printStackTrace();
    virtual void printStackTrace(::java::io::PrintStream* arg0);
    /*void printStackTrace(Throwable_PrintStreamOrWriter* arg0); (private) */
    virtual void printStackTrace(::java::io::PrintWriter* arg0);
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    virtual void setStackTrace(StackTraceElementArray* arg0);
    String* toString() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    Throwable();
    Throwable(String* arg0);
    Throwable(Throwable* arg0);
    Throwable(String* arg0, Throwable* arg1);

public: /* protected */
    Throwable(String* arg0, Throwable* arg1, bool arg2, bool arg3);
protected:
    Throwable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    static String*& CAUSE_CAPTION();
    static ThrowableArray*& EMPTY_THROWABLE_ARRAY();
    static String*& NULL_CAUSE_MESSAGE();
    static String*& SELF_SUPPRESSION_MESSAGE();
    static String*& SUPPRESSED_CAPTION();
    static ::java::util::List*& SUPPRESSED_SENTINEL();
    static StackTraceElementArray*& UNASSIGNED_STACK();
    virtual ::java::lang::Class* getClass0();
};
