#include "task_3.h"

Type parse_type(const std::string& s) {
    if (s == "CREATE_PLANE") return Type::CREATE_PLANE;
    if (s == "PLANES_FOR_TOWN") return Type::PLANES_FOR_TOWN;
    if (s == "TOWNS_FOR_PLANE") return Type::TOWNS_FOR_PLANE;
    if (s == "PLANES") return Type::PLANES;
    if (s == "EXIT") return Type::EXIT;
    return Type::UNKNOWN;
}

void create_plane(std::map<std::string, std::vector<std::string>>& db, const std::string& name, const std::vector<std::string>& route) {
    // Проверка на дубликат самолета
    if (db.find(name) != db.end()) {
        std::cout << "Ошибка: Самолет " << name << " уже создан\n";
        return;
    }

    // Проверка количества городов (должно быть >= 2)
    if (route.size() < 2) {
        std::cout << "Ошибка: Самолет не может быть создан с менее чем 2 городами\n";
        return;
    }

    // Проверка на дубликаты городов в маршруте
    std::set<std::string> unique(route.begin(), route.end());
    if (unique.size() != route.size()) {
        std::cout << "Ошибка: Самолет не может быть создан с повторяющимися городами\n";
        return;
    }

    // Если всё ок 
    db[name] = route;
    std::cout << "Самолет " << name << " создан\n";
}

void planes_for_town(const std::map<std::string, std::vector<std::string>>& db, 
                     const std::string& town) {
    std::vector<std::string> found_planes;
    
    // Ищем, у кого в маршруте есть этот город
    for (const auto& [plane, route] : db) {
        for (const auto& t : route) {
            if (t == town) {
                found_planes.push_back(plane);
                break; // Город найден, переходим к следующему самолету
            }
        }
    }

    if (found_planes.empty()) {
        std::cout << "Ошибка: Город " << town << " не найден\n";
    } else {
        std::cout << "Самолеты через " << town << ": ";
        for (const auto& p : found_planes) std::cout << p << ", ";
        std::cout << "\n";
    }
}

void towns_for_plane(const std::map<std::string, std::vector<std::string>>& db, 
                     const std::string& plane) {
    // Проверяем, существует ли самолет
    if (db.find(plane) == db.end()) {
        std::cout << "Ошибка: Самолет " << plane << " не найден\n";
        return;
    }

    std::cout << "Города самолета " << plane << ":\n";
    const std::vector<std::string>& route = db.at(plane);

    for (const auto& town : route) {
        std::cout << town << ": ";
        std::vector<std::string> other_planes;
        
        // Ищем другие самолеты, летящие через этот город
        for (const auto& [p, r] : db) {
            if (p == plane) continue; // Пропускаем самого себя
            
            for (const auto& t : r) {
                if (t == town) {
                    other_planes.push_back(p);
                    break;
                }
            }
        }

        if (other_planes.empty()) std::cout << "-";
        else {
            bool first = true;
            for (const auto& otpl : other_planes) {
                if (!first) std::cout << ", ";
                std::cout << otpl;
                first = false;
            }
        }
        std::cout << "\n";
    }
}

void print_all(const std::map<std::string, std::vector<std::string>>& db) {
    if (db.empty()) {
        std::cout << "Ошибка: Самолеты не найдены\n";
        return;
    }
    for (const auto& [plane, route] : db) {
        std::cout << "Самолет " << plane << ": ";
        for (const auto& t : route) std::cout << t << " ";
        std::cout << "\n";
    }
}
