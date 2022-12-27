#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <any>


class table {
    std::unordered_map <std::string, std::vector<uint8_t*>*> data;
    std::unordered_map<std::string, int> types;

public:
    template<typename T>
    void add_field(std::string header)
    {
        types[header] = typeid(T).hash_code();
        data[header] = new std::vector<uint8_t*>;
    }

    template<typename T>
    void insert(std::string field, T& Data)
    {
        if (types[field] != (int)typeid(T).hash_code())
        {
            std::cout << "Types does not match" << std::endl;
        }
        else
        {
            data[field]->push_back((uint8_t*)&Data);
            std::cout << data[field]->size() << std::endl;
            for (auto& x : *data[field])
            {
                std::cout << *(int*)x << std::endl;
            }
        }
    }
    ~table() {
        std::cout << "Destructor Called\n";
    }
};