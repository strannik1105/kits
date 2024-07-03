#include <iostream>
#include <string>

#include "common/txt_document_reader.h"
#include "kits/kit.h"

using namespace DocumentReader;
using namespace Kits;
using namespace std;


int main()
{
  string line;
  auto reader = std::make_shared<TxtDocumentReader>("document.txt");
  auto readed_file = reader->read();
  auto catalogs = readed_file->get_column("Каталоги");
  for(auto i = catalogs->begin(); i < catalogs->end(); i++)
    cout << *i << endl;
  
  auto kits_reader = std::make_shared<TxtDocumentReader>("kit.txt");
  auto kit = Kit(*kits_reader->read());

  return 0;
}