#include <cstdlib>

#include "kits/kit.h"


Kits::Kit::Kit(DocumentReader::ReaderResult readed_doc)
{
    auto catalogs = readed_doc.get_column("Каталог");
    auto catalogs_values = readed_doc.get_column("Кол-во");

    for(size_t i = 0; i < (*catalogs).size(); i++)
    {
        size_t i_count = std::strtol((*catalogs_values)[i].c_str(), NULL, 10);
        this->catalog_n_count.insert(
                {
                    (*catalogs)[i],
                    i_count,
                }
            );
    }
}