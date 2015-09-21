// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractQueue.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::PriorityQueue
    : public AbstractQueue
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractQueue super;

private:
    static constexpr int32_t DEFAULT_INITIAL_CAPACITY { int32_t(11) };
    static constexpr int32_t MAX_ARRAY_SIZE { int32_t(2147483639) };
    Comparator* comparator_ {  };

public: /* package */
    int32_t modCount {  };
    ::java::lang::ObjectArray* queue {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(-7720805057305804111LL) };
    int32_t size_ {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(Comparator* arg0);
    void ctor(Collection* arg0);
    void ctor(PriorityQueue* arg0);
    void ctor(SortedSet* arg0);
    void ctor(int32_t arg0, Comparator* arg1);

public:
    bool add(::java::lang::Object* arg0) override;
    void clear() override;
    virtual Comparator* comparator();
    bool contains(::java::lang::Object* arg0) override;
    /*void grow(int32_t arg0); (private) */
    /*void heapify(); (private) */
    /*static int32_t hugeCapacity(int32_t arg0); (private) */
    /*int32_t indexOf(::java::lang::Object* arg0); (private) */
    /*void initElementsFromCollection(Collection* arg0); (private) */
    /*void initFromCollection(Collection* arg0); (private) */
    /*void initFromPriorityQueue(PriorityQueue* arg0); (private) */
    Iterator* iterator() override;
    bool offer(::java::lang::Object* arg0) override;
    ::java::lang::Object* peek() override;
    ::java::lang::Object* poll() override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    bool remove(::java::lang::Object* arg0) override;
    /*::java::lang::Object* removeAt(int32_t arg0); (private) */

public: /* package */
    virtual bool removeEq(::java::lang::Object* arg0);
    /*void siftDown(int32_t arg0, ::java::lang::Object* arg1); (private) */
    /*void siftDownComparable(int32_t arg0, ::java::lang::Object* arg1); (private) */
    /*void siftDownUsingComparator(int32_t arg0, ::java::lang::Object* arg1); (private) */
    /*void siftUp(int32_t arg0, ::java::lang::Object* arg1); (private) */
    /*void siftUpComparable(int32_t arg0, ::java::lang::Object* arg1); (private) */
    /*void siftUpUsingComparator(int32_t arg0, ::java::lang::Object* arg1); (private) */

public:
    int32_t size() override;
    Spliterator* spliterator() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    PriorityQueue();
    PriorityQueue(int32_t arg0);
    PriorityQueue(Comparator* arg0);
    PriorityQueue(Collection* arg0);
    PriorityQueue(PriorityQueue* arg0);
    PriorityQueue(SortedSet* arg0);
    PriorityQueue(int32_t arg0, Comparator* arg1);
protected:
    PriorityQueue(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::java::lang::Object* remove();

private:
    virtual ::java::lang::Class* getClass0();
};
