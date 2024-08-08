#include "network.h"

NetworkListener::NetworkListener(boost::asio::io_context& io_context, unsigned short port) :
    acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

void NetworkListener::startListening() {
    doAccept();
}

void NetworkListener::setOnDataReceived(const std::function<void(const std::string&)>& callback) {
    onDataReceived_ = callback;
}

