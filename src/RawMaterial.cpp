#include "../include/RawMaterial.h"

RawMaterial::RawMaterial(const std::string& id, const std::string& name,
                         int quantity, int minStock)
    : InventoryItem(id, name, quantity, minStock) {}