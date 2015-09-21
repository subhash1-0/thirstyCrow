// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::Properties_LineReader
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::int8_tArray* inByteBuf {  };
    ::char16_tArray* inCharBuf {  };
    int32_t inLimit {  };
    int32_t inOff {  };
    ::java::io::InputStream* inStream {  };
    ::char16_tArray* lineBuf {  };
    ::java::io::Reader* reader {  };
    Properties* this$0 {  };

protected:
    void ctor(::java::io::InputStream* arg0);
    void ctor(::java::io::Reader* arg0);

public: /* package */
    virtual int32_t readLine();

    // Generated

public:
    Properties_LineReader(Properties *Properties_this, ::java::io::InputStream* arg0);
    Properties_LineReader(Properties *Properties_this, ::java::io::Reader* arg0);
protected:
    Properties_LineReader(Properties *Properties_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    Properties *Properties_this;

private:
    virtual ::java::lang::Class* getClass0();
};
