#include <iostream>
#include <string>

#include "common/txt_document_reader.h"
#include "kits/kit.h"
#include "kits/kits_finder.h"
#include "kits/receipt.h"

using namespace DocumentReader;
using namespace Kits;


int main(const int argc, const char *argv[])
{ 
  if(argc < 2)
  {
    std::cout << "Слишком мало аргументов\n";
    return 0;
  }
  else if(argc > 3)
  {
    std::cout << "Слишком много аргументов\n";
    return 0;
  }

  auto kits_reader = std::make_shared<TxtDocumentReader>("kit.txt");
  auto kit = Kit(*kits_reader->read());

  auto receipt_reader = std::make_shared<TxtDocumentReader>("document.txt");
  auto receipt = Receipt(*receipt_reader->read());

  auto kits_finder = std::make_shared<KitsFinder>();
  if(kits_finder->find_kit(receipt, kit))
  {
    std::cout << "Набор содержится в документе\n";
  }
  else
  {
    std::cout << "Набор не содержится в документе\n";
  }

  return 0;
}