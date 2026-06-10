#include "task_3.h"

Type parse_type(const std::string& s) {
    if (s == "CREATE_PLANE") return Type::CREATE_PLANE;
    if (s == "PLANES_FOR_TOWN") return Type::PLANES_FOR_TOWN;
    if (s == "TOWNS_FOR_PLANE") return Type::TOWNS_FOR_PLANE;
    if (s == "PLANES") return Type::PLANES;
    if (s == "EXIT") return Type::EXIT;
    return Type::UNKNOWN;
}

void create_plane(std::map<std::string, Plane>& db, const std::string& name, const std::vector<std::string>& route) {
    if (db.find(name) != db.end()) { std::cout << "Ошибка: Самолет уже создан\n"; return; }
    if (route.size() < 2) { std::cout << "Ошибка: Минимум 2 города\n"; return; }
    std::set<std::string> unique(route.begin(), route.end());
    if (unique.size() != route.size()) { std::cout << "Ошибка: Повторяющиеся города\n"; return; }
    db[name] = {route};
    std::cout << "Самолет " << name << " создан\n";
}

void planes_for_town(const std::map<std::string, Plane>& db, const std::string& town) {
    std::vector<std::string> found;
    for (const auto& [plane_name, plane] : db) {
        for (const auto& t : plane.route) {
            if (t == town) { found.push_back(plane_name); break; }
        }
    }
    if (found.empty()) std::cout << "Ошибка: Город не найден\n";
    else {
        std::cout << "Самолеты через " << town << ": ";
        bool first = true;
        for (const auto& p : found) { if (!first) std::cout << ", "; std::cout << p; first = false; }
        std::cout << "\n";
    }
}

void towns_for_plane(const std::map<std::string, Plane>& db, const std::string& plane_name) {
    if (db.find(plane_name) == db.end()) { std::cout << "Ошибка: Самолет не найден\n"; return; }
    const std::vector<std::string>& route = db.at(plane_name).route;
    std::cout << "Города самолета " << plane_name << ": ";
    bool first = true;
    for (const auto& town : route) { if (!first) std::cout << " "; std::cout << town; first = false; }
    std::cout << "\n";
    for (const auto& town : route) {
        std::cout << town << ": ";
        std::vector<std::string> others;
        for (const auto& [p_name, p_data] : db) {
            if (p_name == plane_name) continue;
            for (const auto& t : p_data.route) { if (t == town) { others.push_back(p_name); break; } }
        }
        if (others.empty()) std::cout << "-";
        else { bool f = true; for (const auto& o : others) { if (!f) std::cout << ", "; std::cout << o; f = false; } }
        std::cout << "\n";
    }
}

void print_all(const std::map<std::string, Plane>& db) {
    if (db.empty()) { std::cout << "Ошибка: Самолеты не найдены\n"; return; }
    for (const auto& [plane_name, plane] : db) {
        std::cout << "Самолет " << plane_name << ": ";
        bool first = true;
        for (const auto& t : plane.route) { if (!first) std::cout << " "; std::cout << t; first = false; }
        std::cout << "\n";
    }
}