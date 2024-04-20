/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-luan.bourbier [WSL: Ubuntu]
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
    #define EXCEPTION_HPP_
    #include <exception>
    #include <string>

namespace arcade
{
    class DLLoaderException : public std::exception
    {
        private:
            std::string _msg;
        public:
            DLLoaderException(std::string msg): _msg(msg) {};
            const char *what() const noexcept override 
            {
                return _msg.c_str();
            };
            ~DLLoaderException() {};
    };
    class ParsingException : public std::exception
    {
        private:
            std::string _msg;
        public:
            ParsingException(std::string msg): _msg(msg) {};
            const char *what() const noexcept override 
            {
                return _msg.c_str();
            };
            ~ParsingException() {};
    };
}

#endif /* !EXCEPTION_HPP_ */
