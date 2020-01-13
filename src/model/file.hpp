
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
        class File
        {

        public:
            File(std::string &filename, TemplateListe &list);
            bool load();
            bool save();
            void setFilename();
            void setListe();

        private:
            std::string m_filename;
            TemplateListe m_list;
    };

} // namespace cppmodel
#endif