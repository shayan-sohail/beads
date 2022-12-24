#pragma once
#include <iostream>
#include <winsock2.h>

using SocketType = enum SocketType
{
    TCP = 1,
    UDP = 2
};

class Socket
{
    WSADATA wsa;
    SOCKET m_socket;
    std::string m_errorString;
    bool m_status;

public:
    sockaddr_in m_sockaddr;
    int32_t m_len;

    Socket() {}
    Socket(SocketType type, std::string_view ipaddress, uint16_t port, uint32_t rxTimeout = NULL)
    {
        m_status = true;
        m_errorString = "No Error";
        if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        {
            m_errorString = "WSA Startup Failed. Error Code : " + std::to_string(WSAGetLastError());
            m_status = false;
        }
        m_socket = socket(AF_INET, type, 0);
        if (m_socket == INVALID_SOCKET)
        {
            m_errorString = "Socket Creation Failed. Error Code : " + std::to_string(WSAGetLastError());
            m_status = false;
        }

        if (rxTimeout != NULL)
        {
            struct timeval tv;
            tv.tv_sec = 0;
            tv.tv_usec = rxTimeout;
            if (setsockopt(m_socket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) < 0)
            {
                m_status = false;
                m_errorString = "Socket Timeout Failed. Error Code: " + std::to_string(WSAGetLastError());
            }
            else {
                std::cout << "All ok bro" << std::endl;
            }
        }
        m_sockaddr.sin_family = AF_INET;
        m_sockaddr.sin_addr.s_addr = inet_addr(ipaddress.data());
        m_sockaddr.sin_port = htons(port);
        m_len = sizeof(m_sockaddr);
    }

    size_t receive(Socket& sourceInfo, char* buffer, size_t maxLength)
    {
        return recvfrom(m_socket, buffer, maxLength, 0, (struct sockaddr*)&sourceInfo.m_sockaddr, &sourceInfo.m_len);
    }
    size_t send(Socket& destinationInfo, char* message, size_t length)
    {
        return sendto(m_socket, message, length, 0, (struct sockaddr*)&destinationInfo.m_sockaddr, destinationInfo.m_len);
    }
    bool bind_socket()
    {
        if (bind(m_socket, (struct sockaddr*)&m_sockaddr, sizeof(m_sockaddr)) == SOCKET_ERROR) return false;
        return true;
    }
    std::string getErrorString()
    {
        return m_errorString;
    }
    ~Socket()
    {
        closesocket(m_socket);
        WSACleanup();
    }
};