#include <iostream>
#include <cstdlib>

#include "kits/kit.h"


Kits::Kit::Kit(DocumentReader::ReaderResult readed_doc)
{
    auto catalogs = readed_doc.get_column("Каталог");
    auto catalogs_values = readed_doc.get_column("Кол-во");

    for(size_t i = 0; i < (*catalogs).size(); i++)
    {
        size_t i_count = std::strtol((*catalogs_values)[i].c_str(), NULL, 10);
        this->catalog_n_count.push_back(
                {
                    (*catalogs)[i],
                    i_count,
                }
            );
    }
}

std::vector<std::pair<std::string, int>> Kits::Kit::get_catalogs_count()
{
    return this->catalog_n_count;
}