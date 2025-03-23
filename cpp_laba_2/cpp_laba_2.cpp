#include <iostream>
using namespace std;

class Counter {
    unsigned range; //диапазон значений
    unsigned value; //значение

public:
    Counter(unsigned ran = 0, unsigned val = 0) {
        setRange(ran);
        setValue(val);
    }
    
    void setRange(unsigned range) { this->range = range; }
    void setValue(unsigned value) {
        if (value > range) {
            this->value = value % range - 1;
        }
        else {
            this->value = value;
        } 
    }

    //ввод начальных значений счетчика
    void enter() {
        int r, v;
        cout << "Введите диапазон значений для счетчика: ";
        cin >> r;
        setRange(r);
        cout << "Введите начальное значение счетчика: ";
        cin >> v;
        setValue(v);
    }

    //увеличение счетчика на n
    void incrCounter() {
        int n;
        cout << "Счетчик увеличится на: ";
        cin >> n;
        setValue(value + n);
    }

    //печать текущего значения
    void printValue() const {
        cout << "Текущее значение счетчика: " << value << endl;
    }

    //менюшка
    void menu() {
        while (1) {
            int n;
            cout << "Увеличить счетчик? 1 - да, 2 - нет" << endl;
            while (!(cin >> n) || n<1 || n>2) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неправильное значение, попробуйте снова: ";
            }
            if (n == 1) {
                incrCounter();
                printValue();
            }
            else {
                printValue();
                cout << "До свидания!" << endl;
                break;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Counter counter;
    counter.enter();
    counter.menu();
}