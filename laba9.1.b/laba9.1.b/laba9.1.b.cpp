#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { КН, ІТ, ПЗ, ВП, СА };

string strSpecialty[] = { "КН","ІТ","ПЗ","ВП","СА" };

struct Student
{
    string prizv;
    Specialty specialty;
    short unsigned kurs;
    short unsigned physics;
    short unsigned math;
    short unsigned informatics;
};

void create(Student* s, const int N);
void print(Student* s, const int N);
double average_mark(Student& s);
void print_average_marks(Student* s, const int N);
double physics_five_four(Student* s, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;
    Student* s = new Student[N];
    create(s, N);
    print(s, N);
    print_average_marks(s, N);
    cout << "| Процент студентів які отримали з фізики " << char(34) << "4" << char(34) << " або " << char(34) << "5" << char(34) << ": " << fixed << setw(6) << setprecision(2) << physics_five_four(s, N) << "%" << setw(18) << "|" << endl;
    cout << "================================================================================" << endl;
    delete[] s;
}

void create(Student* s, const int N)
{
    int kurs, specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент№ " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << "  прізвище: "; getline(cin, s[i].prizv);
        cout << "  курс: "; cin >> s[i].kurs;
        cout << "  спеціальність (0 - КН, 1 - ІТ, 2 - ПЗ, 3 - ВП, 4 - СА): "; cin >> specialty;
        s[i].specialty = (Specialty)specialty;
        cout << "  оцінка з фізики: "; cin >> s[i].physics;
        cout << "  оцінка з математики: "; cin >> s[i].math;
        cout << "  оцінка з інформатики: "; cin >> s[i].informatics;
    }
}

void print(Student* s, const int N)
{
    cout << "================================================================================"
        << endl;
    cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Інформатика |"
        << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << "  "
            << "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
            << "| " << setw(4) << right << s[i].physics << "   "
            << "| " << setw(6) << right << s[i].math << "      "
            << "| " << setw(6) << right << s[i].informatics << "     |" << endl;
    }
    cout << "================================================================================" << endl;
}

double average_mark(Student& s)
{
    return (s.physics + s.math + s.informatics) / 3.;
}

void print_average_marks(Student* s, const int N)
{
    cout << "| Середні оцінки: " << setw(62) << "|" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|    " << i + 1 << ") " << setw(10) << left << s[i].prizv << " - " << setw(4) << left << setprecision(3) << average_mark(s[i]) << right << setw(56) << " | " << endl;
    }
}

double physics_five_four(Student* s, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (s[i].physics == 4 || s[i].physics == 5)
            k++;
    return 100.0 * k / N;
}