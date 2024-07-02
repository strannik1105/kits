#ifndef DOCUMENT_READER_H
#define DOCUMENT_READER_H

#include <map>
#include <memory>
#include <string>
#include <vector>

using std::map;
using std::shared_ptr;
using std::string;
using std::vector;


namespace DocumentReader
{

    typedef map<string, shared_ptr<vector<string>>> Column_t;

    class ReaderResult
    {
        private:
            shared_ptr<Column_t> columns;
        public:
            ReaderResult();
            ~ReaderResult() {};
            void append_column(string name);
            void append_value_by_column(string column, string value);
    };

    // i think it is not good name, but....
    class IDocumentReader
    {
        public:
            virtual shared_ptr<ReaderResult> read() = 0;
    };
}

#endif