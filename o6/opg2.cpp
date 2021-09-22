#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             // If not error:
                             if (!ec) {
                                 // Retrieve inputMessage from client as string:
                                 istream read_stream(read_buffer.get());
                                 std::string inputMessage;
                                 std::string outputMessage;
                                 getline(read_stream, inputMessage);
                                 inputMessage.pop_back(); // Remove "\r" at the end of inputMessage

                                 if (inputMessage.find("GET / HTTP/1.1") == 0) {
                                     outputMessage = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 19\n\nDette er hovedsiden";
                                 }
                                 else if(inputMessage.find("GET /en_side HTTP/1.1") == 0) {
                                     outputMessage = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 16\n\nDette er en side";
                                 }
                                 else {
                                     outputMessage = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 13\n\n404 Not found";
                                 }

                                 auto write_buffer = make_shared<boost::asio::streambuf>();
                                 ostream write_stream(write_buffer.get());

                                 // Add outputmessage to be written to client:
                                 write_stream << outputMessage << "\r\n";

                                 // Write to client
                                 async_write(connection->socket, *write_buffer,
                                             [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                                 // If not error:
                                                 if (!ec)
                                                     handle_request(connection);
                                             });
                             }
                         });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            // If not error:
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();

        io_service.run();
    }
};

int main() {
    EchoServer echo_server;

    cout << "Starting echo server" << endl;

    echo_server.start();
}

