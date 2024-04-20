/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-luan.bourbier [WSL: Ubuntu]
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
    #define DLLOADER_HPP_
    #include <string>
    #include <dlfcn.h>
    #include "Exception.hpp"
    #include <memory>

template <typename T>
class DLLoader
{
    public:
        DLLoader() noexcept = default;
        DLLoader(const std::string &libPath)
        {
            loadLib(libPath);
        }
        ~DLLoader()
        {
            deleteLib();
        }

        DLLoader(const DLLoader&) = delete;
        DLLoader(DLLoader &&) = delete;
        DLLoader& operator=(const DLLoader&) = delete;
        DLLoader& operator=(DLLoader &&) = delete;

        void loadLib(const std::string &libPath)
        {
            deleteLib();
            _handle = dlopen(libPath.c_str(), RTLD_LAZY);
            
            if (!_handle)
            {
                throw arcade::DLLoaderException {dlerror()};
            }
            void *sym = dlsym(_handle, "entry_point");
            if (!sym)
            {
                throw arcade::DLLoaderException {dlerror()};
            }
            _lib = reinterpret_cast<std::shared_ptr<T>(*)()> (sym)();
        }

        void deleteLib() noexcept
        {
            _lib.reset();
            if (_handle) {
                dlclose(_handle);
            }
            _handle = nullptr;
        }
        std::shared_ptr<T> getLib()
        {
            return _lib;
        };

    protected:
    private:
        void* _handle{nullptr};
        std::shared_ptr<T> _lib{nullptr};
};

#endif /* !DLLOADER_HPP_ */
