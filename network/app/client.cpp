#include "network.h"
#include <thread>
#include <chrono>
#include <array>
int main()
{
    // std::array<char, 10> buffer;
    std::string buffer;

    Socket socket(SocketType::UDP, "127.0.0.1", 8888);
    Socket destination(SocketType::UDP, "127.0.0.1", 8890);

    std::cout << socket.getErrorString() << std::endl;
    while (1)
    {
        std::cout << "Input >> ";
        std::cin >> buffer;
        int nBytes = socket.send(destination, buffer.data(), buffer.size());
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