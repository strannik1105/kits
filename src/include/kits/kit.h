#ifndef KIT_H
#define KIT_H

#include <map>
#include <string>

#include "common/document_reader.h"


namespace Kits
{
    class Kit
    {
        private:
            std::map<std::string, int> catalog_n_count;
        public:
            Kit(DocumentReader::ReaderResult readed_doc);
    };
};

#endif