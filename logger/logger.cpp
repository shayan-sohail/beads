#include "logger.h"

bool LogStream::default_stdout = true;
LogStream::NullBuffer LogStream::null_buffer;
std::ostream LogStream::null_stream(&LogStream::null_buffer);

std::array <std::string_view, 5> logProps = { white, green, blue, yellow, red }; /*Log Colors*/

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

LogStream& log(LogStream& stream, LOG_LEVEL level)
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