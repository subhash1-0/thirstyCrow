// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Enumeration.hpp>

struct default_init_tag;

class java::util::StringTokenizer
    : public virtual ::java::lang::Object
    , public virtual Enumeration
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t currentPosition {  };
    ::int32_tArray* delimiterCodePoints {  };
    ::java::lang::String* delimiters {  };
    bool delimsChanged {  };
    bool hasSurrogates {  };
    int32_t maxDelimCodePoint {  };
    int32_t maxPosition {  };
    int32_t newPosition {  };
    bool retDelims {  };
    ::java::lang::String* str {  };

protected:
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1);
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2);

public:
    virtual int32_t countTokens();
    bool hasMoreElements() override;
    virtual bool hasMoreTokens();
    /*bool isDelimiter(int32_t arg0); (private) */
    ::java::lang::Object* nextElement() override;
    virtual ::java::lang::String* nextToken();
    virtual ::java::lang::String* nextToken(::java::lang::String* arg0);
    /*int32_t scanToken(int32_t arg0); (private) */
    /*void setMaxDelimCodePoint(); (private) */
    /*int32_t skipDelimiters(int32_t arg0); (private) */

    // Generated
    StringTokenizer(::java::lang::String* arg0);
    StringTokenizer(::java::lang::String* arg0, ::java::lang::String* arg1);
    StringTokenizer(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2);
protected:
    StringTokenizer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
