#include <iostream>
#include <string>

#include "common/txt_document_reader.h"

using namespace DocumentReader;
using namespace std;


int main()
{
  string line;
  auto reader = std::make_shared<TxtDocumentReader>("document.txt");
  auto readed_file = reader->read();
  auto catalogs = readed_file->get_column("Каталоги");
  for(auto i = catalogs->begin(); i < catalogs->end(); i++)
    cout << *i << endl;

  return 0;
}