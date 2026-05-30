#include "task_1.h"
#include <sstream>

void init_warehouse(std::map<std::string, std::pair<std::string, int>>& warehouse) {
    std::vector<int> shelves, sections, rows;
    for (int i = 1; i <= 19; ++i) shelves.push_back(i);
    for (int i = 1; i <= 5; ++i) sections.push_back(i);
    for (int i = 1; i <= 3; ++i) rows.push_back(i);

    for (auto sh : shelves)
        for (auto sec : sections)
            for (auto r : rows) {
                std::ostringstream oss;
                oss << 'A' << std::setw(2) << std::setfill('0') << sh << sec << r;
                warehouse[oss.str()] = {"", 0};
            }
}

void add_item(std::map<std::string, std::pair<std::string, int>>& warehouse, const std::string& name, int quantity, const std::string& address) {
    if (warehouse.find(address) == warehouse.end()) {
        std::cout << "Ошибка: Ячейка " << address << " не существует\n";
        return;
    }
    auto& add = warehouse[address];
    if (!add.first.empty() && add.first != name) {
        std::cout << "Ошибка: Ячейка " << address << " занята товаром " << add.first << "\n";
        return;
    }
    if (add.second + quantity > 10) {
        std::cout << "Ошибка: Превышена вместимость ячейки (максимум 10)\n";
        return;
    }
    add.first = name;
    add.second += quantity;
    std::cout << "Добавлено " << quantity << " " << name << " в " << address << "\n";
}

void remove_item(std::map<std::string, std::pair<std::string, int>>& warehouse, const std::string& name, int quantity, const std::string& address) {
    if (warehouse.find(address) == warehouse.end()) {
        std::cout << "Ошибка: Ячейка " << address << " не существует\n";
        return;
    }
    auto& remove = warehouse[address];
    if (remove.first.empty() || remove.first != name) {
        std::cout << "Ошибка: Товар " << name << " не найден в ячейке " << address << "\n";
        return;
    }
    if (remove.second < quantity) {
        std::cout << "Ошибка: Недостаточно товаров для удаления\n";
        return;
    }
    remove.second -= quantity;
    std::cout << "Удалено " << quantity << " " << name << " (остаток: " << remove.second << ")\n";
    if (remove.second == 0) remove.first = "";
}

void print_info(const std::map<std::string, std::pair<std::string, int>>& warehouse) {
    int occupied_units = 0;
    std::vector<std::string> empty_cells;

    for (const auto& [addr, item] : warehouse) {
        if (!item.first.empty()) {
            occupied_units += item.second;
        } else {
            empty_cells.push_back(addr);
        }
    }

    double load_percent = (occupied_units / 2850.0) * 100.0;

    std::cout << "\n Состояние склада:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Загруженность склада: " << load_percent << "%\n";
    std::cout << "Загруженность зоны А: " << load_percent << "%\n";

    std::cout << "Заполненные ячейки:\n";
    bool has_items = false;
    for (const auto& [addr, item] : warehouse) {
        if (!item.first.empty()) {
            std::cout << addr << ": " << item.first << " " << item.second << "\n";
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

