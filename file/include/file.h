#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

/*What to add
A file to read contents in a byte array,
Convert functions to primitive data types
*/


using table = std::map<std::string, std::vector<uint8_t>>;
/*
This table Implementation should look like

Key1    Key2    Key3    Key4...

Vec1    Vec2    Vec3    Vec4
Vec1    Vec2    Vec3    Vec4
Vec1    Vec2    Vec3    Vec4
Vec1    Vec2    Vec3    Vec4

*/
class File
{
    std::fstream m_file;
public:

    bool read(uint8_t* input, const char* file_name)
    {
        m_file.open(file_name, std::ios::in);
        if (m_file)
        {
            for (size_t i = 0; !m_file.eof(); i++) m_file >> input[i];
            m_file.close();
            return true;
        }
        return false;
    }

    bool read(uint8_t* input, const char* file_name, uint32_t n_bytes)
    {
        m_file.open(file_name, std::ios::in);
        if (m_file)
        {
            for (size_t i = 0; !m_file.eof() || i < n_bytes; i++) m_file >> input[i];
            m_file.close();
            return true;
        }
        return false;
    }

    bool write(uint8_t* input, const char* file_name, int length, std::ios_base::openmode mode = std::ios::out)
    {
        m_file.open(file_name, mode);
        if (m_file)
        {
            for (size_t i = 0; i < length; i++) m_file << input[i];
            m_file.close();
            return true;
        }
        return false;
    }

    bool read_csv(table& data, const char* file_name, bool hasHeaders = false);

    bool write_csv(table& data, const char* file_name);

};