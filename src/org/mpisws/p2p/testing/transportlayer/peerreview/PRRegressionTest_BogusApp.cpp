// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Random.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp_scheduleMessageToBeSent_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp_sendMessage_2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleSerializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/WitnessListener.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>
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

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::PRRegressionTest_BogusApp(PRRegressionTest *PRRegressionTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_this(PRRegressionTest_this)
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::PRRegressionTest_BogusApp(PRRegressionTest *PRRegressionTest_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env) 
    : PRRegressionTest_BogusApp(PRRegressionTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(player,tl,env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::init()
{
    nextSendTime = int32_t(0);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::ctor(PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->player = player;
    this->tl = tl;
    this->env = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(PRRegressionTest_BogusApp::class_(), nullptr);
    npc(logger)->log(::java::lang::StringBuilder().append(u"new bogus app "_j)->append(static_cast< ::java::lang::Object* >(player))->toString());
    dest = npc(player)->destHandle;
    npc(tl)->setCallback(this);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::init_()
{
    rand = new ::java::util::Random();
    if(npc(npc(npc(player)->localHandle)->id)->id == 1) {
        scheduleMessageToBeSent(npc(npc(env)->getTimeSource())->currentTimeMillis() + int32_t(1000), true);
    }
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::scheduleMessageToBeSent()
{
    scheduleMessageToBeSent(npc(npc(env)->getTimeSource())->currentTimeMillis() + npc(rand)->nextInt(1999) + int32_t(1), true);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::scheduleMessageToBeSent(int64_t time, bool reschedule)
{
    nextSendTime = time;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"scheduling message to be sent at:"_j)->append(time)->toString());

    npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new PRRegressionTest_BogusApp_scheduleMessageToBeSent_1(this, reschedule)), nextSendTime - npc(npc(env)->getTimeSource())->currentTimeMillis());
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::sendMessage()
{
    auto msg = generateMessage();
    npc(logger)->log(::java::lang::StringBuilder().append(u"sending message "_j)->append(npc(msg)->length)
        ->append(u" "_j)
        ->append(::rice::p2p::util::MathUtils::toBase64(msg))->toString());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sending message "_j)->append(npc(msg)->length)
            ->append(u" "_j)
            ->append(::rice::p2p::util::MathUtils::toBase64(msg))->toString());

    try {
        npc(tl)->sendMessage(dest, ::java::nio::ByteBuffer::wrap(msg), new PRRegressionTest_BogusApp_sendMessage_2(this), nullptr);
    } catch (::java::lang::NullPointerException* npe) {
        npc(logger)->log(::java::lang::StringBuilder().append(u"tl:"_j)->append(static_cast< ::java::lang::Object* >(tl))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(dest))->toString());
        throw npe;
    }
}

int8_tArray* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::generateMessage()
{
    auto msg = new ::int8_tArray(npc(rand)->nextInt(31) + int32_t(1));
    npc(rand)->nextBytes(msg);
    return msg;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::storeCheckpoint(::rice::p2p::commonapi::rawserialization::OutputBuffer* buffer) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"storeCheckpoint "_j)->append(nextSendTime)->toString());

    npc(buffer)->writeInt(31173);
    npc(buffer)->writeLong(nextSendTime);
    npc(buffer)->writeBoolean(dest != nullptr);
    if(dest != nullptr)
        npc(dest)->serialize(buffer);

    auto baos = new ::java::io::ByteArrayOutputStream();
    (new ::java::io::ObjectOutputStream(baos))->writeObject(static_cast< ::java::lang::Object* >(rand));
    auto bytes = npc(baos)->toByteArray_();
    npc(buffer)->writeInt(npc(bytes)->length);
    npc(buffer)->write(bytes, 0, npc(bytes)->length);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"storeCheckpoint:"_j)->append(::java::util::Arrays::toString(npc((java_cast< ::rice::p2p::util::rawserialization::SimpleOutputBuffer* >(buffer)))->getBytes()))->toString());

}

bool org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::loadCheckpoint(::rice::p2p::commonapi::rawserialization::InputBuffer* buffer) /* throws(IOException) */
{
    if(npc(buffer)->readInt() != 31173)
        throw new ::java::lang::RuntimeException(u"invalid checkpoint"_j);

    nextSendTime = npc(buffer)->readLong();
    if(npc(buffer)->readBoolean()) {
        dest = (new PRRegressionTest_HandleSerializer())->deserialize(buffer);
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"loadCheckpoint "_j)->append(nextSendTime)->toString());

    auto bytes = new ::int8_tArray(npc(buffer)->readInt());
    npc(buffer)->read(bytes);
    auto bais = new ::java::io::ByteArrayInputStream(bytes);
    try {
        rand = java_cast< ::java::util::Random* >((new ::java::io::ObjectInputStream(bais))->readObject());
    } catch (::java::lang::ClassNotFoundException* cnfe) {
        auto ioe = new ::java::io::IOException(u"Error reading random number from checkpoint"_j);
        npc(ioe)->initCause(cnfe);
        throw ioe;
    }
    if(nextSendTime > 0) {
        scheduleMessageToBeSent(nextSendTime, true);
    }
    return true;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::destroy()
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::notifyCertificateAvailable(PRRegressionTest_IdImpl* id)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::notifyCertificateAvailable(::java::lang::Object* id)
{ 
    notifyCertificateAvailable(dynamic_cast< PRRegressionTest_IdImpl* >(id));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::receive(PRRegressionTest_HandleImpl* source, bool datagram, ::java::nio::ByteBuffer* msg)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::sendComplete(int64_t id)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::messageReceived(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Message received: "_j)->append(::rice::p2p::util::MathUtils::toBase64(npc(m)->array()))->toString());

}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< PRRegressionTest_HandleImpl* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::getWitnesses(PRRegressionTest_IdImpl* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback)
{
    npc(callback)->notifyWitnessSet(subject, ::java::util::Collections::singletonList(npc(PRRegressionTest_this->carol)->localHandle));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::getWitnesses(::java::lang::Object* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback)
{ 
    getWitnesses(dynamic_cast< PRRegressionTest_IdImpl* >(subject), dynamic_cast< ::org::mpisws::p2p::transport::peerreview::WitnessListener* >(callback));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyStatusChange("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u","_j)
            ->append(::org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getStatusString(newStatus))
            ->append(u")"_j)->toString());

    if(newStatus != STATUS_TRUSTED) {
        npc(logger)->log(::java::lang::StringBuilder().append(u"Failure, Node not trusted: "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" at "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(player)->localHandle))->toString());
        ::java::lang::System::exit(1);
    }
    PRRegressionTest_this->addStatusNotification(npc(this->player)->localHandle, id, newStatus);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< PRRegressionTest_IdImpl* >(id), newStatus);
}

java::util::Collection* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::getMyWitnessedNodes()
{
    return npc(player)->witnessed;
}

org::mpisws::p2p::transport::peerreview::PeerReviewCallback* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::getReplayInstance(::org::mpisws::p2p::transport::peerreview::replay::Verifier* v)
{
    auto ret = new PRRegressionTest_BogusApp(PRRegressionTest_this, java_cast< PRRegressionTest_Player* >(npc(PRRegressionTest_this->playerTable)->get(java_cast< PRRegressionTest_HandleImpl* >(npc(v)->getLocalIdentifier()))), v, npc(v)->getEnvironment());
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.BogusApp", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp::getClass0()
{
    return class_();
}

