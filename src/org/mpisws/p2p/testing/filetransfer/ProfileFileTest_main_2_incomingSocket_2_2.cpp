// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_2_incomingSocket_2_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_2.hpp>
#include <rice/environment/time/TimeSource.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::ProfileFileTest_main_2_incomingSocket_2_2(ProfileFileTest_main_2 *ProfileFileTest_main_2_this, ::rice::environment::time::TimeSource* time)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProfileFileTest_main_2_this(ProfileFileTest_main_2_this)
    , time(time)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::init()
{
    startTimes = new ::java::util::HashMap();
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::fileTransferred(::org::mpisws::p2p::filetransfer::FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming)
{
    {
        synchronized synchronized_0(startTimes);
        {
            if(!npc(startTimes)->containsKey(receipt)) {
                npc(startTimes)->put(receipt, ::java::lang::Long::valueOf(npc(time)->currentTimeMillis()));
            }
        }
    }
    if(bytesTransferred == total) {
        ::java::lang::String* s;
        if(incoming) {
            s = u"download"_j;
        } else {
            s = u"upload"_j;
        }
        auto finTime = npc(time)->currentTimeMillis();
        int64_t startTime = (npc(java_cast< ::java::lang::Long* >(npc(startTimes)->get(receipt))))->longValue();
        auto kbps = (1.0 * total) / (1.0 * (finTime - startTime));
        npc(startTimes)->remove(receipt);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Took "_j)->append((finTime - startTime))
            ->append(u" millis to "_j)
            ->append(s)
            ->append(u" "_j)
            ->append(total)
            ->append(u" bytes. "_j)
            ->append(kbps)
            ->append(u" kbps. Started at "_j)
            ->append(startTime)->toString());
    }
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::msgTransferred(::org::mpisws::p2p::filetransfer::BBReceipt* receipt, int32_t bytesTransferred, int32_t total, bool incoming)
{
    if(bytesTransferred == total) {
        ::java::lang::String* s;
        if(incoming) {
            s = u"Downloaded"_j;
        } else {
            s = u"Uploaded"_j;
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(s)->append(u" msg of size "_j)
            ->append(total)->toString());
    }
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::transferCancelled(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming)
{
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::transferFailed(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2::getClass0()
{
    return class_();
}

