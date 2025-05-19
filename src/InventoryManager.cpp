#include "../include/InventoryManager.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

void InventoryManager::addItem(std::shared_ptr<InventoryItem> item) {
    if(items.find(item->getId()) != items.end()) {
        throw std::runtime_error("Item ID already exists");
    }
    items[item->getId()] = item;
}

void InventoryManager::removeItem(const std::string& id) {
    items.erase(id);
}

std::shared_ptr<InventoryItem> InventoryManager::getItem(const std::string& id) const {
    auto it = items.find(id);
    return (it != items.end()) ? it->second : nullptr;
}

void InventoryManager::updateStock(const std::string& id, int newQuantity) {
    if(auto item = getItem(id)) {
        item->updateQuantity(newQuantity);
    }
}

void InventoryManager::checkStockLevels() const {
    for(const auto& [id, item] : items) {
        if(item->getQuantity() < item->getMinStockLevel()) {
            std::cout << "ALERT: Low stock for " << item->getName()
                      << " (Current: " << item->getQuantity()
                      << ", Min: " << item->getMinStockLevel() << ")\n";
        }
    }
}

void InventoryManager::displayAllItems() const {
    for(const auto& [id, item] : items) {
        item->display();
    }
}

void InventoryManager::saveToFile(const std::string& filename) const {
    json j;
    for(const auto& [id, item] : items) {
        j[id] = {
            {"name", item->getName()},
            {"quantity", item->getQuantity()},
            {"minStock", item->getMinStockLevel()}
        };
    }
    
    std::ofstream file(filename);
    if(file) file << j.dump(4);
}

void InventoryManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if(!file) return;
    
    json j;
    try {
        file >> j;
        for(auto& [key, value] : j.items()) {
            auto item = std::make_shared<InventoryItem>(
                key,
                value["name"].get<std::string>(),
                value["quantity"].get<int>(),
                value["minStock"].get<int>()
            );
            items[key] = item;
        }
    } catch(const json::exception& e) {
        std::cerr << "Error loading data: " << e.what() << "\n";
    }
}