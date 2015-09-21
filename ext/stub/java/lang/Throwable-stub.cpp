// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Throwable.hpp>

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

extern void unimplemented_(const char16_t* name);
java::lang::Throwable::Throwable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Throwable::Throwable()
    : Throwable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Throwable::Throwable(String* arg0)
    : Throwable(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Throwable::Throwable(Throwable* arg0)
    : Throwable(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Throwable::Throwable(String* arg0, Throwable* arg1)
    : Throwable(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::Throwable::Throwable(String* arg0, Throwable* arg1, bool arg2, bool arg3)
    : Throwable(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}

bool& java::lang::Throwable::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::lang::Throwable::$assertionsDisabled_;
java::lang::String*& java::lang::Throwable::CAUSE_CAPTION()
{
    clinit();
    return CAUSE_CAPTION_;
}
java::lang::String* java::lang::Throwable::CAUSE_CAPTION_;
java::lang::ThrowableArray*& java::lang::Throwable::EMPTY_THROWABLE_ARRAY()
{
    clinit();
    return EMPTY_THROWABLE_ARRAY_;
}
java::lang::ThrowableArray* java::lang::Throwable::EMPTY_THROWABLE_ARRAY_;
java::lang::String*& java::lang::Throwable::NULL_CAUSE_MESSAGE()
{
    clinit();
    return NULL_CAUSE_MESSAGE_;
}
java::lang::String* java::lang::Throwable::NULL_CAUSE_MESSAGE_;
java::lang::String*& java::lang::Throwable::SELF_SUPPRESSION_MESSAGE()
{
    clinit();
    return SELF_SUPPRESSION_MESSAGE_;
}
java::lang::String* java::lang::Throwable::SELF_SUPPRESSION_MESSAGE_;
java::lang::String*& java::lang::Throwable::SUPPRESSED_CAPTION()
{
    clinit();
    return SUPPRESSED_CAPTION_;
}
java::lang::String* java::lang::Throwable::SUPPRESSED_CAPTION_;
java::util::List*& java::lang::Throwable::SUPPRESSED_SENTINEL()
{
    clinit();
    return SUPPRESSED_SENTINEL_;
}
java::util::List* java::lang::Throwable::SUPPRESSED_SENTINEL_;
java::lang::StackTraceElementArray*& java::lang::Throwable::UNASSIGNED_STACK()
{
    clinit();
    return UNASSIGNED_STACK_;
}
java::lang::StackTraceElementArray* java::lang::Throwable::UNASSIGNED_STACK_;
constexpr int64_t java::lang::Throwable::serialVersionUID;

void ::java::lang::Throwable::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Throwable::ctor()");
}

void ::java::lang::Throwable::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Throwable::ctor(String* arg0)");
}

void ::java::lang::Throwable::ctor(Throwable* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Throwable::ctor(Throwable* arg0)");
}

void ::java::lang::Throwable::ctor(String* arg0, Throwable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Throwable::ctor(String* arg0, Throwable* arg1)");
}

void ::java::lang::Throwable::ctor(String* arg0, Throwable* arg1, bool arg2, bool arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Throwable::ctor(String* arg0, Throwable* arg1, bool arg2, bool arg3)");
}

void java::lang::Throwable::addSuppressed(Throwable* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Throwable::addSuppressed(Throwable* arg0)");
}

java::lang::Throwable* java::lang::Throwable::fillInStackTrace()
{ /* stub */
    unimplemented_(u"java::lang::Throwable* java::lang::Throwable::fillInStackTrace()");
    return 0;
}

java::lang::Throwable* java::lang::Throwable::getCause()
{ /* stub */
return cause ; /* getter */
}

java::lang::String* java::lang::Throwable::getLocalizedMessage()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Throwable::getLocalizedMessage()");
    return 0;
}

java::lang::String* java::lang::Throwable::getMessage()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Throwable::getMessage()");
    return 0;
}

/* private: java::lang::StackTraceElementArray* java::lang::Throwable::getOurStackTrace() */
java::lang::StackTraceElementArray* java::lang::Throwable::getStackTrace()
{ /* stub */
return stackTrace ; /* getter */
}

java::lang::ThrowableArray* java::lang::Throwable::getSuppressed()
{ /* stub */
    unimplemented_(u"java::lang::ThrowableArray* java::lang::Throwable::getSuppressed()");
    return 0;
}

java::lang::Throwable* java::lang::Throwable::initCause(Throwable* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Throwable* java::lang::Throwable::initCause(Throwable* arg0)");
    return 0;
}

/* private: void java::lang::Throwable::printEnclosedStackTrace(Throwable_PrintStreamOrWriter* arg0, StackTraceElementArray* arg1, String* arg2, String* arg3, ::java::util::Set* arg4) */
void java::lang::Throwable::printStackTrace()
{ /* stub */
    unimplemented_(u"void java::lang::Throwable::printStackTrace()");
}

void java::lang::Throwable::printStackTrace(::java::io::PrintStream* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Throwable::printStackTrace(::java::io::PrintStream* arg0)");
}

/* private: void java::lang::Throwable::printStackTrace(Throwable_PrintStreamOrWriter* arg0) */
void java::lang::Throwable::printStackTrace(::java::io::PrintWriter* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Throwable::printStackTrace(::java::io::PrintWriter* arg0)");
}

/* private: void java::lang::Throwable::readObject(::java::io::ObjectInputStream* arg0) */
void java::lang::Throwable::setStackTrace(StackTraceElementArray* arg0)
{ /* stub */
    this->stackTrace = arg0; /* setter */
}

java::lang::String* java::lang::Throwable::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Throwable::toString()");
    return 0;
}

/* private: void java::lang::Throwable::writeObject(::java::io::ObjectOutputStream* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Throwable::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Throwable", 19);
    return c;
}

java::lang::Class* java::lang::Throwable::getClass0()
{
    return class_();
}

