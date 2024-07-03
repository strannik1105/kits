#include <iostream>
#include <string>

#include "common/txt_document_reader.h"
#include "kits/kit.h"
#include "kits/receipt.h"

using namespace DocumentReader;
using namespace Kits;
using namespace std;


int main()
{ 
  auto kits_reader = std::make_shared<TxtDocumentReader>("kit.txt");
  auto kit = Kit(*kits_reader->read());

  auto receipt_reader = std::make_shared<TxtDocumentReader>("document.txt");
  auto receipt = Receipt(*receipt_reader->read());

  return 0;
}