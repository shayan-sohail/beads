#include "network.h"
#include <thread>
#include <chrono>
#include <array>
int main()
{
    std::array<char, 10> buffer{ 'T','E','S','T','M','E','S','S','A','G' };

    Socket socket(SocketType::UDP, "127.0.0.1", 8888);

    std::cout << socket.getErrorString() << std::endl;
    while (1)
    {
        std::cout << "Sending data...\n";
        int nBytes = socket.send(socket, buffer.data(), 10);
        if (nBytes > 0) {
            buffer[nBytes] = '\0';
            printf("Message Sent %s\n", buffer.data());
        }
        else {
            std::cout << "Send Error\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}