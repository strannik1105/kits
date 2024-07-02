#include <string>

#include "common/document_reader.h"

using DocumentReader::ReaderResult;


ReaderResult::ReaderResult()
{
    this->columns = std::make_shared<Column_t>();
};

void ReaderResult::append_column(string name)
{
    this->columns->insert({name, std::make_shared<vector<std::string>>()});
}

void ReaderResult::append_value_by_column(string column, string value)
{
    (*this->columns)[column]->push_back(value);
}