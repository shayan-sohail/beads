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
public:
    struct sockaddr_in m_sockaddr;
    SOCKET m_socket;

public:
    Socket()
    {
        m_socket = socket(AF_INET, UDP, 0);
        if (m_socket != INVALID_SOCKET)
        {
            m_sockaddr.sin_family = AF_INET;
            m_sockaddr.sin_addr.s_addr = INADDR_ANY;
            m_sockaddr.sin_port = htons(8888);
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
    Socket m_socket;
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

    int send(char* buffer, int length, sockaddr_in& client, int& clientlen)
    {
        return sendto(m_socket.m_socket, buffer, length, 0, (struct sockaddr*)&client, clientlen);
    }

    int receive(char* buffer, sockaddr_in& clientInfo, int& clientInfoLen, int MaxBufferLength = 512)
    {
        return recvfrom(m_socket.m_socket, buffer, MaxBufferLength, 0, (struct sockaddr*)&clientInfo, &clientInfoLen);
    }
    int receive(char* buffer, int MaxBufferLength = 512)
    {
        return recvfrom(m_socket.m_socket, buffer, MaxBufferLength, 0, NULL, NULL);
    }
};