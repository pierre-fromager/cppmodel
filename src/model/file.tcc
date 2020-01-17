
#ifndef CPPMODEL_FILE_TEMPLATE_HPP
#define CPPMODEL_FILE_TEMPLATE_HPP

#include <string>
#include <vector>

namespace cppmodel
{

//
// @brief File Class
//
//
template <typename Item, typename VectorItem = std::vector<Item>>
class FileTemplate
{

public:
    FileTemplate(std::string &filename, VectorItem &list);
    bool write(std::ostream &s);
    bool read(std::istream &s);

private:
    std::string m_filename;
    VectorItem m_list;
};

//
// @brief Construct a new File Template< T>:: File Template object
//
// @tparam T
// @param filename
// @param list
//

template <typename Item, typename VectorItem>
FileTemplate<Item, VectorItem>::FileTemplate(std::string &filename, VectorItem &list)
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
template <typename Item, typename VectorItem>
bool FileTemplate<Item, VectorItem>::write(std::ostream &s)
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
template <typename Item, typename VectorItem>
bool FileTemplate<Item, VectorItem>::read(std::istream &s)
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

} // namespace cppmodel
#endif