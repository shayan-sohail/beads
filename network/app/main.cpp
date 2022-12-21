#include "network.h"

int main()
{
    Udp server(SERVER, "127.0.0.1", 8888);
    std::cout << server.getLastError() << std::endl;
    std::array<char, 20> buffer;

    struct sockaddr_in m_client;
    int m_slen = sizeof(m_client);

    std::fill(buffer.begin(), buffer.end(), '\0');
    std::cout << "Initializing Server\n";
    int n;
    if (server.m_status) n = server.receive(buffer.data(), m_client, m_slen, 20);
    std::printf("Message is %s and n is %d\n", buffer.data(), n);
    server.send(buffer.data(), n, m_client, m_slen);
    std::cout << "Here\n";

}