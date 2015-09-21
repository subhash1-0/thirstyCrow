// Forward declarations for org.mpisws.p2p.filetransfer
#pragma once


namespace org
{
    namespace mpisws
    {
        namespace p2p
        {
            namespace filetransfer
            {
                struct BBReceipt;
                struct FileAllocationStrategy;
                struct FileReceipt;
                struct FileTransfer;
                struct FileTransferCallback;
                class FileTransferImpl;
                class FileTransferImpl_BBDataReader;
                class FileTransferImpl_BBHeaderReader;
                class FileTransferImpl_BBReceiptImpl;
                class FileTransferImpl_ChunkReader;
                struct FileTransferImpl_DataReader;
                class FileTransferImpl_FileDataReader;
                class FileTransferImpl_FileDataReader_cancelled_3;
                class FileTransferImpl_FileDataReader_cancelled_4;
                class FileTransferImpl_FileDataReader_completeChunk_1;
                class FileTransferImpl_FileDataReader_completeChunk_2;
                class FileTransferImpl_FileHeaderReader;
                class FileTransferImpl_FileNameReader;
                class FileTransferImpl_FileReceiptImpl;
                class FileTransferImpl_FileReceiptImpl_cancel_5;
                class FileTransferImpl_FileReceiptImpl_cancel_6;
                class FileTransferImpl_FileReceiptImpl_scheduleClose_3;
                class FileTransferImpl_FileReceiptImpl_scheduleClose_4;
                class FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1;
                class FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2;
                struct FileTransferImpl_MessageWrapper;
                class FileTransferImpl_MessageWrapperImpl;
                class FileTransferImpl_MsgTypeReader;
                struct FileTransferImpl_Reader;
                class FileTransferImpl_ReceiptImpl;
                class FileTransferImpl_SimpleMessageWrapper;
                class FileTransferImpl_enqueue_1;
                struct FileTransferListener;
                class OperationCancelledException;
                struct Receipt;
                class SimpleFileTransferListener;
                class TempFileAllocationStrategy;
                class TransferFailedException;
            } // filetransfer
        } // p2p
    } // mpisws
} // org
