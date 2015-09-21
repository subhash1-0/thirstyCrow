// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/fwd-pastry-2.1.hpp>
#include <java/nio/channels/SelectableChannel.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace nio
    {
        namespace channels
        {
typedef ::SubArray< ::java::nio::channels::SelectionKey, ::java::lang::ObjectArray > SelectionKeyArray;
        } // channels
    } // nio
} // java

struct default_init_tag;

class java::nio::channels::spi::AbstractSelectableChannel
    : public ::java::nio::channels::SelectableChannel
{

public:
    typedef ::java::nio::channels::SelectableChannel super;

private:
    static bool $assertionsDisabled_;

public: /* package */
    bool blocking {  };

private:
    int32_t keyCount {  };
    ::java::lang::Object* keyLock {  };
    ::java::nio::channels::SelectionKeyArray* keys {  };
    SelectorProvider* provider_ {  };
    ::java::lang::Object* regLock {  };

protected:
    void ctor(SelectorProvider* arg0);
    /*void addKey(::java::nio::channels::SelectionKey* arg0); (private) */

public:
    ::java::lang::Object* blockingLock() override;
    ::java::nio::channels::SelectableChannel* configureBlocking(bool arg0) override;
    /*::java::nio::channels::SelectionKey* findKey(::java::nio::channels::Selector* arg0); (private) */
    /*bool haveValidKeys(); (private) */

public: /* protected */
    void implCloseChannel() override;
    virtual void implCloseSelectableChannel() = 0;
    virtual void implConfigureBlocking(bool arg0) = 0;

public:
    bool isBlocking() override;
    bool isRegistered() override;
    ::java::nio::channels::SelectionKey* keyFor(::java::nio::channels::Selector* arg0) override;
    SelectorProvider* provider() override;
    ::java::nio::channels::SelectionKey* register_(::java::nio::channels::Selector* arg0, int32_t arg1, ::java::lang::Object* arg2) override;

public: /* package */
    virtual void removeKey(::java::nio::channels::SelectionKey* arg0);

    // Generated

public: /* protected */
    AbstractSelectableChannel(SelectorProvider* arg0);
protected:
    AbstractSelectableChannel(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::java::nio::channels::SelectionKey* register_(::java::nio::channels::Selector* arg0, int32_t arg1);

public: /* package */
    static bool& $assertionsDisabled();

private:
    virtual ::java::lang::Class* getClass0();
};
