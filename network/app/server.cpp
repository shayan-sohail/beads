#include "network.h"
#include <array>
int main()
{
    std::array<char, 10> buffer;
    Socket socket(SocketType::UDP, "127.0.0.1", 8888), receiverInfo;
    socket.bind_socket();

    while (1)
    {
        std::cout << "Receiving data...\n";
        int nBytes = socket.receive(receiverInfo, buffer.data(), 10);
        if (nBytes > 0) {
            buffer[nBytes] = '\0';
            printf("Message Received %s\n", buffer.data());
        }
        else {
            std::cout << "Receive Error\n";
        }
    }

}