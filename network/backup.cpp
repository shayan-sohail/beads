#pragma once
#include <iostream>
#include <array>
#include <winsock2.h>

using ConnectionType = enum ConnectionType
{
    TCP = SOCK_STREAM, UDP = SOCK_DGRAM
};

using ConnectionSide = enum ConnectionSide
{
    SERVER, CLIENT
};

class Socket
{
    int32_t m_len;
public:
    struct sockaddr_in m_sockaddr;
    SOCKET m_socket;
    int32_t m_nBytes; /*Used for receive Sockets*/

public:
    friend class Udp;
    Socket()
    {
        m_socket = socket(AF_INET, UDP, 0);
        m_nBytes = -1;
        m_len = sizeof(m_sockaddr);
        if (m_socket != INVALID_SOCKET)
        {
            m_sockaddr.sin_family = AF_INET;
            m_sockaddr.sin_addr.s_addr = INADDR_ANY;
            m_sockaddr.sin_port = htons(0);
        }
    }

    bool Set(ConnectionType type, std::string ip_address, uint32_t port)
    {
        m_socket = socket(AF_INET, type, 0);
        if (m_socket != INVALID_SOCKET)
        {
            m_sockaddr.sin_family = AF_INET;
            m_sockaddr.sin_addr.s_addr = inet_addr(ip_address.data());
            m_sockaddr.sin_port = htons(port);
            return true;
        }
        return false;
    }

    bool Bind()
    {
        if (bind(m_socket, (struct sockaddr*)&m_sockaddr, sizeof(m_sockaddr)) == SOCKET_ERROR) return false;
        return true;
    }

    ~Socket()
    {
        closesocket(m_socket);
    }
};

class Udp
{
private:
    Socket m_socket, m_client_socket;
    WSADATA m_wsa;
    struct sockaddr_in m_client; int32_t m_client_len;
    std::string m_errorString;

public:
    bool m_status;
    Udp(ConnectionSide side, std::string ip_address, uint32_t port)
    {
        m_status = true;
        m_errorString = "No Error";
        if (WSAStartup(MAKEWORD(2, 2), &m_wsa) != 0)
        {
            m_errorString = "WSA Startup Failed, Error Code " + std::to_string(WSAGetLastError());
            m_status = false;
        }
        if (!m_socket.Set(UDP, ip_address, port))
        {
            m_errorString = "Socket Creation Failed " + std::to_string(WSAGetLastError());
            m_status = false;
        }
        else
        {
            if (side == SERVER)
            {
                if (!m_socket.Bind())
                {
                    m_errorString = "Bind Failed, Error Code " + std::to_string(WSAGetLastError());
                    m_status = false;
                }
            }
        }
    }

    std::string getLastError()
    {
        return m_errorString;
    }

    int send(char* buffer, int length, Socket& client)
    {
        return sendto(m_socket.m_socket, buffer, length, 0, (struct sockaddr*)&client.m_sockaddr, sizeof(client.m_sockaddr));
    }

    Socket receive(char* buffer, int MaxBufferLength = 512)
    {
        m_client_socket.m_nBytes = recvfrom(m_socket.m_socket, buffer, MaxBufferLength, 0, (struct sockaddr*)&m_client_socket.m_sockaddr, &m_client_socket.m_len);
        return m_client_socket;
    }

};