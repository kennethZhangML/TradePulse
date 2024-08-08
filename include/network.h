#ifndef NETWORK_H
#define NETWORK_H

#include <boost/asio.hpp>
#include <thread>
#include <functional>

class NetworkListener { 
public:
    NetworkListener(boost::asio::io_context& io_context, unsigned short port);
    void startListening();
    void setOnDataReceived(const std::function<void(const std::string&)>& callback);

private:
    void doAccept();
    void doRead(boost::asio::ip::tcp::socket socket);

    boost::asio::ip::tcp::acceptor acceptor_;
    std::function<void(const std::string&)> onDataReceived_;
};

#endif // NETWORK_H