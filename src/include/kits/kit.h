#ifndef KIT_H
#define KIT_H

#include <string>
#include <vector>

#include "common/document_reader.h"


namespace Kits
{
    class Kit
    {
        private:
            std::vector<std::pair<std::string, int>> catalog_n_count;
        public:
            Kit(DocumentReader::ReaderResult readed_doc);
            std::vector<std::pair<std::string, int>> get_catalogs_count();
    };
};

#endif