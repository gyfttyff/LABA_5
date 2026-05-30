#include "task_1.h"
#include <vector>
#include <string>

int main() {
    std::map<std::string, std::pair<std::string, int>> warehouse;
    init_warehouse(warehouse);

    std::string command;
    const std::vector<std::string> valid_commands = {"ADD", "REMOVE", "INFO", "EXIT"};

    while (command == "ADD" || command == "REMOVE" || command == "INFO") {
        std::cout << ">>> ";
        std::cin >> command;

        bool is_valid = false;
        for (const auto& cmd : valid_commands) {
            if (cmd == command) {
                is_valid = true;
                break;
            }
        }
        if (!is_valid) continue;
        if (command == "EXIT") break;

        if (command == "ADD") {
            std::string name, address;
            int quantity;
            std::cin >> name >> quantity >> address;
            add_item(warehouse, name, quantity, address);
        } 
        else if (command == "REMOVE") {
            std::string name, address;
            int quantity;
            std::cin >> name >> quantity >> address;
            remove_item(warehouse, name, quantity, address);
        } 
        else if (command == "INFO") {
            print_info(warehouse);
        }
    }
    return 0;
}