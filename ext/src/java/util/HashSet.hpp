// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>
#include <java/util/Set.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::HashSet
    : public AbstractSet
    , public virtual Set
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractSet super;

private:
    static ::java::lang::Object* PRESENT_;
    HashMap* map {  };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-5024744406713321676LL) };

protected:
    void ctor();
    void ctor(Collection* arg0);
    void ctor(int32_t arg0);
    void ctor(int32_t arg0, float arg1);
    void ctor(int32_t arg0, float arg1, bool arg2);

public:
    bool add(::java::lang::Object* arg0) override;
    void clear() override;
    ::java::lang::Object* clone() override;
    bool contains(::java::lang::Object* arg0) override;
    bool isEmpty() override;
    Iterator* iterator() override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    bool remove(::java::lang::Object* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    HashSet();
    HashSet(Collection* arg0);
    HashSet(int32_t arg0);
    HashSet(int32_t arg0, float arg1);

public: /* package */
    HashSet(int32_t arg0, float arg1, bool arg2);
protected:
    HashSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool addAll(Collection* arg0);
    bool containsAll(Collection* arg0);
    bool equals(::java::lang::Object* arg0);
    int32_t hashCode();
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    static ::java::lang::Object*& PRESENT();
    virtual ::java::lang::Class* getClass0();
};
