// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Collections_UnmodifiableNavigableSet.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableNavigableSet_EmptyNavigableSet
    : public Collections_UnmodifiableNavigableSet
    , public virtual ::java::io::Serializable
{

public:
    typedef Collections_UnmodifiableNavigableSet super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-6291252904449939134LL) };

protected:
    void ctor();
    /*::java::lang::Object* readResolve(); (private) */

    // Generated

public:
    Collections_UnmodifiableNavigableSet_EmptyNavigableSet();
protected:
    Collections_UnmodifiableNavigableSet_EmptyNavigableSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
