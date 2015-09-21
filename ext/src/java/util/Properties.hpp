// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Hashtable.hpp>

struct default_init_tag;

class java::util::Properties
    : public Hashtable
{

public:
    typedef Hashtable super;

public: /* protected */
    Properties* defaults {  };

private:
    static ::char16_tArray* hexDigit_;
    static constexpr int64_t serialVersionUID { int64_t(4112578634029874840LL) };

protected:
    void ctor();
    void ctor(Properties* arg0);
    /*void enumerate(Hashtable* arg0); (private) */
    /*void enumerateStringProperties(Hashtable* arg0); (private) */

public:
    virtual ::java::lang::String* getProperty(::java::lang::String* arg0);
    virtual ::java::lang::String* getProperty(::java::lang::String* arg0, ::java::lang::String* arg1);
    virtual void list(::java::io::PrintStream* arg0);
    virtual void list(::java::io::PrintWriter* arg0);
    virtual void load(::java::io::Reader* arg0);
    virtual void load(::java::io::InputStream* arg0);
    /*void load0(Properties_LineReader* arg0); (private) */
    /*::java::lang::String* loadConvert(::char16_tArray* arg0, int32_t arg1, int32_t arg2, ::char16_tArray* arg3); (private) */
    virtual void loadFromXML(::java::io::InputStream* arg0);
    virtual Enumeration* propertyNames();
    virtual void save(::java::io::OutputStream* arg0, ::java::lang::String* arg1);
    /*::java::lang::String* saveConvert(::java::lang::String* arg0, bool arg1, bool arg2); (private) */
    virtual ::java::lang::Object* setProperty(::java::lang::String* arg0, ::java::lang::String* arg1);
    virtual void store(::java::io::Writer* arg0, ::java::lang::String* arg1);
    virtual void store(::java::io::OutputStream* arg0, ::java::lang::String* arg1);
    /*void store0(::java::io::BufferedWriter* arg0, ::java::lang::String* arg1, bool arg2); (private) */
    virtual void storeToXML(::java::io::OutputStream* arg0, ::java::lang::String* arg1);
    virtual void storeToXML(::java::io::OutputStream* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2);
    virtual Set* stringPropertyNames();
    /*static char16_t toHex(int32_t arg0); (private) */
    /*static void writeComments(::java::io::BufferedWriter* arg0, ::java::lang::String* arg1); (private) */

    // Generated
    Properties();
    Properties(Properties* arg0);
protected:
    Properties(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::char16_tArray*& hexDigit();
    virtual ::java::lang::Class* getClass0();
};
