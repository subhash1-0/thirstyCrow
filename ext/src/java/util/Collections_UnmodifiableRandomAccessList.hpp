// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Collections_UnmodifiableList.hpp>
#include <java/util/RandomAccess.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableRandomAccessList
    : public Collections_UnmodifiableList
    , public virtual RandomAccess
{

public:
    typedef Collections_UnmodifiableList super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-2542308836966382001LL) };

protected:
    void ctor(List* arg0);

public:
    List* subList(int32_t arg0, int32_t arg1) override;
    /*::java::lang::Object* writeReplace(); (private) */

    // Generated

public: /* package */
    Collections_UnmodifiableRandomAccessList(List* arg0);
protected:
    Collections_UnmodifiableRandomAccessList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
