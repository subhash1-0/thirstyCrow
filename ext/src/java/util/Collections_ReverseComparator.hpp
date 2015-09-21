// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_ReverseComparator
    : public virtual ::java::lang::Object
    , public virtual Comparator
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static Collections_ReverseComparator* REVERSE_ORDER_;
    static constexpr int64_t serialVersionUID { int64_t(7207038068494060240LL) };

    /*void ctor(); (private) */

public:
    virtual int32_t compare(::java::lang::Comparable* arg0, ::java::lang::Comparable* arg1);
    /*::java::lang::Object* readResolve(); (private) */
    Comparator* reversed() override;

    // Generated
    Collections_ReverseComparator();
protected:
    Collections_ReverseComparator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;

public: /* package */
    static Collections_ReverseComparator*& REVERSE_ORDER();

private:
    virtual ::java::lang::Class* getClass0();
};
