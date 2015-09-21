// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransfer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_2_incomingSocket_2_1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_2_incomingSocket_2_2.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/transport/SocketAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2::ProfileFileTest_main_2(::rice::environment::logging::Logger* logger, ::rice::environment::Environment* env, ::rice::environment::time::TimeSource* time)
    : super(*static_cast< ::default_init_tag* >(0))
    , logger(logger)
    , env(env)
    , time(time)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2::messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
        ->append(u")"_j)->toString());
    ::rice::p2p::commonapi::appsocket::AppSocket* const sock = new ::rice::pastry::transport::SocketAdapter(s, env);
    ::org::mpisws::p2p::filetransfer::FileTransfer* ft = new ::org::mpisws::p2p::filetransfer::FileTransferImpl(sock, new ProfileFileTest_main_2_incomingSocket_2_1(this, logger), env);
    npc(ft)->addListener(new ProfileFileTest_main_2_incomingSocket_2_2(this, time));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2::getClass0()
{
    return class_();
}

