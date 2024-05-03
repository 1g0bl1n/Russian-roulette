#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функция для определения победителя
void determineWinner(bool playerAlive, bool dealerAlive) {
    if (!playerAlive) {
        cout << "Вы проиграли. Дилер выиграл." << endl;
    } else if (!dealerAlive) {
        cout << "Поздравляем! Вы выиграли!" << endl;
    } else {
        cout << "Игра продолжается..." << endl;
    }
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    bool playerAlive = true;
    bool dealerAlive = true;
    bool barrel[6] = {false, false, false, false, false, true}; // 1 из 6 пуль в барабане

    cout << "Добро пожаловать в игру русскую рулетку!" << endl;

    while (playerAlive && dealerAlive) {
        cout << "Ваш ход. Нажмите Enter, чтобы выстрелить." << endl;
        cin.get(); // Ждем, пока игрок нажмет Enter
        int bulletIndex = rand() % 6; // Случайный выбор пули из барабана
        
        if (barrel[bulletIndex]) {
            playerAlive = false; // Если пуля в барабане, игрок проиграл
        }

        cout << "Ход дилера..." << endl;
        bulletIndex = rand() % 6;
        if (barrel[bulletIndex]) {
            dealerAlive = false; // Если пуля в барабане, дилер проиграл
        }

        determineWinner(playerAlive, dealerAlive); // Определение победителя
    }

    return 0;
}