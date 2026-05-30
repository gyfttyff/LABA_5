#include "task_1.h"
#include <vector>
#include <limits>
#include <string>

int main() {
    std::map<std::string, std::pair<std::string, int>> warehouse;
    init_warehouse(warehouse);

    std::string command;
    const std::vector<std::string> valid_commands = {"ADD", "REMOVE", "INFO", "EXIT"};

    while (true) {
        std::cout << "Введите команду (ADD, REMOVE, INFO, EXIT)>>> " << std::flush;
        std::cin >> command;

        bool is_valid = false;
        for (const auto& cmd : valid_commands) {
            if (cmd == command) {
                is_valid = true;
                break;
            }
        }
        
        if (!is_valid){
            std::cout << "Введите корректную команду! \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
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
