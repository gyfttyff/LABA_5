#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

// Инициализация склада по варианту 9: 1 зона (A), 19 стеллажей, 5 секций, 3 полки
void init_warehouse(std::map<std::string, std::pair<std::string, int>>& warehouse);

// Добавление товара
void add_item(std::map<std::string, std::pair<std::string, int>>& warehouse, const std::string& name, int quantity, const std::string& address);

// Удаление товара
void remove_item(std::map<std::string, std::pair<std::string, int>>& warehouse, const std::string& name, int quantity, const std::string& address);

// Вывод состояния склада
void print_info(const std::map<std::string, std::pair<std::string, int>>& warehouse);