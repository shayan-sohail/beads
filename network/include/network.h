#pragma once
#include <iostream>
#include <array>
#include <winsock2.h>

/*Steps of Socket Programming
1. Create a Socket


*/
class Network
{
protected:
    static constexpr uint32_t m_MaxBufferLength = 512;
    static constexpr uint32_t m_PORT = 8888;
    SOCKET m_socket;
    struct sockaddr_in m_server;
    int32_t m_slen, m_recvPktLen;
    bool m_isInitialized;
    std::string m_errorString;

    std::array<int8_t, m_MaxBufferLength> m_buffer;
    WSADATA m_wsa;

public:
    Network()
    {
        m_isInitialized = true;
        m_errorString = "No Error";
        m_slen = sizeof(m_server);
        if (WSAStartup(MAKEWORD(2, 2), &m_wsa) != 0)
        {
            m_errorString = "WSA Startup Failed, Error Code " + std::to_string(WSAGetLastError());
            m_isInitialized = false;
        }
        if (m_isInitialized && (m_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) /*Creating */
        {
            m_errorString = "Socket Creation Failed, Error Code " + std::to_string(WSAGetLastError());
            m_isInitialized = false;
        }
        else
        {
            m_server.sin_family = AF_INET;
            m_server.sin_addr.s_addr = INADDR_ANY;
            m_server.sin_port = htons(m_PORT);

            if (m_isInitialized && bind(m_socket, (struct sockaddr*)&m_server, sizeof(m_server)) == SOCKET_ERROR)
            {
                m_errorString = "Bind Failed, Error Code " + std::to_string(WSAGetLastError());
                m_isInitialized = false;
            }
        }
    }
    ~Network()
    {
        closesocket(m_socket);
        WSACleanup();
    }
};

class UDP_Server: public Network
{
private:
    struct sockaddr_in m_client;

public:
    void listen()
    {
        printf("Waiting for data...");
        fflush(stdout);
        std::fill(m_buffer.begin(), m_buffer.end(), '\0');
        while (1)
        {
            if ((m_recvPktLen = recvfrom(m_socket, (char*)m_buffer.data(), m_MaxBufferLength, 0, (struct sockaddr*)&m_client, &m_slen)) == SOCKET_ERROR)
            {
                m_errorString = "Receive Failed, Error Code " + std::to_string(WSAGetLastError());
                break;
            }

            printf("Received packet from %s:%d\n", inet_ntoa(m_client.sin_addr), ntohs(m_client.sin_port));
            printf("Data: %s\n", m_buffer);

            if (sendto(m_socket, (char*)m_buffer.data(), m_recvPktLen, 0, (struct sockaddr*)&m_client, m_slen) == SOCKET_ERROR)
            {
                m_errorString = "Send Failed, Error Code " + std::to_string(WSAGetLastError());
            }
        }
    }
};

class UDP_Client
{

};

class TCP_Server
{

};

class TCP_Client
{

};