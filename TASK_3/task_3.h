#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

enum class Type {
    CREATE_PLANE,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES,
    EXIT,
    UNKNOWN
};

// Функция преобразования строки в enum
Type parse_type(const std::string& s);

// Логические функции
void create_plane(std::map<std::string, std::vector<std::string>>& db, const std::string& name, const std::vector<std::string>& route);

void planes_for_town(const std::map<std::string, std::vector<std::string>>& db, const std::string& town);

void towns_for_plane(const std::map<std::string, std::vector<std::string>>& db, const std::string& plane);

void print_all(const std::map<std::string, std::vector<std::string>>& db);
