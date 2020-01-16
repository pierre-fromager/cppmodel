
#ifndef CPPMODEL_TERMINAL_ANSI_HPP
#define CPPMODEL_TERMINAL_ANSI_HPP

#define ANSI_RESET "\033[0m"
#define ANSI_BLACK "\033[30m"              /* Black */
#define ANSI_RED "\033[31m"                /* Red */
#define ANSI_GREEN "\033[32m"              /* Green */
#define ANSI_YELLOW "\033[33m"             /* Yellow */
#define ANSI_BLUE "\033[34m"               /* Blue */
#define ANSI_MAGENTA "\033[35m"            /* Magenta */
#define ANSI_CYAN "\033[36m"               /* Cyan */
#define ANSI_WHITE "\033[37m"              /* White */
#define ANSI_BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define ANSI_BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define ANSI_BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define ANSI_BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define ANSI_BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define ANSI_BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define ANSI_BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define ANSI_BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#include <string>

namespace cppmodel
{
namespace terminal
{

namespace ansi
{

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &reset(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_RESET;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_black(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_BLACK;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_red(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_RED;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_green(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_GREEN;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_yellow(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_YELLOW;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_blue(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_BLUE;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_magenta(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_MAGENTA;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_cyan(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_CYAN;
}

template <class CharT, class Traits>
constexpr std::basic_ostream<CharT, Traits> &fg_white(std::basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_WHITE;
}

} // namespace ansi
} // namespace terminal
} // namespace cppmodel

#endif