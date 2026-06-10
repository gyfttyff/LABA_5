#include "task_1.h"
#include <sstream>

void init_warehouse(std::map<std::string, Cell>& warehouse) {
    // Вариант 9: 1 зона (A), 19 стеллажей, 5 секций, 3 полки
    // Инициализируем векторы значениями для использования range-based for
    char zones = 'A';
    
    const int sh = 19; 
    const int sec = 5;
    const int rows = 3; 
     
    /*std::vector<int> shelves (19);
    for (size_t i = 0; i < shelves.size(); ++i){
    	shelves[i] = i;
    }
    
    std::vector<int> sections (5);
     for (size_t i = 0; i < section.size(); ++i){
    	section[i] = i;
    }
    
    std::vector<int> rows = (3);
     for (size_t i = 0; i < rows.size(); ++i){
    	rows[i] = i;
    }*/
    
    // Range-based for loop 
    for ( int i = 0; i < sh*sec*rows; ++i) {
    	warehouse.push_back({"", 0})
    }
    
    
    
    
        /*for (auto sh : shelves) {
            for (auto sec : sections) {
                for (auto r : rows) {
                    std::ostringstream oss;
                    oss << z << std::setw(2) << std::setfill('0') << sh << sec << r;
                    warehouse[oss.str()] = {"", 0};
                }
            }
        }
    }*/
}

void add_item(std::map<std::string, Cell>& warehouse, const std::string& name, int quantity, const std::string& address) {
    if (warehouse.find(address) == warehouse.end()) {
        std::cout << "Ошибка: Ячейка " << address << " не существует\n";
        return;
    }
    Cell& item = warehouse[address]; // Работа со структурой
    if (!item.product.empty() && item.product != name) {
        std::cout << "Ошибка: Ячейка " << address << " занята товаром " << item.product << "\n";
        return;
    }
    if (item.quantity + quantity > 10) {
        std::cout << "Ошибка: Превышена вместимость ячейки (максимум 10)\n";
        return;
    }
    item.product = name;
    item.quantity += quantity;
    std::cout << "Добавлено " << quantity << " " << name << " в " << address << "\n";
}

void remove_item(std::map<std::string, Cell>& warehouse, const std::string& name, int quantity, const std::string& address) {
    if (warehouse.find(address) == warehouse.end()) {
        std::cout << "Ошибка: Ячейка " << address << " не существует\n";
        return;
    }
    Cell& item = warehouse[address];
    if (item.product.empty() || item.product != name) {
        std::cout << "Ошибка: Товар " << name << " не найден в ячейке " << address << "\n";
        return;
    }
    if (item.quantity < quantity) {
        std::cout << "Ошибка: Недостаточно товаров для удаления\n";
        return;
    }
    item.quantity -= quantity;
    std::cout << "Удалено " << quantity << " " << name << " (остаток: " << item.quantity << ")\n";
    if (item.quantity == 0) item.product = "";
}

void print_info(const std::map<std::string, Cell>& warehouse) {
    int occupied_units = 0;
    
    const int sh = 19; 
    const int sec = 5;
    const int rows = 3;
    const int all = sh*sec*rows;
    
    std::vector<std::string> empty_cells;

    // Range-based for loop
    for (const auto& [addr, item] : warehouse) {
        if (!item.product.empty()) {
            occupied_units += item.quantity;
        } else {
            empty_cells.push_back(addr);
        }
    }

    double load_percent = (occupied_units / all) * 100.0; // Вариант 9: 2850

    std::cout << "\nСостояние склада:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Загруженность склада: " << load_percent << "%\n";
    std::cout << "Загруженность зоны А: " << load_percent << "%\n";

    std::cout << "Заполненные ячейки:\n";
    bool has_items = false;
    for (const auto& [addr, item] : warehouse) {
        if (!item.product.empty()) {
            std::cout << addr << ": " << item.product << " (" << item.quantity << ")\n";
            has_items = true;
        }
    }
    if (!has_items) std::cout << " (нет)\n";

    std::cout << "Пустые ячейки:\n";
    if (empty_cells.empty()) {
        std::cout << " (нет)\n";
    } else {
        bool first = true;
        for (const auto& addr : empty_cells) {
            if (!first) std::cout << ", ";
            std::cout << addr;
            first = false;
        }
        std::cout << "\n";
    }
}
