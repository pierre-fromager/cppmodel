
#ifndef CPPMODEL_FILE_HPP
#define CPPMODEL_FILE_HPP

#include <string>
#include <vector>

namespace cppmodel
{

    template <typename T>
    struct TemplateListe
    {
        typedef std::vector<T> type;
    };

    //
    // @brief File Class
    //
    //
    template <class T>
        class FileTemplate
        {

        public:
            FileTemplate(std::string &filename, TemplateListe<T> &list);
            bool write(std::ostream &s);
            bool read(std::istream &s);

        private:
            std::string m_filename;
            TemplateListe<T> m_list;
    };

}
#endif