#include "iostream"

#include "kits/kits_finder.h"


Kits::FoundKit::FoundKit(int position, int count, std::string catalog)
{
    this->position = position;
    this->count = count;
    this->catalog = catalog;
}

bool Kits::KitsFinder::find_kit(Kits::Receipt receipt, Kits::Kit kit)
{
    auto kits = kit.get_catalogs_count();
    auto records = receipt.get_records();
    bool status = true;

    std::vector<Kits::FoundKit> found_kits;

    for(size_t i = 0; i < kits.size(); i++)
    {
        if(records.find(kits[i].first) != records.end())
        {
            if(!(kits[i].second <= records[kits[i].first].size()))
            {
                status = false;
            }
        }
    }

    return status;
}