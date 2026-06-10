#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

// Структура для хранения данных ячейки (вместо pair)
struct Cell {
    std::string product;
    int quantity;
};

void init_warehouse(std::map<std::string, Cell>& warehouse);
void add_item(std::map<std::string, Cell>& warehouse, const std::string& name, int quantity, const std::string& address);
void remove_item(std::map<std::string, Cell>& warehouse, const std::string& name, int quantity, const std::string& address);
void print_info(const std::map<std::string, Cell>& warehouse);