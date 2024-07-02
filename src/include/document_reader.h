#ifndef DOCUMENT_READER_H
#define DOCUMENT_READER_H

#include <map>
#include <string>
#include <vector>


using std::map;
using std::string;
using std::vector;


typedef map<string, vector<int>> columns Column_t;

class ReaderResult
{
    private:
        Column_t columns;
    public:
        ReaderResult();
};

class IDocumentReader
{
    public:
        void read
};

#endif DOCUMENT_READER_H