#include "task_2.h"

void process_arrive(std::vector<std::vector<std::pair<std::string, int>>>& stacks, std::vector<int>& stack_weights, int max_weight, const std::string& id, int weight) {

    bool placed = false;
    
    // Ищем первый стек, куда поместится контейнер
    for (size_t i = 0; i < stacks.size(); ++i) {
        if (stack_weights[i] + weight <= max_weight) {
            stacks[i].push_back({id, weight});
            stack_weights[i] += weight;
            std::cout << "Контейнер " << id << " размещен в стек " << (i + 1) << "\n";
            placed = true;
            break;
        }
    }
    
    // Если ни один стек не подошёл - создаём новый
    if (!placed) {
        stacks.push_back({{id, weight}});
        stack_weights.push_back(weight);
        std::cout << "Контейнер " << id << " размещен в стек " << stacks.size() << "\n";
    }
}

void process_load(const std::vector<std::vector<std::pair<std::string, int>>>& stacks, int sections_count) {
    // Создаём секции судна (изначально пустые)
    std::vector<std::vector<std::string>> sections(sections_count);
    std::vector<int> section_weights(sections_count, 0);
    
    // Собираем все контейнеры в порядке LIFO
    std::vector<std::pair<std::string, int>> all_containers;
    for (int i = static_cast<int>(stacks.size()) - 1; i >= 0; --i) { //Внешний цикл: идём по стекам с последнего к первому
        for (int j = static_cast<int>(stacks[i].size()) - 1; j >= 0; --j) { // Внутренний цикл: идём по контейнерам в стеке с вершины к основанию
            all_containers.push_back(stacks[i][j]);
        }
    }
    
    // Распределяем контейнеры по секциям
    for (const auto& container : all_containers) {
        const std::string& id = container.first;
        int weight = container.second;
        
        // Находим секцию с минимальным весом
        size_t best_section = 0;
        for (size_t s = 1; s < sections.size(); ++s) {
            if (section_weights[s] < section_weights[best_section]) {
                best_section = s;
            }
        }
        
        // Добавляем контейнер в выбранную секцию
        sections[best_section].push_back(id);
        section_weights[best_section] += weight;
    }
    
    // Вывод результата
    for (size_t s = 0; s < sections.size(); ++s) {
        std::cout << "Секция " << (s + 1) << "(" << section_weights[s] << " тонн): ";
        
        bool first = true;
        for (const auto& id : sections[s]) {
            if (!first) std::cout << ", ";
            std::cout << id;
            first = false;
        }
        std::cout << "\n";
    }

}
