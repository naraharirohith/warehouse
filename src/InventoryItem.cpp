#include "../include/InventoryItem.h"

InventoryItem::InventoryItem(const std::string& id, const std::string& name,
                             int quantity, int minStock)
    : id(id), name(name), quantity(quantity), minStockLevel(minStock) {}

std::string InventoryItem::getId() const { return id; }
std::string InventoryItem::getName() const { return name; }
int InventoryItem::getQuantity() const { return quantity; }
int InventoryItem::getMinStockLevel() const { return minStockLevel; }

void InventoryItem::updateQuantity(int newQuantity) {
    quantity = newQuantity;
}

void InventoryItem::setMinStockLevel(int newMin) {
    minStockLevel = newMin;
}

void InventoryItem::display() const {
    std::cout << "\nID: " << id
              << "\nName: " << name
              << "\nQuantity: " << quantity
              << "\nMin Stock: " << minStockLevel
              << "\n------------------------\n";
}