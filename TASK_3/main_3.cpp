#include "task_3.h"
#include <vector>
#include <string>
#include <limits>

int main() {
    std::map<std::string, Plane> db;
    std::string input;
    const std::vector<std::string> valid = {"CREATE_PLANE", "PLANES_FOR_TOWN", "TOWNS_FOR_PLANE", "PLANES", "EXIT"};
    while (true) {
        std::cout << ">>> ";
        if (!(std::cin >> input)) break;
        bool ok = false;
        for (const auto& cmd : valid) if (cmd == input) { ok = true; break; }
        if (!ok) { std::cout << "Неверная команда\n"; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); continue; }
        Type cmd = parse_type(input);
        if (cmd == Type::EXIT) break;
        if (cmd == Type::CREATE_PLANE) {
            std::string name; int n; std::cin >> name >> n;
            std::vector<std::string> route(n); for (auto& town : route) std::cin >> town;
            create_plane(db, name, route);
        } 
        else if (cmd == Type::PLANES_FOR_TOWN) { std::string t; std::cin >> t; planes_for_town(db, t); } 
        else if (cmd == Type::TOWNS_FOR_PLANE) { std::string p; std::cin >> p; towns_for_plane(db, p); } 
        else if (cmd == Type::PLANES) print_all(db);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}