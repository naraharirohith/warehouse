#pragma once
#include "InventoryItem.h"
#include <unordered_map>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>

class InventoryManager {
    std::unordered_map<std::string, std::shared_ptr<InventoryItem>> items;
    
public:
    void addItem(std::shared_ptr<InventoryItem> item);
    void removeItem(const std::string& id);
    std::shared_ptr<InventoryItem> getItem(const std::string& id) const;
    void updateStock(const std::string& id, int quantity);
    void checkStockLevels() const;
    void displayAllItems() const;
    
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};