// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractList.hpp>
#include <java/util/List.hpp>
#include <java/util/RandomAccess.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::ArrayList
    : public AbstractList
    , public virtual List
    , public virtual RandomAccess
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractList super;

private:
    static ::java::lang::ObjectArray* DEFAULTCAPACITY_EMPTY_ELEMENTDATA_;
    static constexpr int32_t DEFAULT_CAPACITY { int32_t(10) };
    static ::java::lang::ObjectArray* EMPTY_ELEMENTDATA_;
    static constexpr int32_t MAX_ARRAY_SIZE { int32_t(2147483639) };

public: /* package */
    ::java::lang::ObjectArray* elementData_ {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(8683452581122892189LL) };
    int32_t size_ {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(Collection* arg0);

public:
    bool add(::java::lang::Object* arg0) override;
    void add(int32_t arg0, ::java::lang::Object* arg1) override;
    bool addAll(Collection* arg0) override;
    bool addAll(int32_t arg0, Collection* arg1) override;
    /*bool batchRemove(Collection* arg0, bool arg1); (private) */
    void clear() override;
    ::java::lang::Object* clone() override;
    bool contains(::java::lang::Object* arg0) override;

public: /* package */
    virtual ::java::lang::Object* elementData(int32_t arg0);

public:
    virtual void ensureCapacity(int32_t arg0);
    /*void ensureCapacityInternal(int32_t arg0); (private) */
    /*void ensureExplicitCapacity(int32_t arg0); (private) */
    /*void fastRemove(int32_t arg0); (private) */
    void forEach(::java::util::function::Consumer* arg0) override;
    ::java::lang::Object* get(int32_t arg0) override;
    /*void grow(int32_t arg0); (private) */
    /*static int32_t hugeCapacity(int32_t arg0); (private) */
    int32_t indexOf(::java::lang::Object* arg0) override;
    bool isEmpty() override;
    Iterator* iterator() override;
    int32_t lastIndexOf(::java::lang::Object* arg0) override;
    ListIterator* listIterator() override;
    ListIterator* listIterator(int32_t arg0) override;
    /*::java::lang::String* outOfBoundsMsg(int32_t arg0); (private) */
    /*void rangeCheck(int32_t arg0); (private) */
    /*void rangeCheckForAdd(int32_t arg0); (private) */
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    ::java::lang::Object* remove(int32_t arg0) override;
    bool remove(::java::lang::Object* arg0) override;
    bool removeAll(Collection* arg0) override;
    bool removeIf(::java::util::function::Predicate* arg0) override;

public: /* protected */
    void removeRange(int32_t arg0, int32_t arg1) override;

public:
    void replaceAll(::java::util::function::UnaryOperator* arg0) override;
    bool retainAll(Collection* arg0) override;
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    int32_t size() override;
    void sort(Comparator* arg0) override;
    Spliterator* spliterator() override;
    List* subList(int32_t arg0, int32_t arg1) override;

public: /* package */
    static void subListRangeCheck(int32_t arg0, int32_t arg1, int32_t arg2);

public:
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;
    virtual void trimToSize();
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    ArrayList();
    ArrayList(int32_t arg0);
    ArrayList(Collection* arg0);
protected:
    ArrayList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool containsAll(Collection* arg0);
    bool equals(::java::lang::Object* arg0);
    int32_t hashCode();

private:
    static ::java::lang::ObjectArray*& DEFAULTCAPACITY_EMPTY_ELEMENTDATA();
    static ::java::lang::ObjectArray*& EMPTY_ELEMENTDATA();
    virtual ::java::lang::Class* getClass0();
};
