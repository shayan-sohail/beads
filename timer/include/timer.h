#pragma once
#include <thread>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>
#include <map>

using tp = std::chrono::_V2::system_clock::time_point;
using hrc = std::chrono::high_resolution_clock;

class Timer
{
private:
    struct CB_Props
    {
        bool m_isperiodic;
        uint64_t m_duration_millisec;
        tp m_start_millisec;
        uint64_t m_elapsed_millisec;
        std::function<void()> m_callback;
        bool m_firstCheck;
    };
    void t_sync();

    std::map<uint64_t, CB_Props> m_callbacks;
    bool m_keepAlive;
    std::thread m_thread;

public:

    Timer()
    {
        m_keepAlive = true;
        m_thread = std::thread(&Timer::t_sync, this);
        m_thread.detach();
    }

    void add_periodic(void (*callback)(void), uint64_t duration_millisec)
    {
        CB_Props cb = { true, duration_millisec, std::chrono::high_resolution_clock::now(), 0, callback, true };
        m_callbacks[(uint64_t)callback] = cb;
    }

    void add_singleshot(void (*callback)(void), uint64_t duration_millisec)
    {
        CB_Props cb = { false, duration_millisec, std::chrono::high_resolution_clock::now(), 0, callback, true };
        m_callbacks[(uint64_t)callback] = cb;
    }

    void remove(void (*callback)(void))
    {
        m_callbacks.erase((uint64_t)callback);
    }

    ~Timer()
    {
        m_keepAlive = false;
    }
};

void Timer::t_sync()
{
    using namespace std::chrono;
    while (m_keepAlive)
    {
        for (auto& cb : m_callbacks)
        {
            if (cb.second.m_firstCheck)
            {
                cb.second.m_firstCheck = false;
                cb.second.m_start_millisec = hrc::now();
            }

            cb.second.m_elapsed_millisec = duration_cast<milliseconds>(hrc::now() - cb.second.m_start_millisec).count();
            if (cb.second.m_elapsed_millisec >= cb.second.m_duration_millisec)
            {
                cb.second.m_callback();
                if (!cb.second.m_isperiodic) m_callbacks.erase(cb.first);
                else cb.second.m_start_millisec = hrc::now();
            }
        }
    }
}