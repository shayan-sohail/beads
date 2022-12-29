#include "network.h"
#include <array>
int main()
{
    std::array<char, 50> buffer;
    Socket socket(SocketType::UDP, "127.0.0.1", 8890), receiverInfo;
    socket.bind_socket();
    std::cout << socket.getErrorString() << std::endl;
    printf("Last Error: %d\n", WSAGetLastError());
    while (1)
    {
        std::cout << "Receiving data...\n";
        int nBytes = socket.receive(receiverInfo, buffer.data(), 10);
        if (nBytes > 0) {
            buffer[nBytes] = '\0';
            printf("Message Received %s\n", buffer.data());
        }
        else {
            printf("Error: %d\n", WSAGetLastError());
        }
    }

}