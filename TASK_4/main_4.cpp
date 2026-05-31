#include "task_4.h"
#include <vector>
#include <string>
#include <limits>


int main() {
    // Расписание: день список дисциплин
    std::map<int, std::vector<std::string>> schedule;
    
    // Текущий месяц (начинаем с января = 1)
    int current_month = 1;
    
    std::string input_cmd;
    const std::vector<std::string> valid = {"CLASS", "NEXT", "VIEW", "EXIT"};

    while (true) {
        std::cout << "Введите команду (CLASS, NEXT, VIEW, EXIT)>>> ";

        // Валидация команды
        bool is_valid = false;
        for (const auto& cmd : valid) {
            if (cmd == input_cmd) { is_valid = true; break; }
        }

        if (!is_valid) {
            std::cout << "Введите корректную команду\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        Cmd cmd = parse_cmd(input_cmd);
        if (cmd == Cmd::EXIT) break;

        if (cmd == Cmd::CLASS) {
            int day;
            std::string subject;
            std::cin >> day >> subject;
            add_class(schedule, day, subject);
        } 
        else if (cmd == Cmd::NEXT) {
            next_month(schedule, current_month);
        } 
        else if (cmd == Cmd::VIEW) {
            int day;
            std::cin >> day;
            view_day(schedule, day);
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}