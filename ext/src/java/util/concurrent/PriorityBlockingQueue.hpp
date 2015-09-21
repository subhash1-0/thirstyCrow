// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/locks/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <java/util/AbstractQueue.hpp>
#include <java/util/concurrent/BlockingQueue.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::concurrent::PriorityBlockingQueue
    : public ::java::util::AbstractQueue
    , public virtual BlockingQueue
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::util::AbstractQueue super;

private:
    static constexpr int32_t DEFAULT_INITIAL_CAPACITY { int32_t(11) };
    static constexpr int32_t MAX_ARRAY_SIZE { int32_t(2147483639) };
    static ::sun::misc::Unsafe* UNSAFE_;
    std::atomic< int32_t > allocationSpinLock {  };
    static int64_t allocationSpinLockOffset_;
    ::java::util::Comparator* comparator_ {  };
    ::java::util::concurrent::locks::ReentrantLock* lock {  };
    ::java::util::concurrent::locks::Condition* notEmpty {  };
    ::java::util::PriorityQueue* q {  };
    ::java::lang::ObjectArray* queue {  };
    static constexpr int64_t serialVersionUID { int64_t(5595510919245408276LL) };
    int32_t size_ {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(::java::util::Collection* arg0);
    void ctor(int32_t arg0, ::java::util::Comparator* arg1);

public:
    bool add(::java::lang::Object* arg0) override;
    void clear() override;
    virtual ::java::util::Comparator* comparator();
    bool contains(::java::lang::Object* arg0) override;
    /*::java::lang::Object* dequeue(); (private) */
    int32_t drainTo(::java::util::Collection* arg0) override;
    int32_t drainTo(::java::util::Collection* arg0, int32_t arg1) override;
    /*void heapify(); (private) */
    /*int32_t indexOf(::java::lang::Object* arg0); (private) */
    ::java::util::Iterator* iterator() override;
    bool offer(::java::lang::Object* arg0) override;
    bool offer(::java::lang::Object* arg0, int64_t arg1, TimeUnit* arg2) override;
    ::java::lang::Object* peek() override;
    ::java::lang::Object* poll() override;
    ::java::lang::Object* poll(int64_t arg0, TimeUnit* arg1) override;
    void put(::java::lang::Object* arg0) override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    int32_t remainingCapacity() override;
    bool remove(::java::lang::Object* arg0) override;
    /*void removeAt(int32_t arg0); (private) */

public: /* package */
    virtual void removeEQ(::java::lang::Object* arg0);
    /*static void siftDownComparable(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2, int32_t arg3); (private) */
    /*static void siftDownUsingComparator(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2, int32_t arg3, ::java::util::Comparator* arg4); (private) */
    /*static void siftUpComparable(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2); (private) */
    /*static void siftUpUsingComparator(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2, ::java::util::Comparator* arg3); (private) */

public:
    int32_t size() override;
    ::java::util::Spliterator* spliterator() override;
    ::java::lang::Object* take() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;
    ::java::lang::String* toString() override;
    /*void tryGrow(::java::lang::ObjectArray* arg0, int32_t arg1); (private) */
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    PriorityBlockingQueue();
    PriorityBlockingQueue(int32_t arg0);
    PriorityBlockingQueue(::java::util::Collection* arg0);
    PriorityBlockingQueue(int32_t arg0, ::java::util::Comparator* arg1);
protected:
    PriorityBlockingQueue(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool addAll(::java::util::Collection* arg0);
    virtual bool containsAll(::java::util::Collection* arg0);
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual bool isEmpty();
    virtual bool removeAll(::java::util::Collection* arg0);
    virtual bool retainAll(::java::util::Collection* arg0);
    virtual ::java::lang::Object* element();
    virtual ::java::lang::Object* remove();

private:
    static ::sun::misc::Unsafe*& UNSAFE();
    static int64_t& allocationSpinLockOffset();
    virtual ::java::lang::Class* getClass0();
};
