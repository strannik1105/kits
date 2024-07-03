#ifndef KIT_FINDER_H
#define KIT_FINDER_H

#include <string>
#include <vector>

#include "kits/kit.h"
#include "kits/receipt.h"


namespace Kits
{
    struct FoundKit
    {
        int position;
        int count;
        std::string catalog;

        FoundKit(int position, int count, std::string catalog);  
    };

    class KitsFinder
    {
        public:
            KitsFinder() {};
            bool find_kit(Receipt receipt, Kit kit);
    };
};

#endif