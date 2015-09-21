// Generated from /pastry-2.1/src/rice/p2p/util/XMLParser.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::XMLParser_CharArrayBuffer
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t DEFAULT_CAPACITY { int32_t(32) };

public: /* protected */
    ::char16_tArray* buffer {  };
    int32_t length {  };
protected:
    void ctor(::char16_tArray* chars, int32_t length, int32_t off);

public:
    virtual ::char16_tArray* getBuffer();
    virtual int32_t getLength();
    virtual void append(::char16_tArray* chars, int32_t off, int32_t len);

public: /* protected */
    virtual void expandBuffer();

    // Generated

public:
    XMLParser_CharArrayBuffer(XMLParser *XMLParser_this, ::char16_tArray* chars, int32_t length, int32_t off);
protected:
    XMLParser_CharArrayBuffer(XMLParser *XMLParser_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    XMLParser *XMLParser_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLParser;
};
