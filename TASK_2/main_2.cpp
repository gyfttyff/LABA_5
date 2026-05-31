#include "task_2.h"
#include <vector>
#include <string>
#include <limits>

int main() {
    int max_stack_weight, sections_count;
    
    std::cout << "Введите максимальный размер стека: >>> ";
    std::cin >> max_stack_weight;
    
    std::cout << "Введите количество секций судна: >>> ";
    std::cin >> sections_count;
    
    // Используем pair<id, weight>
    std::vector<std::vector<std::pair<std::string, int>>> stacks;
    std::vector<int> stack_weights;
    
    std::string command;
    const std::vector<std::string> valid_commands = {"ARRIVE", "LOAD", "EXIT"};
    
    while (true) {
        std::cout << "Введите команду (ARRIVE, LOAD, EXIT)>>> ";
        if (!(std::cin >> command)) break;
        
        
        // Валидация команды
        bool is_valid = false;
        for (const auto& cmd : valid_commands) {
            if (cmd == command) {
                is_valid = true;
                break;
            }
        }
        
        if (!is_valid) {
            std::cout << "Введите корректную команду (ARRIVE, LOAD, EXIT)!\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        if (command == "EXIT") break;
        
        if (command == "ARRIVE") {
            std::string id;
            int weight;
            if (!(std::cin >> id >> weight)) {
                std::cout << "Ошибка формата. Введите: ARRIVE <id> <вес>\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            process_arrive(stacks, stack_weights, max_stack_weight, id, weight);
        } 
        else if (command == "LOAD") {
            process_load(stacks, sections_count);
        }
        
        // Очищаем остаток строки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    return 0;
}
