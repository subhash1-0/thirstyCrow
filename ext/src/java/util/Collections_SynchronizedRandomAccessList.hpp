// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Collections_SynchronizedList.hpp>
#include <java/util/RandomAccess.hpp>

struct default_init_tag;

class java::util::Collections_SynchronizedRandomAccessList
    : public Collections_SynchronizedList
    , public virtual RandomAccess
{

public:
    typedef Collections_SynchronizedList super;

private:
    static constexpr int64_t serialVersionUID { int64_t(1530674583602358482LL) };

protected:
    void ctor(List* arg0);
    void ctor(List* arg0, ::java::lang::Object* arg1);

public:
    List* subList(int32_t arg0, int32_t arg1) override;
    /*::java::lang::Object* writeReplace(); (private) */

    // Generated

public: /* package */
    Collections_SynchronizedRandomAccessList(List* arg0);
    Collections_SynchronizedRandomAccessList(List* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SynchronizedRandomAccessList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
