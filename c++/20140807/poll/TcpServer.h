#include "Socket.h"
#include "PollPoller.h"
#include <memory>

class TcpServer : private NonCopyable
{
    public:
        typedef TcpConnection :: TcpConnectionCallback TcpCallback;

        explicit TcpServer(const InetAddress &addr);

        //set Callback
        void setConnection(const TcpCallback &cb)
        { onConnect_ = cb; }
        void setMessage(const TcpCallback &cb)
        { onMessage_ = cb; }
        void setClose(const TcpCallback &cb)
        { onClose_ = cb; }

        void start();

    private:
        std::unique_ptr<Socket> sock_;

        std::unique_ptr<PollPoller> poller_;

        TcpCallback onConnect_;
        TcpCallback onMessage_;
        TcpCallback onClose_;

 };
