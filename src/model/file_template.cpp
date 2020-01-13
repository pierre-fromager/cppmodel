
#include "file_template.hpp"

using namespace cppmodel;

//
// @brief Construct a new File Template< T>:: File Template object
//
// @tparam T
// @param filename
// @param list
//
template <class T>
FileTemplate<T>::FileTemplate(std::string &filename, TemplateListe<T> &list)
    : m_filename(filename), m_list(list)
{
}

//
// @brief write whatever vector to file
//
// @tparam T
// @param s
// @return true
// @return false
//
template <class T>
bool FileTemplate<T>::write(std::ostream &s)
{
    unsigned int len = m_list.size();
    s.write((char *)&len, sizeof(len));
    for (unsigned int i = 0; i < len; i++)
    {
        write(s, m_list[i]);
    }
    return true;
}

//
// @brief read whatever vector from file
//
// @tparam T
// @param s
// @return true
// @return false
//
template <class T>
bool FileTemplate<T>::read(std::istream &s)
{
    unsigned int len = 0;
    s.read((char *)&len, sizeof(len));
    m_list.resize(len);
    for (unsigned int i = 0; i < len; i++)
    {
        read(s, m_list[i]);
    }
    return true;
}
