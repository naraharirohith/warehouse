#pragma once
#include <string>
#include <iostream>

class InventoryItem {
protected:
    std::string id;
    std::string name;
    int quantity;
    int minStockLevel;

public:
    InventoryItem(const std::string& id, const std::string& name, 
                 int quantity, int minStock);
    virtual ~InventoryItem() = default;

    // Getters
    std::string getId() const;
    std::string getName() const;
    int getQuantity() const;
    int getMinStockLevel() const;

    // Setters
    virtual void updateQuantity(int newQuantity);
    void setMinStockLevel(int newMin);
    virtual void display() const;
};