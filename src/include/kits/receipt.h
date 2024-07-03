#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
#include <vector>

#include "common/document_reader.h"


namespace Kits
{
    class Receipt
    {
        private:
            std::map<std::string, std::vector<int>> catalog_n_count;
        public:
            Receipt(DocumentReader::ReaderResult readed_doc);
    };
};

#endif