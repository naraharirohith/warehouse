#include "InventoryManager.h"
#include "InventoryItem.h"
#include "RawMaterial.h"
#include <iostream>
#include <memory>
#include <limits>

void displayMenu() {
    std::cout << "\nWarehouse Management System\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. View All Items\n";
    std::cout << "3. Update Stock\n";
    std::cout << "4. Check Stock Alerts\n";
    std::cout << "5. Save Data\n";
    std::cout << "6. Load Data\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    InventoryManager manager;
    manager.loadFromFile("data/inventory.json");
    
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        try {
            switch(choice) {
                case 1: {
                    std::string id, name;
                    int qty, minStock;
                    
                    std::cout << "Enter ID: ";
                    std::getline(std::cin, id);
                    std::cout << "Enter Name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter Quantity: ";
                    std::cin >> qty;
                    std::cout << "Enter Min Stock: ";
                    std::cin >> minStock;
                    std::cin.ignore();
                    
                    auto item = std::make_shared<InventoryItem>(id, name, qty, minStock);
                    manager.addItem(item);
                    break;
                }
                case 2:
                    manager.displayAllItems();
                    break;
                case 3: {
                    std::string id;
                    int qty;
                    
                    std::cout << "Enter Item ID: ";
                    std::getline(std::cin, id);
                    std::cout << "Enter New Quantity: ";
                    std::cin >> qty;
                    std::cin.ignore();
                    
                    manager.updateStock(id, qty);
                    break;
                }
                case 4:
                    manager.checkStockLevels();
                    break;
                case 5:
                    manager.saveToFile("data/inventory.json");
                    std::cout << "Data saved successfully!\n";
                    break;
                case 6:
                    manager.loadFromFile("data/inventory.json");
                    std::cout << "Data loaded successfully!\n";
                    break;
                case 0:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice!\n";
            }
        } catch(const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    } while(choice != 0);
    
    return 0;
}