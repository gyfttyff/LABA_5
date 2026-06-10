#include "task_4.h"
#include <vector>
#include <string>
#include <limits>

int main() {
    std::map<int, std::vector<std::string>> schedule;
    int current_month = 1;
    std::string cmd;
    const std::vector<std::string> valid = {"CLASS", "NEXT", "VIEW", "EXIT"};
    while (true) {
        std::cout << ">>> ";
        if (!(std::cin >> cmd)) break;
        bool ok = false;
        for (const auto& v : valid) if (v == cmd) { ok = true; break; }
        if (!ok) { std::cout << "Неверная команда\n"; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); continue; }
        Cmd c = parse_cmd(cmd);
        if (c == Cmd::EXIT) break;
        if (c == Cmd::CLASS) { int d; std::string s; std::cin >> d >> s; add_class(schedule, d, s); }
        else if (c == Cmd::NEXT) next_month(schedule, current_month);
        else if (c == Cmd::VIEW) { int d; std::cin >> d; view_day(schedule, d); }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}