// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.hpp>
#include <java/nio/channels/Channel.hpp>

struct default_init_tag;

class java::nio::channels::SelectableChannel
    : public ::java::nio::channels::spi::AbstractInterruptibleChannel
    , public virtual Channel
{

public:
    typedef ::java::nio::channels::spi::AbstractInterruptibleChannel super;

protected:
    void ctor();

public:
    virtual ::java::lang::Object* blockingLock() = 0;
    virtual SelectableChannel* configureBlocking(bool arg0) = 0;
    virtual bool isBlocking() = 0;
    virtual bool isRegistered() = 0;
    virtual SelectionKey* keyFor(Selector* arg0) = 0;
    virtual ::java::nio::channels::spi::SelectorProvider* provider() = 0;
    SelectionKey* register_(Selector* arg0, int32_t arg1);
    virtual SelectionKey* register_(Selector* arg0, int32_t arg1, ::java::lang::Object* arg2) = 0;
    virtual int32_t validOps() = 0;

    // Generated

public: /* protected */
    SelectableChannel();
protected:
    SelectableChannel(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void close();
    virtual bool isOpen();

private:
    virtual ::java::lang::Class* getClass0();
};
