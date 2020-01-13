
#include "file.hpp"

using namespace cppmodel;

template <class T>

File<T>::File(std::string &filename, TemplateListe<T> &list)
    : m_filename(filename), m_list(list)
{
}