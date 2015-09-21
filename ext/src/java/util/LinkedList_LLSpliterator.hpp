// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::LinkedList_LLSpliterator final
    : public virtual ::java::lang::Object
    , public Spliterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t BATCH_UNIT { int32_t(1024) };
    static constexpr int32_t MAX_BATCH { int32_t(33554432) };
    int32_t batch {  };
    LinkedList_Node* current {  };
    int32_t est {  };
    int32_t expectedModCount {  };
    LinkedList* list {  };

protected:
    void ctor(LinkedList* arg0, int32_t arg1, int32_t arg2);

public:
    int32_t characteristics() override;
    int64_t estimateSize() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;

public: /* package */
    int32_t getEst();

public:
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    Spliterator* trySplit() override;

    // Generated

public: /* package */
    LinkedList_LLSpliterator(LinkedList* arg0, int32_t arg1, int32_t arg2);
protected:
    LinkedList_LLSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
