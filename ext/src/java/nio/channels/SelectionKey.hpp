// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/atomic/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::nio::channels::SelectionKey
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t OP_ACCEPT { int32_t(16) };
    static constexpr int32_t OP_CONNECT { int32_t(8) };
    static constexpr int32_t OP_READ { int32_t(1) };
    static constexpr int32_t OP_WRITE { int32_t(4) };

private:
    std::atomic< ::java::lang::Object* > attachment_ {  };
    static ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater* attachmentUpdater_;

protected:
    void ctor();

public:
    ::java::lang::Object* attach(::java::lang::Object* arg0);
    ::java::lang::Object* attachment();
    virtual void cancel() = 0;
    virtual SelectableChannel* channel() = 0;
    virtual int32_t interestOps() = 0;
    virtual SelectionKey* interestOps(int32_t arg0) = 0;
    bool isAcceptable();
    bool isConnectable();
    bool isReadable();
    virtual bool isValid() = 0;
    bool isWritable();
    virtual int32_t readyOps() = 0;
    virtual Selector* selector() = 0;

    // Generated

public: /* protected */
    SelectionKey();
protected:
    SelectionKey(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater*& attachmentUpdater();
    virtual ::java::lang::Class* getClass0();
};
