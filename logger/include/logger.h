#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <ctime>
#pragma once

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
std::array <std::string_view, 5> logProps = { white, green, blue, yellow, red }; /*Log Colors*/



class LogStream
{
    class NullBuffer: public std::streambuf
    {};

    std::string m_logName;
    std::string m_logFileName;
    std::fstream file = nullptr;
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

bool LogStream::default_stdout = true;
LogStream::NullBuffer LogStream::null_buffer;
std::ostream LogStream::null_stream(&LogStream::null_buffer);

LogStream::LogStream(std::string_view name, std::string_view path)
{
    m_logName = name;
    m_logFileName = path;
    m_logFileName = m_logFileName + m_logName + ".log";
}

LogStream::~LogStream()
{
    file.close();
}

std::string date_time()
{
    time_t now = time(0);
    tm* DateTime = localtime(&now);
    std::string year = std::to_string(DateTime->tm_year + 1900);
    std::string month = std::to_string(DateTime->tm_mon + 1);
    std::string day = std::to_string(DateTime->tm_mday);
    std::string hour = std::to_string(DateTime->tm_hour);
    std::string min = std::to_string(DateTime->tm_min);
    std::string sec = std::to_string(DateTime->tm_sec);

    month = month.length() == 1 ? "0" + month : month;
    day = day.length() == 1 ? "0" + day : day;
    hour = hour.length() == 1 ? "0" + hour : hour;
    min = min.length() == 1 ? "0" + min : min;
    sec = sec.length() == 1 ? "0" + sec : sec;

    return  "[" + day + "/" + month + "/" + year + " " + hour + ":" + min + ":" + sec + " | ";
}

/*Default Construct for Log*/
std::ostream& log()
{
    if (LogStream::default_stdout) return std::cout;
    return LogStream::null_stream;
}

LogStream& log(LogStream& stream, LOG_LEVEL level = INFO)
{
    std::cout << logProps[level];
    stream << date_time() << stream.m_logName << "]\t";
    std::cout << reset;
    return stream;
}

LogStream& log(LogStream& stream, std::string_view Trace)
{
    std::cout << logProps[2];
    stream << date_time() << stream.m_logName << "]\t";
    stream << Trace << "\t";
    std::cout << reset;
    return stream;
}
// target_compile_options(demo PRIVATE -std=c++20)