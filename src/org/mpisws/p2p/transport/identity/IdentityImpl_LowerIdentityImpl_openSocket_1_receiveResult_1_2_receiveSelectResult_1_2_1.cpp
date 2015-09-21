// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1_receiveSelectResult_1_2_1_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentitySerializer.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1(IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2 *IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this(IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , i(i)
    , options(options)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1::init()
{
    responseBuffer = ::java::nio::ByteBuffer::allocate(1);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverSocketToMe)->receiveException(ret, ioe);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(!canRead)
        throw new ::java::io::IOException(u"Can't read!"_j);

    if(canWrite)
        throw new ::java::io::IOException(u"Never asked to write!"_j);

    if(npc(socket)->read(responseBuffer) == -int32_t(1)) {
        npc(socket)->close();
        npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Remote node closed socket while opening.  Try again."_j));
        return;
    }
    if(npc(responseBuffer)->remaining() > 0) {
        npc(socket)->register_(true, false, this);
    } else {
        auto answer = (*npc(responseBuffer)->array())[int32_t(0)];
        if(answer == IdentityImpl::FAILURE) {
            if(npc(IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this->IdentityImpl_LowerIdentityImpl_openSocket_1_this->IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this->IdentityImpl_LowerIdentityImpl_openSocket_1_this->IdentityImpl_LowerIdentityImpl_this->logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
                    ->append(u") answer = FAILURE"_j)->toString());

            auto newDest = java_cast< ::java::lang::Object* >(npc(IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this->IdentityImpl_LowerIdentityImpl_openSocket_1_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->serializer)->deserialize(new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socket, npc(IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this->IdentityImpl_LowerIdentityImpl_openSocket_1_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->localIdentifier)->length), i));
            if(IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_this->IdentityImpl_LowerIdentityImpl_openSocket_1_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->addBinding(newDest, i, options)) {
            } else {
                npc(socket)->close();
                npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i));
            }
            npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i));
        } else {
            npc(ret)->setSubCancellable(new IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1_receiveSelectResult_1_2_1_1(this, ret, socket));
            npc(deliverSocketToMe)->receiveResult(ret, socket);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1::getClass0()
{
    return class_();
}

