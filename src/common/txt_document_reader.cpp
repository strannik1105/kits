#include <iostream>
#include <sstream>
#include <string>

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
        std::stringstream ss(headers_line);
        std::string header;
        int headers_count = 0;

        while(ss >> header)
        {
            std::cout << header << std::endl;
            
            headers_count++;
        }

        while (std::getline(this->input_stream, line))
        {
            std::cout << line << std::endl;
        }
    }

    return reader_result;
}