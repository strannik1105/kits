#include <sstream>

#include "common/txt_document_reader.h"

using namespace std;
using DocumentReader::TxtDocumentReader;


TxtDocumentReader::TxtDocumentReader(std::string txt_doc)
{
    this->input_stream.open(txt_doc);
}

TxtDocumentReader::~TxtDocumentReader()
{
    this->input_stream.close();
}

std::shared_ptr<DocumentReader::ReaderResult> DocumentReader::TxtDocumentReader::read()
{
    std::string headers_line;
    std::string line;
    auto reader_result = std::make_shared<DocumentReader::ReaderResult>();

    if (this->input_stream.is_open())
    {
        if(!std::getline(this->input_stream, headers_line))
        {
            return reader_result;
        }
        std::stringstream headers_stream(headers_line);
        std::string header;
        int headers_count = 0;
        std::map<int, std::string> header_mapper;

        while(headers_stream >> header)
        {
            reader_result->append_column(header);   
            header_mapper.insert({++headers_count, header});
        }

        while (std::getline(this->input_stream, line))
        {
            std::stringstream line_stream(line);
            std::string word;
            int column_cur = 0;

            while(line_stream >> word)
            {
                reader_result->append_value_by_column(header_mapper[++column_cur], word);
            }
        }
    }

    return reader_result;
}