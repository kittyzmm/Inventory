#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Item {
    string name, type;
    int level;
};

void addItem(vector<Item>& inv, string name, string type, int level) {
    inv.push_back({ name, type, level });
}

bool removeItem(vector<Item>& inv, string name) {
    auto it = find_if(inv.begin(), inv.end(), [&name](Item& i) { return i.name == name; });
    if (it != inv.end()) {
        inv.erase(it);
        return true;
    }
    return false;
}

void printInventory(vector<Item> inv) {
    cout << "\n--- Инвентарь ---\n";
    for (auto& i : inv)
        cout << "Название: " << i.name << ", Тип: " << i.type << ", Уровень: " << i.level << endl;
}

void showMenu() {
    cout << "\n--- Меню инвентаря ---\n"
        << "1. Добавить предмет\n"
        << "2. Удалить предмет по названию\n"
        << "3. Вывести инвентарь\n"
        << "4. Сортировать по типу\n"
        << "5. Сортировать по уровню\n"
        << "6. Фильтрация по типу\n"
        << "7. Выход\n"
        << "Выберите действие (1-7): ";
}
