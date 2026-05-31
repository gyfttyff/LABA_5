#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>

// Обработка прибытия контейнера
void process_arrive(std::vector<std::vector<std::pair<std::string, int>>>& stacks, std::vector<int>& stack_weights, int max_weight, const std::string& id, int weight);

// Погрузка на судно
void process_load(const std::vector<std::vector<std::pair<std::string, int>>>& stacks, int sections_count);
