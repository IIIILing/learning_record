#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int height = 20, width = 20;  // 设置游戏界面的高度和宽度
int gameOver;  // 游戏结束标志?0表示游戏未结束，1表示游戏结束?
int x, y, fruitX, fruitY, score;  // 蛇头位置、食物位置、分�?
int tailX[100], tailY[100];  // 蛇身位置数组
int nTail;  // 蛇身长度
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };  // 控制方向的枚举类型?
enum eDirection dir;  // 当前方向

void Setup() {
    gameOver = 0;  // 初始化游戏未结束
    dir = STOP;  // 初始化方向为静止
    x = width / 2;  // 蛇头初始位置为宽度的一半?
    y = height / 2;  // 蛇头初始位置为高度的一半?
    fruitX = rand() % width;  // 随机设置食物初始位置X坐标
    fruitY = rand() % height;  // 随机设置食物初始位置Y坐标
    score = 0;  // 初始化分数为0
}

void Draw() {
    system("cls");  // 清空屏幕
    for (int i = 0; i < width + 2; i++)  // 打印上边?
        printf("#");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)  // 打印左边?
                printf("#");
            if (i == y && j == x)  // 如果位置是蛇头则打印"O"
                printf("O");
            else if (i == fruitY && j == fruitX)  // 如果位置是食物则打印"*"
                printf("*");
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {  // 循环打印蛇身
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print)  // 如果不是蛇身则打印空格?
                    printf(" ");
            }

            if (j == width - 1)  // 打印右边?
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++)  // 打印下边?
        printf("#");
    printf("\n");
    printf("Score:%d", score);  // 打印分数
}

void Input() {
    if (_kbhit()) {  // 判断键盘是否有输入?
        switch (_getch()) {  // 获取键盘输入
        case 'a':  // 左移
            dir = LEFT;
            break;
        case 'd':  // 右移
            dir = RIGHT;
            break;
        case 'w':  // 上移
            dir = UP;
            break;
        case 's':  // 下移
            dir = DOWN;
            break;
        case 'x':  // 游戏结束
            gameOver = 1;
            break;
        }
    }
}

void Algorithm() {
    // 更新蛇身位置
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // 根据用户输入更新蛇头位置
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // 处理蛇越界情�?
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // 判断蛇是否撞到自身?
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    
    // 处理吃到食物的情况?
    if (x == fruitX && y == fruitY) {
        score += 10;  // 分数增加
        fruitX = rand() % width;  // 食物位置随机更新
        fruitY = rand() % height;
        nTail++;  // 蛇身长度增加
    }
}

// 游戏主函�?
int main() {
    Setup();  // 初始化游戏?
    while (!gameOver) {  // 游戏未结束循环?
        Draw();  // 绘制游戏界面
        Input();  // 获取用户输入
        Algorithm();  // 更新游戏逻辑
        Sleep(150);  // 使游戏休眠一段时间?
    }
    return 0;
}