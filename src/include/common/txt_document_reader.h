#ifndef TXT_DOCUMENT_READER_H
#define TXT_DOCUMENT_READER_H

#include <fstream>
#include <string>

#include "common/document_reader.h"


namespace DocumentReader
{

    class TxtDocumentReader: public IDocumentReader
    {
        private:
            std::fstream input_stream;

        public:
            TxtDocumentReader(std::string txt_doc);
            ~TxtDocumentReader();
            std::shared_ptr<ReaderResult> read() override;
    };

}

#endif