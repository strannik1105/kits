#include <cstdlib>

#include "kits/receipt.h"

std::vector<std::string> split(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

Kits::Receipt::Receipt(DocumentReader::ReaderResult readed_doc)
{
    auto positions = readed_doc.get_column("Поз.");
    auto counts = readed_doc.get_column("Кол-во");
    auto catalogs = readed_doc.get_column("Каталоги");

    for(int i = 0; i < (*catalogs).size(); i++)
    {
        auto catalogs_i = split((*catalogs)[i], ",");
        for(auto j = catalogs_i.begin(); j < catalogs_i.end(); j++)
        {
            if (this->catalog_n_count.find(*j) == this->catalog_n_count.end())
            {
                std::vector<int> items;


                this->catalog_n_count.insert(
                        {
                            *j,
                            items
                        }
                    );
            } 
            
            size_t count_i = std::strtol((*counts)[i].c_str(), NULL, 10);
            int  positions_i = std::strtol((*positions)[i].c_str(), NULL, 10);
            for(int k = 0; k < count_i; k++)
            {
                this->catalog_n_count[*j].push_back(positions_i);
            }
        }
    }
}