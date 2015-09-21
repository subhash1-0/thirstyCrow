// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>

struct default_init_tag;

class java::util::Arrays_NaturalOrder final
    : public virtual ::java::lang::Object
    , public Comparator
{

public:
    typedef ::java::lang::Object super;

private:
    static Arrays_NaturalOrder* INSTANCE_;

protected:
    void ctor();

public:
    int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;

    // Generated

public: /* package */
    Arrays_NaturalOrder();
protected:
    Arrays_NaturalOrder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);

public: /* package */
    static Arrays_NaturalOrder*& INSTANCE();

private:
    virtual ::java::lang::Class* getClass0();
};
