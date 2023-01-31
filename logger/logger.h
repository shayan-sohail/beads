#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <ctime>

#define TRACE std::string(__FILE__) + ":" + std::string(__PRETTY_FUNCTION__) + ":" + std::to_string(__LINE__)

namespace colors
{
    constexpr std::string_view red = "\033[91m";
    constexpr std::string_view green = "\033[92m";
    constexpr std::string_view yellow = "\033[33m";
    constexpr std::string_view blue = "\033[94m";
    constexpr std::string_view magenta = "\033[95m";
    constexpr std::string_view cyan = "\033[96m";
    constexpr std::string_view white = "\033[97m";
    constexpr std::string_view reset = "\033[0m";
};

using namespace colors;

using LOG_LEVEL = enum LOG_LEVEL { INFO = 0, SUCCESS = 1, WARNING = 3, ERROR = 4 }; /*Log Types*/

class LogStream;
std::ostream& log();
LogStream& log(LogStream& stream, LOG_LEVEL level = INFO);
LogStream& log(LogStream& stream, std::string_view Trace);
std::string date_time();

class LogStream
{
    class NullBuffer: public std::streambuf
    {};

    std::string m_logName;
    std::string m_logFileName;
    std::fstream file = NULL;
    bool to_stdout = true;
    bool file_write = false;
    static NullBuffer null_buffer;
    static std::ostream null_stream;

public:
    static bool default_stdout;
    /*Path Format = D:/Something/Something/*/
    LogStream(std::string_view name = "Unknown", std::string_view path = "");
    ~LogStream();

    void disable_stdout() { to_stdout = false; }
    void enable_stdout() { to_stdout = true; }
    void enable_filewrite() { if (!file) file.open(m_logFileName.data(), std::ios::out | std::ios::app); file_write = true; }
    void disable_filewrite() { file_write = false; }

    friend std::ostream& log();
    friend LogStream& log(LogStream& stream, LOG_LEVEL level);
    friend LogStream& log(LogStream& stream, std::string_view Trace);

    template<typename T>
    friend LogStream& operator << (LogStream& stream, const T& mValue)
    {
        if (stream.to_stdout)
            std::cout << mValue;
        if (stream.file_write && stream.file)
            stream.file << mValue;

        return stream;
    }

    friend LogStream& operator << (LogStream& stream, std::ostream& (*endline)(std::ostream&))
    {
        if (stream.to_stdout)
            std::cout << endline;
        if (stream.file_write)
            stream.file << endline;

        return stream;
    }
};

// target_compile_options(demo PRIVATE -std=c++20)
