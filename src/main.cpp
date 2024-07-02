#include <iostream>
#include <string>

#include "common/txt_document_reader.h"

using namespace DocumentReader;
using namespace std;


int main()
{
  string line;
  auto reader = std::make_shared<TxtDocumentReader>("document.txt");
  reader->read();

  return 0;
}