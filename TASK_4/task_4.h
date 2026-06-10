#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

enum class Cmd { CLASS, NEXT, VIEW, EXIT, UNKNOWN };

Cmd parse_cmd(const std::string& s);
int get_days_in_month(int month);
void add_class(std::map<int, std::vector<std::string>>& schedule, int day, const std::string& subject);
void next_month(std::map<int, std::vector<std::string>>& schedule, int& current_month);
void view_day(const std::map<int, std::vector<std::string>>& schedule, int day);