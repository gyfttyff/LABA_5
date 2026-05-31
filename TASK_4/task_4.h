#pragma once
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>

enum class Cmd {
    CLASS,
    NEXT,
    VIEW,
    EXIT,
    UNKNOWN
};

Cmd parse_cmd(const std::string& s);

// Получить количество дней в месяце (1-12)
int get_days_in_month(int month);

// Добавить дисциплину в день
void add_class(std::map<int, std::vector<std::string>>& schedule,  int day, const std::string& subject);

// Перейти на следующий месяц
void next_month(std::map<int, std::vector<std::string>>& schedule, 
                int& current_month);

// Показать расписание на день
void view_day(const std::map<int, std::vector<std::string>>& schedule, 
              int day);