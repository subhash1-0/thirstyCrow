// Forward declarations for org.mpisws.p2p.transport.priority
#pragma once


namespace org
{
    namespace mpisws
    {
        namespace p2p
        {
            namespace transport
            {
                namespace priority
                {
                    struct MessageInfo;
                    class MessageInfoImpl;
                    struct PrimarySocketListener;
                    struct PriorityTransportLayer;
                    class PriorityTransportLayerImpl;
                    class PriorityTransportLayerImpl_EntityManager;
                    class PriorityTransportLayerImpl_EntityManager_BufferReader;
                    class PriorityTransportLayerImpl_EntityManager_MessageWrapper;
                    class PriorityTransportLayerImpl_EntityManager_PendingMessages;
                    class PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage;
                    class PriorityTransportLayerImpl_EntityManager_SizeReader;
                    class PriorityTransportLayerImpl_EntityManager_clearState_1;
                    class PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5;
                    class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2;
                    class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3;
                    class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1;
                    class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2;
                    class PriorityTransportLayerImpl_EntityManager_send_6;
                    class PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4;
                    class PriorityTransportLayerImpl_destroy_4;
                    class PriorityTransportLayerImpl_incomingSocket_1;
                    class PriorityTransportLayerImpl_openSocket_2;
                    class PriorityTransportLayerImpl_openSocket_2_receiveResult_2_1;
                    class PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2;
                    class PriorityTransportLayerImpl_sendMessage_3;
                    struct PriorityTransportLayerListener;
                    class QueueOverflowException;
                } // priority
            } // transport
        } // p2p
    } // mpisws
} // org
