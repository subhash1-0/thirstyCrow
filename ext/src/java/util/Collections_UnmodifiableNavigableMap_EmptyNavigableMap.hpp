// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Collections_UnmodifiableNavigableMap.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableNavigableMap_EmptyNavigableMap
    : public Collections_UnmodifiableNavigableMap
    , public virtual ::java::io::Serializable
{

public:
    typedef Collections_UnmodifiableNavigableMap super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-2239321462712562324LL) };

protected:
    void ctor();

public:
    NavigableSet* navigableKeySet() override;
    /*::java::lang::Object* readResolve(); (private) */

    // Generated

public: /* package */
    Collections_UnmodifiableNavigableMap_EmptyNavigableMap();
protected:
    Collections_UnmodifiableNavigableMap_EmptyNavigableMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
