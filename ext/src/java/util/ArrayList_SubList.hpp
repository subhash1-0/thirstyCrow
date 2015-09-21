// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractList.hpp>
#include <java/util/RandomAccess.hpp>

struct default_init_tag;

class java::util::ArrayList_SubList
    : public AbstractList
    , public virtual RandomAccess
{

public:
    typedef AbstractList super;

private:
    int32_t offset {  };
    AbstractList* parent {  };
    int32_t parentOffset {  };

public: /* package */
    int32_t size_ {  };
    ArrayList* this$0 {  };

protected:
    void ctor(AbstractList* arg0, int32_t arg1, int32_t arg2, int32_t arg3);

public:
    void add(int32_t arg0, ::java::lang::Object* arg1) override;
    bool addAll(Collection* arg0) override;
    bool addAll(int32_t arg0, Collection* arg1) override;
    /*void checkForComodification(); (private) */
    ::java::lang::Object* get(int32_t arg0) override;
    Iterator* iterator() override;
    ListIterator* listIterator(int32_t arg0) override;
    /*::java::lang::String* outOfBoundsMsg(int32_t arg0); (private) */
    /*void rangeCheck(int32_t arg0); (private) */
    /*void rangeCheckForAdd(int32_t arg0); (private) */
    ::java::lang::Object* remove(int32_t arg0) override;

public: /* protected */
    void removeRange(int32_t arg0, int32_t arg1) override;

public:
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    int32_t size() override;
    Spliterator* spliterator() override;
    List* subList(int32_t arg0, int32_t arg1) override;

    // Generated

public: /* package */
    ArrayList_SubList(ArrayList *ArrayList_this, AbstractList* arg0, int32_t arg1, int32_t arg2, int32_t arg3);
protected:
    ArrayList_SubList(ArrayList *ArrayList_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool add(::java::lang::Object* arg0);
    ListIterator* listIterator();
    bool remove(::java::lang::Object* arg0);
    ArrayList *ArrayList_this;

private:
    virtual ::java::lang::Class* getClass0();
};
