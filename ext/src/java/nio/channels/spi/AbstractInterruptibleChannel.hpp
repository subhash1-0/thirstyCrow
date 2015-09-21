// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/fwd-pastry-2.1.hpp>
#include <sun/nio/ch/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/channels/Channel.hpp>
#include <java/nio/channels/InterruptibleChannel.hpp>

struct default_init_tag;

class java::nio::channels::spi::AbstractInterruptibleChannel
    : public virtual ::java::lang::Object
    , public virtual ::java::nio::channels::Channel
    , public virtual ::java::nio::channels::InterruptibleChannel
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::Object* closeLock {  };
    std::atomic< ::java::lang::Thread* > interrupted {  };
    ::sun::nio::ch::Interruptible* interruptor {  };
    std::atomic< bool > open {  };

protected:
    void ctor();

public: /* protected */
    void begin();

public: /* package */
    static void blockedOn(::sun::nio::ch::Interruptible* arg0);

public:
    void close() override;

public: /* protected */
    void end(bool arg0);
    virtual void implCloseChannel() = 0;

public:
    bool isOpen() override;

    // Generated

public: /* protected */
    AbstractInterruptibleChannel();
protected:
    AbstractInterruptibleChannel(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
