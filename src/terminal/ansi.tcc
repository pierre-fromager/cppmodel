
#ifndef CPPMODEL_TERMINAL_ANSI_HPP
#define CPPMODEL_TERMINAL_ANSI_HPP
#define ANSI_BLACK "\033[30m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN "\033[36m"
#define ANSI_WHITE "\033[37m"
#define ANSI_RESET "\033[0m"
#define ANSI_UNDERLINE "\033[4m"
#define ANSI_BOLD "\033[1m"
#define ANSI_REVERSE "\033[7m"

#include <string>

namespace cppmodel
{
namespace terminal
{
namespace ansi
{

using namespace std;

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_black(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_BLACK;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_red(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_RED;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_green(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_GREEN;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_yellow(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_YELLOW;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_blue(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_BLUE;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_magenta(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_MAGENTA;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_cyan(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_CYAN;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &fg_white(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_WHITE;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &reset(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_RESET;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &underline(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_UNDERLINE;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &bold(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_BOLD;
}

template <class CharT, class Traits>
constexpr basic_ostream<CharT, Traits> &reverse(basic_ostream<CharT, Traits> &os)
{
    return os << ANSI_REVERSE;
}

} // namespace ansi
} // namespace terminal
} // namespace cppmodel

#endif