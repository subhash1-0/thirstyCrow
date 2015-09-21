// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Enumeration.hpp>

struct default_init_tag;

class java::util::Collections_EmptyEnumeration
    : public virtual ::java::lang::Object
    , public virtual Enumeration
{

public:
    typedef ::java::lang::Object super;

private:
    static Collections_EmptyEnumeration* EMPTY_ENUMERATION_;

    /*void ctor(); (private) */

public:
    bool hasMoreElements() override;
    ::java::lang::Object* nextElement() override;

    // Generated
    Collections_EmptyEnumeration();
protected:
    Collections_EmptyEnumeration(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static Collections_EmptyEnumeration*& EMPTY_ENUMERATION();

private:
    virtual ::java::lang::Class* getClass0();
};
