#pragma once
#include "InventoryItem.h"

class RawMaterial : public InventoryItem {
public:
    RawMaterial(const std::string& id, const std::string& name,
               int quantity, int minStock);
};git remote remove origin