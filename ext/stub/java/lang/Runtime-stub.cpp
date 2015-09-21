// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Runtime.hpp>

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

extern void unimplemented_(const char16_t* name);
java::lang::Runtime::Runtime(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Runtime*& java::lang::Runtime::currentRuntime()
{
    clinit();
    return currentRuntime_;
}
java::lang::Runtime* java::lang::Runtime::currentRuntime_;

/* private: void ::java::lang::Runtime::ctor() */
void java::lang::Runtime::addShutdownHook(Thread* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::addShutdownHook(Thread* arg0)");
}

java::lang::Process* java::lang::Runtime::exec(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Process* java::lang::Runtime::exec(String* arg0)");
    return 0;
}

java::lang::Process* java::lang::Runtime::exec(StringArray* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Process* java::lang::Runtime::exec(StringArray* arg0)");
    return 0;
}

java::lang::Process* java::lang::Runtime::exec(String* arg0, StringArray* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Process* java::lang::Runtime::exec(String* arg0, StringArray* arg1)");
    return 0;
}

java::lang::Process* java::lang::Runtime::exec(StringArray* arg0, StringArray* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Process* java::lang::Runtime::exec(StringArray* arg0, StringArray* arg1)");
    return 0;
}

java::lang::Process* java::lang::Runtime::exec(String* arg0, StringArray* arg1, ::java::io::File* arg2)
{ /* stub */
    unimplemented_(u"java::lang::Process* java::lang::Runtime::exec(String* arg0, StringArray* arg1, ::java::io::File* arg2)");
    return 0;
}

java::lang::Process* java::lang::Runtime::exec(StringArray* arg0, StringArray* arg1, ::java::io::File* arg2)
{ /* stub */
    unimplemented_(u"java::lang::Process* java::lang::Runtime::exec(StringArray* arg0, StringArray* arg1, ::java::io::File* arg2)");
    return 0;
}

void java::lang::Runtime::exit(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::exit(int32_t arg0)");
}

java::io::InputStream* java::lang::Runtime::getLocalizedInputStream(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"java::io::InputStream* java::lang::Runtime::getLocalizedInputStream(::java::io::InputStream* arg0)");
    return 0;
}

java::io::OutputStream* java::lang::Runtime::getLocalizedOutputStream(::java::io::OutputStream* arg0)
{ /* stub */
    unimplemented_(u"java::io::OutputStream* java::lang::Runtime::getLocalizedOutputStream(::java::io::OutputStream* arg0)");
    return 0;
}

java::lang::Runtime* java::lang::Runtime::getRuntime()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Runtime* java::lang::Runtime::getRuntime()");
    return 0;
}

void java::lang::Runtime::halt(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::halt(int32_t arg0)");
}

void java::lang::Runtime::load(String* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::load(String* arg0)");
}

void java::lang::Runtime::load0(Class* arg0, String* arg1)
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::load0(Class* arg0, String* arg1)");
}

void java::lang::Runtime::loadLibrary(String* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::loadLibrary(String* arg0)");
}

void java::lang::Runtime::loadLibrary0(Class* arg0, String* arg1)
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::loadLibrary0(Class* arg0, String* arg1)");
}

bool java::lang::Runtime::removeShutdownHook(Thread* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::Runtime::removeShutdownHook(Thread* arg0)");
    return 0;
}

void java::lang::Runtime::runFinalization()
{ /* stub */
    unimplemented_(u"void java::lang::Runtime::runFinalization()");
}

void java::lang::Runtime::runFinalizersOnExit(bool arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::Runtime::runFinalizersOnExit(bool arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Runtime::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Runtime", 17);
    return c;
}

java::lang::Class* java::lang::Runtime::getClass0()
{
    return class_();
}

