#include <string>

#include "common/document_reader.h"

using DocumentReader::Column_t;
using DocumentReader::ReaderResult;
using DocumentReader::Table_t;


ReaderResult::ReaderResult()
{
    this->columns = std::make_shared<Table_t>();
};

void ReaderResult::append_column(string name)
{
    this->columns->insert({name, std::make_shared<vector<std::string>>()});
}

void ReaderResult::append_value_by_column(string column, string value)
{
    (*this->columns)[column]->push_back(value);
}

Column_t ReaderResult::get_column(string name)
{
    return (*this->columns)[name];
}