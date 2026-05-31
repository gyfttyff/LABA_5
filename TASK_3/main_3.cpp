#include "task_3.h"
#include <vector>
#include <string>
#include <limits>


int main() {

    std::map<std::string, std::vector<std::string>> database;
    std::string input_cmd;
    
    // Список валидных команд для проверки
    const std::vector<std::string> valid = {"CREATE_PLANE", "PLANES_FOR_TOWN", "TOWNS_FOR_PLANE", "PLANES", "EXIT"};

    while (true) {
        std::cout << "Введите команду (CREATE_PLANE, PLANES_FOR_TOWN, TOWNS_FOR_PLANE, PLANES, EXIT)>>> ";


        // Валидация команды через range-based for
        bool is_valid = false;
        for (const auto& cmd : valid) {
            if (cmd == input_cmd) {
                is_valid = true;
                break;
            }
        }

        if (!is_valid) {
            std::cout << "Введите корректную команду\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Парсим строку в enum
        Type cmd = parse_type(input_cmd);

        // Выход
        if (cmd == Type::EXIT) {
            break;
        }

        if (cmd == Type::CREATE_PLANE) {
            std::string name;
            int n;
            std::cin >> name >> n;
            
            std::vector<std::string> route(n);
            for (auto& town : route) std::cin >> town;
            
            create_plane(database, name, route);
        } 
        else if (cmd == Type::PLANES_FOR_TOWN) {
            std::string town;
            std::cin >> town;
            planes_for_town(database, town);
        } 
        else if (cmd == Type::TOWNS_FOR_PLANE) {
            std::string plane;
            std::cin >> plane;
            towns_for_plane(database, plane);
        } 
        else if (cmd == Type::PLANES) {
            print_all(database);
        }

        // Очищаем буфер ввода
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}