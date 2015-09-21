// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>

struct default_init_tag;

class java::util::AbstractCollection
    : public virtual ::java::lang::Object
    , public virtual Collection
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t MAX_ARRAY_SIZE { int32_t(2147483639) };

protected:
    void ctor();

public:
    bool add(::java::lang::Object* arg0) override;
    bool addAll(Collection* arg0) override;
    void clear() override;
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;
    /*static ::java::lang::ObjectArray* finishToArray_(::java::lang::ObjectArray* arg0, Iterator* arg1); (private) */
    /*static int32_t hugeCapacity(int32_t arg0); (private) */
    bool isEmpty() override;
    /*Iterator* iterator(); (already declared) */
    bool remove(::java::lang::Object* arg0) override;
    bool removeAll(Collection* arg0) override;
    bool retainAll(Collection* arg0) override;
    /*int32_t size(); (already declared) */
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* protected */
    AbstractCollection();
protected:
    AbstractCollection(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();

private:
    virtual ::java::lang::Class* getClass0();
};
