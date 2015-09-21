// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Collections_CheckedList.hpp>
#include <java/util/RandomAccess.hpp>

struct default_init_tag;

class java::util::Collections_CheckedRandomAccessList
    : public Collections_CheckedList
    , public virtual RandomAccess
{

public:
    typedef Collections_CheckedList super;

private:
    static constexpr int64_t serialVersionUID { int64_t(1638200125423088369LL) };

protected:
    void ctor(List* arg0, ::java::lang::Class* arg1);

public:
    List* subList(int32_t arg0, int32_t arg1) override;

    // Generated

public: /* package */
    Collections_CheckedRandomAccessList(List* arg0, ::java::lang::Class* arg1);
protected:
    Collections_CheckedRandomAccessList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
