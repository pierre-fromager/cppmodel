
#include "file.hpp"

using namespace cppmodel;

/*
template <typename T>
struct TemplateListe
{
    typedef std::vector<T> type;
};*/

template <class T>
File<T>::File(std::string filename, TemplateListe list)
    : m_filename(filename), m_list(list)
{
}