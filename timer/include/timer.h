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
public:
    struct CB_Props
    {
        bool m_isperiodic;
        uint64_t m_duration_millisec;
        tp m_start_millisec;
        uint64_t m_elapsed_millisec;
        std::function<void()> m_callback;
    };
    std::map<uint64_t, CB_Props> m_callbacks;
private:
    bool m_keepAlive;
    uint64_t m_toRemove;
    std::thread m_thread;

public:

    Timer()
    {
        m_keepAlive = true;
        m_thread = std::thread(&Timer::t_sync, this);
        m_thread.detach();
        m_toRemove = 0;
    }

    void add_periodic(void (*callback)(void), uint64_t duration_millisec)
    {
        CB_Props cb = { true, duration_millisec, std::chrono::high_resolution_clock::now(), 0, callback };
        m_callbacks[(uint64_t)callback] = cb;
    }

    void add_singleshot(void (*callback)(void), uint64_t duration_millisec)
    {
        CB_Props cb = { false, duration_millisec, std::chrono::high_resolution_clock::now(), 0, callback };
        m_callbacks[(uint64_t)callback] = cb;
    }

    void remove(void (*callback)(void))
    {
        while (m_toRemove != 0) {}
        m_toRemove = (uint64_t)callback;
    }

    ~Timer()
    {
        m_keepAlive = false;
    }
private:
    void t_sync()
    {
        using namespace std::chrono;
        while (m_keepAlive)
        {
            int i = 0;
            for (auto& cb : m_callbacks)
            {

                cb.second.m_elapsed_millisec = duration_cast<milliseconds>(hrc::now() - cb.second.m_start_millisec).count();
                if (cb.second.m_elapsed_millisec >= cb.second.m_duration_millisec)
                {
                    cb.second.m_callback();
                    if (!cb.second.m_isperiodic) m_callbacks.erase(cb.first);
                    else cb.second.m_start_millisec = hrc::now();
                }
            }
            if (m_toRemove != 0)
            {
                m_callbacks.erase(m_toRemove);
                m_toRemove = 0;
            }
        }
        std::cout << "Exiting Thread" << std::endl;
    }

};