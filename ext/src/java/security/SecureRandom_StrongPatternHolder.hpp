// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/regex/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::SecureRandom_StrongPatternHolder final
    : public ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::util::regex::Pattern* pattern_;

    /*void ctor(); (private) */

    // Generated

public:
    SecureRandom_StrongPatternHolder();
protected:
    SecureRandom_StrongPatternHolder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::util::regex::Pattern*& pattern();
    virtual ::java::lang::Class* getClass0();
};
