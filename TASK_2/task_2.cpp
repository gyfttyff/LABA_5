#include "task_2.h"
#include <algorithm>
#include <limits>

void process_arrive(std::vector<std::vector<std::pair<std::string, int>>>& stacks,
                   std::vector<int>& stack_weights,
                   int max_weight,
                   const std::string& id,
                   int weight) {
    
    if (weight > max_weight) {
        std::cout << "Ошибка: Вес контейнера " << id << " (" << weight 
                  << " тонн) превышает максимальный размер стека (" 
                  << max_weight << " тонн)" << std::endl;
        return;
    }
    
    bool placed = false;
    size_t idx = 0;
    
    // Range-based for: ищем первый подходящий стек
    for (auto& stack : stacks) {
        if (stack_weights[idx] + weight <= max_weight) {
            stack.push_back({id, weight});
            stack_weights[idx] += weight;
            std::cout << "Контейнер " << id << " размещен в стек " << (idx + 1) << std::endl;
            placed = true;
            break;
        }
        idx++;
    }
    
    // Если не нашли место - создаем новый стек
    if (!placed) {
        stacks.push_back({{id, weight}});
        stack_weights.push_back(weight);
        std::cout << "Контейнер " << id << " размещен в стек " << stacks.size() << std::endl;
    }
}

void process_load(const std::vector<std::vector<std::pair<std::string, int>>>& stacks,
                 int sections_count) {
    // Создаем секции
    std::vector<std::vector<std::string>> sections(sections_count);
    std::vector<int> section_weights(sections_count, 0);
    
    // Собираем все контейнеры из всех стеков
    std::vector<std::pair<std::string, int>> all_containers;
    for (const auto& stack : stacks) {
        for (const auto& container : stack) {
            all_containers.push_back(container);
        }
    }
    
    // Разворачиваем для LIFO 
    std::reverse(all_containers.begin(), all_containers.end());
    
    // Распределяем по секциям с минимальным весом
    for (const auto& container : all_containers) {
        const std::string& id = container.first;
        int weight = container.second;
        
        // Ищем секцию с минимальным весом (range-based for с индексом)
        size_t best_section = 0;
        size_t current_idx = 0;
        for (int w : section_weights) {
            if (w < section_weights[best_section]) {
                best_section = current_idx;
            }
            current_idx++;
        }
        
        sections[best_section].push_back(id);
        section_weights[best_section] += weight;
    }
    
    // Вывод результата
    size_t s = 0;
    for (const auto& section : sections) {
        std::cout << "Секция " << (s + 1) << " (" << section_weights[s] << " тонн): ";
        bool first = true;
        for (const auto& id : section) {
            if (!first) std::cout << ", ";
            std::cout << id;
            first = false;
        }
        std::cout << std::endl;
        s++;
    }
}
