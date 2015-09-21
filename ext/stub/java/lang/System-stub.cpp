// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/System.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::System::System(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

std::atomic< java::io::Console* >& java::lang::System::cons()
{
    clinit();
    return cons_;
}
std::atomic< java::io::Console* > java::lang::System::cons_;
java::io::PrintStream*& java::lang::System::err()
{
    clinit();
    return err_;
}
java::io::PrintStream* java::lang::System::err_;
java::io::InputStream*& java::lang::System::in()
{
    clinit();
    return in_;
}
java::io::InputStream* java::lang::System::in_;
java::lang::String*& java::lang::System::lineSeparator_()
{
    clinit();
    return lineSeparator__;
}
java::lang::String* java::lang::System::lineSeparator__;
java::io::PrintStream*& java::lang::System::out()
{
    clinit();
    return out_;
}
java::io::PrintStream* java::lang::System::out_;
java::util::Properties*& java::lang::System::props()
{
    clinit();
    return props_;
}
java::util::Properties* java::lang::System::props_;
std::atomic< java::lang::SecurityManager* >& java::lang::System::security()
{
    clinit();
    return security_;
}
std::atomic< java::lang::SecurityManager* > java::lang::System::security_;

/* private: void ::java::lang::System::ctor() */
/* private: void java::lang::System::checkIO() */
/* private: void java::lang::System::checkKey(String* arg0) */
java::lang::String* java::lang::System::clearProperty(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::System::clearProperty(String* arg0)");
    return 0;
}

java::io::Console* java::lang::System::console()
{ /* stub */
    clinit();
    unimplemented_(u"java::io::Console* java::lang::System::console()");
    return 0;
}

void java::lang::System::exit(int32_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::exit(int32_t arg0)");
}

void java::lang::System::gc()
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::gc()");
}

java::util::Properties* java::lang::System::getProperties()
{ /* stub */
    clinit();
    unimplemented_(u"java::util::Properties* java::lang::System::getProperties()");
    return 0;
}

java::lang::String* java::lang::System::getProperty(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::System::getProperty(String* arg0)");
    return 0;
}

java::lang::String* java::lang::System::getProperty(String* arg0, String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::System::getProperty(String* arg0, String* arg1)");
    return 0;
}

java::lang::SecurityManager* java::lang::System::getSecurityManager()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::SecurityManager* java::lang::System::getSecurityManager()");
    return 0;
}

java::util::Map* java::lang::System::getenv()
{ /* stub */
    clinit();
    unimplemented_(u"java::util::Map* java::lang::System::getenv()");
    return 0;
}

java::lang::String* java::lang::System::getenv(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::System::getenv(String* arg0)");
    return 0;
}

java::nio::channels::Channel* java::lang::System::inheritedChannel()
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::channels::Channel* java::lang::System::inheritedChannel()");
    return 0;
}

/* private: void java::lang::System::initializeSystemClass() */
java::lang::String* java::lang::System::lineSeparator()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::System::lineSeparator()");
    return 0;
}

void java::lang::System::load(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::load(String* arg0)");
}

void java::lang::System::loadLibrary(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::loadLibrary(String* arg0)");
}

/* private: java::io::PrintStream* java::lang::System::newPrintStream(::java::io::FileOutputStream* arg0, String* arg1) */
void java::lang::System::runFinalization()
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::runFinalization()");
}

void java::lang::System::runFinalizersOnExit(bool arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::runFinalizersOnExit(bool arg0)");
}

void java::lang::System::setErr(::java::io::PrintStream* arg0)
{ /* stub */
    clinit();
    System::err() = arg0; /* setter */
}

void java::lang::System::setIn(::java::io::InputStream* arg0)
{ /* stub */
    clinit();
    System::in() = arg0; /* setter */
}

/* private: void java::lang::System::setJavaLangAccess() */
void java::lang::System::setOut(::java::io::PrintStream* arg0)
{ /* stub */
    clinit();
    System::out() = arg0; /* setter */
}

void java::lang::System::setProperties(::java::util::Properties* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::setProperties(::java::util::Properties* arg0)");
}

java::lang::String* java::lang::System::setProperty(String* arg0, String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::System::setProperty(String* arg0, String* arg1)");
    return 0;
}

void java::lang::System::setSecurityManager(SecurityManager* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::System::setSecurityManager(SecurityManager* arg0)");
}

/* private: void java::lang::System::setSecurityManager0(SecurityManager* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::System::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.System", 16);
    return c;
}

java::lang::Class* java::lang::System::getClass0()
{
    return class_();
}

