// Copyright 2022 kossmali, lelaanna, giovannb
#include <stdio.h>

void draw(int leftPad, int rightPad, int ballX, int ballY,
          int scoreLeft, int scoreRight);

void ballMove(int leftPad, int rightPad, int ballX, int ballY,
              int scoreLeft, int scoreRight);

void step();

int main() {
    step();
    return 0;
}

void step() {
    int leftPad = 13;  // Центральная координата левой ракетки
    int rightPad = 13;  // Центральная координата правой ракетки
    int ballX = 5, ballY = leftPad;  // Координаты шарика,егоначальное положение
    int ballMoveX = 1;  // Движение по X
    int ballMoveY = 1;  // Движение по Y
    int scoreLeft = 0;  // Счет левого игрока
    int scoreRight = 0;  // Счет праввого игрока


    draw(leftPad, rightPad, ballX, ballY, scoreLeft, scoreRight);
    char key, c;
    while (scoreLeft != 21 && scoreRight != 21) {
        if ((scanf("%c%c", &key, &c) == 2) && (c == '\n')
            && ((key == ' ') || (key == 'z') ||
        (key == 'Z') || (key == 'a') || (key == 'A')
        || (key == 'm') ||(key == 'M') || (key == 'k') || (key == 'K'))) {
// Касание шарика о грани поля
            if (ballY >= 23 || ballY <= 1) {
                ballMoveY *= -1;
            }
// Касание шарика о центр правой ракетки
            if (ballX+1 ==76 && ballY == rightPad) {
                ballMoveX *= -1;
                ballMoveY *= 0;
            }
// Касание шарика о верх правой ракетки
            if (ballX+1 ==76 && ballY == rightPad+1) {
                ballMoveX *= - 1;
                ballMoveY = 1;
            }
// Касание шарика о низ правой ракетки
            if (ballX+1 ==76 && ballY == rightPad-1) {
                ballMoveX *= - 1;
                ballMoveY = -1;
            }
// Касание шарика о центр левой ракетки
            if (ballX-1 ==3 && ballY == leftPad) {
                ballMoveX *= - 1;
                ballMoveY *= 0;
            }
// Касание шарика о верх левой ракетки
            if (ballX-1 ==3 && ballY == leftPad+1) {
                ballMoveX *= - 1;
                ballMoveY = 1;
            }
// Касание шарика о низ левой ракетки
            if (ballX-1 ==3 && ballY == leftPad-1) {
                ballMoveX *= - 1;
                ballMoveY = -1;
            }
// Вылет шарика за правый край
            if (ballX == 76) {
                    scoreLeft +=1;
                    ballX = 75;
                    ballY = rightPad - ballMoveY;
                    ballMoveX *= -1;
            }
// Вылет шарика за левый край
            if (ballX == 3) {
                    scoreRight +=1;
                    ballX = 4;
                    ballY = leftPad - ballMoveY;
                    ballMoveX *= -1;
                }
// Движение шарика каждый шаг
            ballX += ballMoveX;
            ballY += ballMoveY;
                if ((key == 'z') || (key == 'Z')) {
// Проверка положение левой ракетки по высоте
                if (leftPad + 2 == 24) {
                } else {
                    leftPad += 1;  // Свдиг левой ракетки вниз
                }
// Обновление кадра ;)))
                printf("\33c\e[3J");
                draw(leftPad, rightPad, ballX, ballY, scoreLeft, scoreRight);
            } else if ((key == 'a') || (key == 'A')) {
// Проверка положение левой ракетки по высоте
                if (leftPad - 2 == 0) {
                } else {
                    leftPad -= 1;  // Свдиг левой ракетки вверх
                }
                printf("\33c\e[3J");
                draw(leftPad, rightPad, ballX, ballY, scoreLeft, scoreRight);
            } else if ((key == 'm') || (key == 'M')) {
// Проверка положение правой ракетки по высоте
                if (rightPad + 2 == 24) {
                } else {
                    rightPad += 1;  // Свдиг правой ракетки вниз
                }
                printf("\33c\e[3J");
                draw(leftPad, rightPad, ballX, ballY, scoreLeft, scoreRight);
            } else if ((key == 'k') || (key == 'K')) {
// Проверка положение правой ракетки по высоте
                if (rightPad - 2 == 0) {
                } else {
                    rightPad -= 1;  // Свдиг правой ракетки вверх
                }
                printf("\33c\e[3J");
                draw(leftPad, rightPad, ballX, ballY, scoreLeft, scoreRight);
// Ход не двигая ракетку
            } else if (key == ' ') {
                printf("\33c\e[3J");
                draw(leftPad, rightPad, ballX, ballY, scoreLeft, scoreRight);
                }
        } else if (scanf("%c%c", &key, &c) == EOF) {
            break;
            } else {
            printf("\33c\e[3J");
            draw(leftPad, rightPad, ballX, ballY, scoreLeft, scoreRight);
        }
    }
    if (scoreLeft == 21) {
        printf("Left player WIN!!!");
    }
    if (scoreRight == 21) {
        printf("Right player WIN!!!");
    }
}
// Отрисовка поля и объектов
void draw(int leftPad, int rightPad, int ballX,
    int ballY, int scoreLeft, int scoreRight) {
    char ball = 'o';
    char space = ' ';
    char BounceBoarder = '=';
    char FailBoarder = '|';
    char padLeft = ']';
    char padRight = '[';
    printf("%39d:%d\n", scoreLeft, scoreRight);  // Вывод очков игроков
    for (int y = 0; y <= 24; y++) {
        for (int x = 0; x <= 79; x++) {
            if (y == 0 || y == 24) {  // Отрисовка горизонтальных границ поля
                printf("%c", BounceBoarder);
            } else if (x == 0 || x == 79 || x == 39) {
                if (x == ballX && y == ballY) {
                    printf("%c", ball);
                } else {
                    printf("%c", FailBoarder);
                }
            } else if (x == 76 && (y == rightPad ||
                y == rightPad-1 || y == rightPad+1)) {
                printf("%c", padRight);
            } else if (x == 3 && (y == leftPad ||
            y == leftPad-1 || y == leftPad+1)) {
                printf("%c", padLeft);
            } else if (x == ballX && y == ballY) {
                printf("%c", ball);
            } else {
                printf("%c", space);  // Собственно само пространство поля)
            }
        }
        printf("\n");
    }
}
