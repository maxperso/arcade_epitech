/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-mathis.legrand
** File description:
** Loader
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <dlfcn.h>

template<typename T>
class DLLoader {
private:
    std::string _path;
    void *handle;
    T *(*get_instance)();

public:
    DLLoader(const std::string filename)
    {
        handle = dlopen(filename.c_str(), RTLD_LAZY);
        if (!handle) {
            throw std::runtime_error(dlerror());
        }
        get_instance = reinterpret_cast<T *(*)()>(dlsym(handle, "getInstance"));
        if (!get_instance) {
            throw std::runtime_error(dlerror());
        }
    }

    ~DLLoader()
    {
        if (handle)
        {
            dlclose(handle);
        }
    }

    T *getInstance()
    {
        return get_instance();
    }

    const std::string &getPath() const
    {
        return _path;
    }
};
