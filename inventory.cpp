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
void sortByLevel(vector<Item>& inv) {
    sort(inv.begin(), inv.end(), [](Item& a, Item& b) { return a.level < b.level; });
}

void sortByType(vector<Item>& inv) {
    sort(inv.begin(), inv.end(), [](Item& a, Item& b) { return a.type < b.type; });
}

vector<Item> filterByType(vector<Item> inv, string type) {
    vector<Item> f;
    copy_if(inv.begin(), inv.end(), back_inserter(f), [&type](Item& i) { return i.type == type; });
    return f;
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

int main() {
    vector<Item> inventory;
    setlocale(LC_ALL, "");

    addItem(inventory, "Клинок", "оружие", 8);
    addItem(inventory, "Доспехи", "броня", 6);
    addItem(inventory, "Эликсир", "зелье", 3);
    addItem(inventory, "Арбалет", "оружие", 9);
    addItem(inventory, "Щит", "броня", 7);
    addItem(inventory, "Зелье невидимости", "зелье", 5);

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, type; int level;
            cout << "Название: "; cin.ignore(); getline(cin, name);
            cout << "Тип: "; getline(cin, type);
            cout << "Уровень: "; cin >> level;
            addItem(inventory, name, type, level);
            cout << "Предмет добавлен!\n";
            break;
        }
        case 2: {
            string name;
            cout << "Название для удаления: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << (removeItem(inventory, name) ? "Предмет удалён!\n" : "Предмет не найден!\n");
            break;
        }

        case 3: printInventory(inventory); break;
        case 4: sortByType(inventory); cout << "Отсортировано по типу!\n"; printInventory(inventory); break;
        case 5: sortByLevel(inventory); cout << "Отсортировано по уровню!\n"; printInventory(inventory); break;
        case 6: {
            string type;
            cout << "Тип для фильтрации: "; cin.ignore(); getline(cin, type);
            vector<Item> f = filterByType(inventory, type);
            if (!f.empty()) {
                cout << "Предметы типа '" << type << "':\n";
                printInventory(f);
            }
            else {
                cout << "Нет предметов данного типа!\n";
            }
            break;
        }
        case 7: break;
        default: cout << "Неверный выбор!\n"; break;
        }
    } while (choice != 7);
    return 0;
}
