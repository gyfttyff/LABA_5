#include "task_4.h"

Cmd parse_cmd(const std::string& s) {
    if (s == "CLASS") return Cmd::CLASS;
    if (s == "NEXT") return Cmd::NEXT;
    if (s == "VIEW") return Cmd::VIEW;
    if (s == "EXIT") return Cmd::EXIT;
    return Cmd::UNKNOWN;
}

int get_days_in_month(int month) {
    if (month == 2) return 28;
    if (month == 4 || month == 6 || month == 8 || month == 10 || month == 12) return 30;
    return 31;
}

void add_class(std::map<int, std::vector<std::string>>& schedule, int day, const std::string& subject) {
    if (day < 1 || day > 31) { std::cout << "Ошибка: Неверный день\n"; return; }
    schedule[day].push_back(subject);
    std::cout << "Добавлено: " << subject << " на " << day << "\n";
}

void next_month(std::map<int, std::vector<std::string>>& schedule, int& current_month) {
    current_month++;
    if (current_month > 12) current_month = 1;
    int limit = get_days_in_month(current_month);
    std::map<int, std::vector<std::string>> next_schedule;
    for (const auto& [day, subjects] : schedule) {
        int new_day = (day > limit) ? limit : day;
        for (const auto& subj : subjects) next_schedule[new_day].push_back(subj);
    }
    schedule = next_schedule;
    std::cout << "Месяц " << current_month << " (дней: " << limit << ")\n";
}

void view_day(const std::map<int, std::vector<std::string>>& schedule, int day) {
    auto it = schedule.find(day);
    if (it == schedule.end() || it->second.empty()) { std::cout << "День " << day << ": свободно\n"; return; }
    std::cout << "День " << day << ": ";
    bool first = true;
    for (const auto& subj : it->second) { if (!first) std::cout << ", "; std::cout << subj; first = false; }
    std::cout << "\n";
}
