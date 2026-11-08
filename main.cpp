#include <iostream>
#include <string>
#include <vector>

struct Student {
    int roll;
    std::string name;
    double marks;
};

int main() {
    std::vector<Student> students;
    int choice = 0;

    do {
        std::cout << "\n1. Add student\n2. List students\n3. Exit\nChoice: ";
        if (!(std::cin >> choice)) {
            std::cerr << "Invalid input.\n";
            return 1;
        }

        if (choice == 1) {
            Student s{};
            std::cout << "Roll number: ";
            std::cin >> s.roll;
            std::cin.ignore();
            std::cout << "Name: ";
            std::getline(std::cin, s.name);
            std::cout << "Marks: ";
            std::cin >> s.marks;
            students.push_back(s);
            std::cout << "Record added (currently stored in memory).\n";
        } else if (choice == 2) {
            for (const auto& s : students) {
                std::cout << s.roll << " | " << s.name << " | " << s.marks << '\n';
            }
            if (students.empty()) std::cout << "No records yet.\n";
        } else if (choice != 3) {
            std::cout << "Choose 1, 2 or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
