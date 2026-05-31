#include "task_4.h"

Cmd parse_cmd(const std::string& s) {
    if (s == "CLASS") return Cmd::CLASS;
    if (s == "NEXT") return Cmd::NEXT;
    if (s == "VIEW") return Cmd::VIEW;
    if (s == "EXIT") return Cmd::EXIT;
    return Cmd::UNKNOWN;
}

int get_days_in_month(int month) {
    switch (month) {
        case 2:  return 28; // Февраль
        case 4:  return 30; // Апрель
        case 6:  return 30; // Июнь
        case 8:  return 30; // Август
        case 10: return 30; // Октябрь
        case 12: return 30; // Декабрь
        default: return 31; // Остальные (31 день)
    }
}

void add_class(std::map<int, std::vector<std::string>>& schedule, int day, const std::string& subject) {
   
    if (day < 1 || day > 31) {
        std::cout << "Ошибка: Неверный день (должен быть 1-31)\n";
        return;
    }
    
    // Добавляем предмет в день
    schedule[day].push_back(subject);
    std::cout << "Добавлена дисциплина " << subject << " на день " << day << "\n";
}

void next_month(std::map<int, std::vector<std::string>>& schedule, int& current_month) {
    // Переход на следующий месяц
    current_month++;
    if (current_month > 12) {
        current_month = 1; // Новый год
    }
    
    int daysmon = get_days_in_month(current_month);
    std::cout << "Переход на месяц " << current_month 
              << " (дней: " << daysmon << ")\n";
    
    // Создаем новое расписание для следующего месяца
    std::map<int, std::vector<std::string>> new_schedule;
    
    for (const auto& [day, subjects] : schedule) {
        int new_day = day;
        
        // Если день выходит за пределы нового месяца → переносим на последний день
        if (day > daysmon) {
            new_day = daysmon;
            std::cout << "День " << day << " перенесен на " << new_day << "\n";
        }
        
        // Копируем все предметы в новый день
        for (const auto& subject : subjects) {
            new_schedule[new_day].push_back(subject);
        }
    }
    
    // Заменяем старое расписание новым
    schedule = new_schedule;
}

void view_day(const std::map<int, std::vector<std::string>>& schedule, int day) {
    // Проверяем, есть ли записи на этот день
    auto it = schedule.find(day);
    
    if (schedule.find(day) == schedule.end() || it->second.empty()) {
        std::cout << "В день " << day << " мы свободны!\n";
        return;
    }
    
    // Выводим все дисциплины дня
    std::cout << "В день " << day << " занятия в университете: ";
    bool first = true;
    for (const auto& subject : it->second) {
        if (!first) std::cout << ", ";
        std::cout << subject;
        first = false;
    }
    std::cout << "\n";
}