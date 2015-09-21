// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::System final
    : public Object
{

public:
    typedef Object super;

private:
    static std::atomic< ::java::io::Console* > cons_;
    static ::java::io::PrintStream* err_;
    static ::java::io::InputStream* in_;
    static String* lineSeparator__;
    static ::java::io::PrintStream* out_;
    static ::java::util::Properties* props_;
    static std::atomic< SecurityManager* > security_;

    /*void ctor(); (private) */

public:
    static void arraycopy(Object* arg0, int32_t arg1, Object* arg2, int32_t arg3, int32_t arg4);
    /*static void checkIO(); (private) */
    /*static void checkKey(String* arg0); (private) */
    static String* clearProperty(String* arg0);
    static ::java::io::Console* console();
    static int64_t currentTimeMillis();
    static void exit(int32_t arg0);
    static void gc();
    static ::java::util::Properties* getProperties();
    static String* getProperty(String* arg0);
    static String* getProperty(String* arg0, String* arg1);
    static SecurityManager* getSecurityManager();
    static ::java::util::Map* getenv();
    static String* getenv(String* arg0);
    static int32_t identityHashCode(Object* arg0);
    static ::java::nio::channels::Channel* inheritedChannel();
    /*static ::java::util::Properties* initProperties(::java::util::Properties* arg0); (private) */
    /*static void initializeSystemClass(); (private) */
    static String* lineSeparator();
    static void load(String* arg0);
    static void loadLibrary(String* arg0);
    static String* mapLibraryName(String* arg0);
    static int64_t nanoTime();
    /*static ::java::io::PrintStream* newPrintStream(::java::io::FileOutputStream* arg0, String* arg1); (private) */
    /*static void registerNatives(); (private) */
    static void runFinalization();
    static void runFinalizersOnExit(bool arg0);
    static void setErr(::java::io::PrintStream* arg0);
    /*static void setErr0(::java::io::PrintStream* arg0); (private) */
    static void setIn(::java::io::InputStream* arg0);
    /*static void setIn0(::java::io::InputStream* arg0); (private) */
    /*static void setJavaLangAccess(); (private) */
    static void setOut(::java::io::PrintStream* arg0);
    /*static void setOut0(::java::io::PrintStream* arg0); (private) */
    static void setProperties(::java::util::Properties* arg0);
    static String* setProperty(String* arg0, String* arg1);
    static void setSecurityManager(SecurityManager* arg0);
    /*static void setSecurityManager0(SecurityManager* arg0); (private) */

    // Generated
    System();
protected:
    System(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static std::atomic< ::java::io::Console* >& cons();

public:
    static ::java::io::PrintStream*& err();
    static ::java::io::InputStream*& in();

private:
    static String*& lineSeparator_();

public:
    static ::java::io::PrintStream*& out();

private:
    static ::java::util::Properties*& props();
    static std::atomic< SecurityManager* >& security();
    virtual ::java::lang::Class* getClass0();
};
