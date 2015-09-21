// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::lang::String_CaseInsensitiveComparator
    : public virtual Object
    , public virtual ::java::util::Comparator
    , public virtual ::java::io::Serializable
{

public:
    typedef Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(8575799808933029326LL) };

    /*void ctor(); (private) */

public:
    virtual int32_t compare(String* arg0, String* arg1);
    /*Object* readResolve(); (private) */

    // Generated
    String_CaseInsensitiveComparator();
protected:
    String_CaseInsensitiveComparator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(Object* arg0);
    virtual int32_t compare(Object* arg0, Object* arg1) override;

private:
    virtual ::java::lang::Class* getClass0();
};
