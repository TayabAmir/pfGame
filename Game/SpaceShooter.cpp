#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
void printHeader();
void printMaze();
void displayMenu();
void displayInstructions();
void Game(int value);
void printEnemy1();
void eraseEnemy1();
void printEnemy2();
void eraseEnemy2();
void printEnemy3();
void eraseEnemy3();
void printPlayer();
void erasePlayer();
void movePlayerRight();
void movePlayerLeft();
void movePlayerUp();
void generateEnemy1Fire();
void moveEnemy1Fire();
void removeEnemy1Fire(int x, int y);
void generateEnemy2Fire();
void moveEnemy2Fire();
void generateEnemy3Fire();
void moveEnemy3Fire();
void movePlayerDown();
void printScore();
void generatePlayerFire();
void movePlayerFire();
void generateRandomFire();
void moveRandomFire();
void removePlayerFire(int x, int y);
void moveEnemy1(string direction);
void moveEnemy2(string direction);
void moveEnemy3(string vdirection);
string changeDirection(string direction);
string changevDirection(string vdirection);
char getCharAtxy(short int x, short int y);
void gotoxy(int x, int y);
void hideCursor();
void setConsoleColor(int color);
bool checkOptionValidation(string input);

int pfX[1000], pfY[1000], pfCount = 0;
bool isPlayerBulletActive[100] = {false};
int efX[1000], efY[1000], efCount = 0;
bool isEnemyBulletActive[1000] = {false};
int efX2[1000], efY2[1000], efCount2 = 0;
bool isEnemyBulletActive2[1000] = {false};
int efX3[1000], efY3[1000], efCount3 = 0;
bool isEnemyBulletActive3[1000] = {false};
int efX_random[1000], efY_random[1000], efCount_random = 0;
bool isEnemyBulletActive_random[1000] = {false};

int ex1 = 4, ey1 = 9;
int ex2 = 70, ey2 = 9;
int ex3 = 45, ey3 = 9;
int px = 47, py = 32;
int fx = 0, fy = 0;
int e1Health = 5, e2Health = 5, e3Health = 5, playerHealth = 10;

int main()
{
    string input;
    int option, gameOption;
    do
    {
        system("cls");
        printHeader();
        displayMenu();
        cin >> input;
        if (checkOptionValidation(input))
        {
            option = stoi(input);
        }
        else
        {
            cout << "Write valid input.";
            Sleep(300);
        }
        if (option == 1)
        {
            do
            {
                system("cls");
                printHeader();
                setConsoleColor(14);
                cout << endl
                     << endl
                     << "Choose the difficulty level.." << endl
                     << endl;
                setConsoleColor(7);
                cout << " 1. Easy " << endl;
                cout << " 2. Medium " << endl;
                cout << " 0. Return to Main Menu" << endl;
                setConsoleColor(14);
                cout << endl
                     << "Choose the option... ";
                cin >> gameOption;
                switch (gameOption)
                {
                case 1:
                    Game(50);
                    gotoxy(113, 15);
                    cout << "Enter any key to go back...";
                    cin >> input;
                    break;
                case 2:
                    Game(1);
                    gotoxy(113, 15);
                    cout << "Enter any key to go back...";
                    cin >> input;
                    break;
                case 0:
                    break;
                default:
                    cout << "Write Correct option.";
                }
            } while (gameOption != 0);
        }
        else if (option == 2)
        {
            displayInstructions();
            cout << endl
                 << "Press any key to go back..";
            getch();
        }
        else if (option == 3)
        {
            cout << endl
                 << "Thanks for playing";
            break;
        }
    } while (option != 3);
}
void printHeader()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\t \t  ____  ____   _    ____ _____   ____  _____ _____ _   _ ____  _____ ____  " << endl;
    cout << "\t \t / ___||  _ \\ / \\  / ___| ____| |  _ \\| ____|  ___| \\ | |  _ \\| ____|  _ \\ " << endl;
    cout << "\t \t \\___ \\| |_) / _ \\| |   |  _|   | | | |  _| | |_  |  \\| | | | |  _| | |_) |" << endl;
    cout << "\t \t  ___) |  __/ ___ \\|___ | |___  | |_| | |___|  _| | |\\  | |_| | |___|  _ < " << endl;
    cout << "\t \t |____/|_| /_/   \\_\\____|_____| |____/|_____|_|   |_| \\_|____/|_____|_| \\_\\" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------  " << endl
         << endl;
}
void setConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
bool checkOptionValidation(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        if (ch < '0' || ch > '9')
        {
            return false;
        }
    }
    return true;
}
void Game(int value)
{

    hideCursor();
    system("cls");
    printHeader();
    printMaze();
    printEnemy1();
    printEnemy2();
    printEnemy3();
    printPlayer();
    string enemyDirection = "right", enemyDirection2 = "right", vdirection = "down";
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generatePlayerFire();
        }
        if (value == 1)
        {
            generateRandomFire();
            moveRandomFire();
        }
        movePlayerFire();
        if (e1Health > 0)
        {
            moveEnemy1(enemyDirection);
            enemyDirection = changeDirection(enemyDirection);
            Sleep(value);
            generateEnemy1Fire();
        }
        else
        {
            eraseEnemy1();
        }
        moveEnemy1Fire();
        if (e2Health > 0)
        {
            moveEnemy2(enemyDirection2);
            enemyDirection2 = changeDirection(enemyDirection2);
            generateEnemy2Fire();
            Sleep(value);
        }
        else
        {
            eraseEnemy2();
        }
        moveEnemy2Fire();
        if (e3Health > 0)
        {
            moveEnemy3(vdirection);
            vdirection = changevDirection(vdirection);
            generateEnemy3Fire();
            Sleep(value);
        }
        else
        {
            eraseEnemy3();
        }
        moveEnemy3Fire();

        printScore();
        if (playerHealth < 0)
        {
            playerHealth = 0;
        }
        if (e1Health < 0)
        {
            e1Health = 0;
        }
        if (e2Health < 0)
        {
            e2Health = 0;
        }
        if (e3Health < 0)
        {
            e3Health = 0;
        }
        if (e1Health == 0 && e2Health == 0 && e3Health == 0)
        {
            ex1 = 4, ey1 = 9, ex2 = 70, ey2 = 9, ex3 = 45, ey3 = 9, px = 47, py = 32, fx = 0, fy = 0, e1Health = 5, e2Health = 5, e3Health = 5, playerHealth = 10, pfCount = 0, efCount = 0, efCount2 = 0, efCount3 = 0;
            gotoxy(115, 14);
            cout << "Game Over! You Win.";
            break;
        }
        else if (playerHealth == 0)
        {
            ex1 = 4, ey1 = 9, ex2 = 70, ey2 = 9, ex3 = 45, ey3 = 9, px = 47, py = 32, fx = 0, fy = 0, e1Health = 5, e2Health = 5, e3Health = 5, playerHealth = 10, pfCount = 0, efCount = 0, efCount2 = 0, efCount3 = 0;
            erasePlayer();
            gotoxy(115, 14);
            cout << "Game Over! You Lose";
            break;
        }
    }
}
void displayMenu()
{
    setConsoleColor(14);
    cout << "1. Start Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Exit" << endl;
    setConsoleColor(11);
    cout << "====================================" << endl
         << endl;
    setConsoleColor(7);
    cout << "Choose the option you want...";
}
void displayInstructions()
{
    system("cls");
    printHeader();
    setConsoleColor(14);
    gotoxy(25, 9);
    cout << "====================================";
    gotoxy(25, 10);
    cout << "           GAME INSTRUCTIONS         ";
    gotoxy(25, 11);
    cout << "====================================";
    setConsoleColor(7);
    gotoxy(25, 13);
    cout << "Use ^ to move up.";
    gotoxy(25, 14);
    cout << "Use > to move right.";
    gotoxy(25, 15);
    cout << "Use < to move left.";
    gotoxy(25, 16);
    cout << "Use v to move down.";
    gotoxy(25, 17);
    cout << "Press the spacebar to shoot.";
    gotoxy(25, 18);
    cout << "Avoid enemy bullets and collision with them";
    gotoxy(25, 19);
    cout << "Survive as long as you can!";
    setConsoleColor(14);
    gotoxy(25, 21);
    cout << "====================================" << endl;
    setConsoleColor(7);
}
string changevDirection(string vdirection)
{
    if (vdirection == "up" && ey3 <= 10)
    {
        vdirection = "down";
    }
    else if (vdirection == "down" && ey3 + 2 >= 23)
    {
        vdirection = "up";
    }
    return vdirection;
}

string changeDirection(string direction)
{
    if (direction == "right" && ex1 >= 38)
    {
        direction = "left";
    }
    if (direction == "left" && ex1 <= 4)
    {
        direction = "right";
    }
    if (direction == "right" && ex2 >= 104)
    {
        direction = "left";
    }
    if (direction == "left" && ex2 <= 52)
    {
        direction = "right";
    }
    return direction;
}
void printEnemy1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    gotoxy(ex1, ey1);
    cout << "___";
    gotoxy(ex1, ey1 + 1);
    cout << "|~|";
    gotoxy(ex1, ey1 + 2);
    cout << ":*:";
}

void eraseEnemy1()
{
    gotoxy(ex1, ey1);
    cout << "   ";
    gotoxy(ex1, ey1 + 1);
    cout << "   ";
    gotoxy(ex1, ey1 + 2);
    cout << "   ";
}
void moveEnemy1(string direction)
{
    if (getCharAtxy(ex1 + 4, ey1) == '/' || getCharAtxy(ex1 + 3, ey1 + 1) == '_' || getCharAtxy(ex1 + 4, ey1 + 2) == '~' || getCharAtxy(ex1 - 1, ey1) == '\\' || getCharAtxy(ex1 - 1, ey1 + 1) == '_' || getCharAtxy(ex1 - 1, ey1 + 1) == '~')
    {
        playerHealth--;
    }
    else
    {
        eraseEnemy1();
        if (direction == "right")
        {
            ex1 = ex1 + 1;
        }
        if (direction == "left")
        {
            ex1 = ex1 - 1;
        }
        printEnemy1();
    }
}
void printEnemy2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    gotoxy(ex2, ey2);
    cout << "___";
    gotoxy(ex2, ey2 + 1);
    cout << "|~|";
    gotoxy(ex2, ey2 + 2);
    cout << "(o)";
}
void eraseEnemy2()
{
    gotoxy(ex2, ey2);
    cout << "   ";
    gotoxy(ex2, ey2 + 1);
    cout << "   ";
    gotoxy(ex2, ey2 + 2);
    cout << "   ";
}

void printEnemy3()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    gotoxy(ex3, ey3);
    cout << "___";
    gotoxy(ex3, ey3 + 1);
    cout << "|~|";
    gotoxy(ex3, ey3 + 2);
    cout << "\\^/";
}
void eraseEnemy3()
{
    gotoxy(ex3, ey3);
    cout << "   ";
    gotoxy(ex3, ey3 + 1);
    cout << "   ";
    gotoxy(ex3, ey3 + 2);
    cout << "   ";
}
void moveEnemy2(string direction)
{
    if (getCharAtxy(ex2 + 3, ey1) == '/' || getCharAtxy(ex2 + 3, ey1 + 1) == '_' || getCharAtxy(ex2 + 3, ey1 + 2) == '~' || getCharAtxy(ex2 - 2, ey1) == '\\' || getCharAtxy(ex2 - 2, ey1 + 1) == '_' || getCharAtxy(ex2 - 2, ey1 + 1) == '~')
    {
        playerHealth--;
    }
    else
    {
        eraseEnemy2();
        if (direction == "right")
        {
            ex2 = ex2 + 1;
        }
        if (direction == "left")
        {
            ex2 = ex2 - 1;
        }
        printEnemy2();
    }
}

void moveEnemy3(string vdirection)
{
    if (getCharAtxy(ex3, ey3 + 3) == '/' || getCharAtxy(ex3 + 1, ey3 + 3) == '~' || getCharAtxy(ex3 + 2, ey3 + 3) == '\\' || getCharAtxy(ex3, ey3 - 1) == '~' || getCharAtxy(ex3 + 1, ey3 - 1) == '~' || getCharAtxy(ex3 + 2, ey3 - 1) == '~')
    {
        playerHealth--;
    }
    else
    {
        eraseEnemy3();
        if (vdirection == "down")
        {
            ey3 = ey3 + 1;
        }
        if (vdirection == "up")
        {
            ey3 = ey3 - 1;
        }
        printEnemy3();
    }
}
void printScore()
{
    gotoxy(115, 9);
    cout << "                         ";
    gotoxy(115, 9);
    cout << "Player's Health: " << playerHealth;
    gotoxy(115, 10);
    cout << "                         ";
    gotoxy(115, 10);
    cout << "Enemy 1 Health: " << e1Health;
    gotoxy(115, 11);
    cout << "                         ";
    gotoxy(115, 11);
    cout << "Enemy 2 Health: " << e2Health;
    gotoxy(115, 12);
    cout << "                         ";
    gotoxy(115, 12);
    cout << "Enemy 3 Health: " << e3Health;
}

void printPlayer()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(px, py);
    cout << " /~\\" << endl;
    gotoxy(px, py + 1);
    cout << "_|~|_" << endl;
    gotoxy(px, py + 2);
    cout << " ~~~ " << endl;
}
void erasePlayer()
{
    gotoxy(px, py);
    cout << "     " << endl;
    gotoxy(px, py + 1);
    cout << "     " << endl;
    gotoxy(px, py + 2);
    cout << "     " << endl;
}
void movePlayerLeft()
{
    if (getCharAtxy(px - 1, py) == ' ' && getCharAtxy(px - 1, py + 1) == ' ' && getCharAtxy(px - 1, py + 2) == ' ')
    {
        erasePlayer();
        px = px - 1;
        printPlayer();
    }
}
void movePlayerRight()
{
    if (getCharAtxy(px + 6, py) == ' ' && getCharAtxy(px + 6, py + 2) == ' ' && getCharAtxy(px + 6, py + 2) == ' ')
    {
        erasePlayer();
        px = px + 1;
        printPlayer();
    }
}
void movePlayerUp()
{
    if (getCharAtxy(px, py - 1) == ' ' && getCharAtxy(px + 1, py - 1) == ' ' && getCharAtxy(px + 2, py - 1) == ' ' && getCharAtxy(px + 3, py - 1) == ' ' && getCharAtxy(px + 4, py - 1) == ' ')
    {
        erasePlayer();
        py = py - 1;
    }
    printPlayer();
}

void movePlayerDown()
{
    if (getCharAtxy(px, py + 3) == ' ' && getCharAtxy(px + 1, py + 3) == ' ' && getCharAtxy(px + 2, py + 3) == ' ' && getCharAtxy(px + 3, py + 3) == ' ' && getCharAtxy(px + 4, py + 3) == ' ')
    {
        erasePlayer();
        py = py + 1;
    }
    printPlayer();
}
void generatePlayerFire()
{
    pfX[pfCount] = px + 2;
    pfY[pfCount] = py - 1;
    if (getCharAtxy(pfX[pfCount], pfY[pfCount]) == ' ')
    {
        gotoxy(pfX[pfCount], pfY[pfCount]);
        setConsoleColor(2);
        cout << ".";
        isPlayerBulletActive[pfCount] = true;
        pfCount++;
    }
}

void movePlayerFire()
{
    for (int i = 0; i < pfCount; i++)
    {
        if (isPlayerBulletActive[i])
        {
            removePlayerFire(pfX[i], pfY[i]);
            if (getCharAtxy(pfX[i], pfY[i] - 1) == ' ')
            {
                pfY[i]--;
                gotoxy(pfX[i], pfY[i]);
                setConsoleColor(2);
                cout << ".";
            }
            else if (getCharAtxy(pfX[i], pfY[i] - 1) == '\\' || getCharAtxy(pfX[i], pfY[i] - 1) == '^' || getCharAtxy(pfX[i], pfY[i] - 1) == '/' || getCharAtxy(pfX[i], pfY[i] - 1) == '|')
            {
                e3Health--;
                isPlayerBulletActive[pfCount] = false;
            }
            else if (getCharAtxy(pfX[i], pfY[i] - 1) == '(' || getCharAtxy(pfX[i], pfY[i] - 1) == 'o' || getCharAtxy(pfX[i], pfY[i] - 1) == ')' || getCharAtxy(pfX[i], pfY[i] - 1) == '|')
            {
                e2Health--;
                isPlayerBulletActive[pfCount] = false;
            }
            else if (getCharAtxy(pfX[i], pfY[i] - 1) == ':' || getCharAtxy(pfX[i], pfY[i] - 1) == '*' || getCharAtxy(pfX[i], pfY[i] - 1) == '|')
            {
                e1Health--;
                isPlayerBulletActive[pfCount] = false;
            }
            else
            {
                isPlayerBulletActive[pfCount] = false;
            }
        }
    }
}

void removePlayerFire(int x, int y)
{
    gotoxy(x, y);
    cout << ' ';
}

void generateEnemy1Fire()
{
    int randomNumber = rand() % 100;
    if (randomNumber < 40)
    {
        efX[efCount] = ex1 + 2;
        efY[efCount] = ey1 + 3;
        if (getCharAtxy(efX[efCount], efY[efCount]) == ' ')
        {
            gotoxy(efX[efCount], efY[efCount]);
            cout << ".";
            isEnemyBulletActive[efCount] = true;
            efCount++;
        }
    }
}

void moveEnemy1Fire()
{
    for (int i = 0; i < efCount; i++)
    {
        if (isEnemyBulletActive[i])
        {
            removeEnemy1Fire(efX[i], efY[i]);
            if (getCharAtxy(efX[i], efY[i] + 1) == ' ')
            {
                efY[i]++;
                gotoxy(efX[i], efY[i]);
                cout << ".";
            }
            else if (getCharAtxy(efX[i], efY[i] + 1) == '/' || getCharAtxy(efX[i], efY[i] + 1) == '^' || getCharAtxy(efX[i], efY[i] + 1) == '\\')
            {
                playerHealth--;
                isEnemyBulletActive[i] = false;
            }
            else if (efY[i] >= 25)
            {
                isEnemyBulletActive[i] = false;
            }
        }
    }
}

void removeEnemy1Fire(int x, int y)
{
    gotoxy(x, y);
    cout << ' ';
}
void generateEnemy2Fire()
{
    int randomNumber = rand() % 100;
    if (randomNumber < 40)
    {
        efX2[efCount2] = ex2 + 1;
        efY2[efCount2] = ey2 + 3;
        if (getCharAtxy(efX2[efCount2], efY2[efCount2]) == ' ')
        {
            gotoxy(efX2[efCount2], efY2[efCount2]);
            cout << ".";
            isEnemyBulletActive2[efCount2] = true;
            efCount2++;
        }
    }
}

void moveEnemy2Fire()
{
    for (int i = 0; i < efCount2; i++)
    {
        if (isEnemyBulletActive2[i])
        {
            removeEnemy1Fire(efX2[i], efY2[i]);
            if (getCharAtxy(efX2[i], efY2[i] + 1) == ' ')
            {
                efY2[i]++;
                gotoxy(efX2[i], efY2[i]);
                cout << ".";
            }
            else if (getCharAtxy(efX2[i], efY2[i] + 1) == '/' || getCharAtxy(efX2[i], efY2[i] + 1) == '^' || getCharAtxy(efX2[i], efY2[i] + 1) == '\\')
            {
                playerHealth--;
                isEnemyBulletActive2[i] = false;
            }
            else if (efY2[i] >= 25)
            {
                isEnemyBulletActive2[i] = false;
            }
        }
    }
}

void removeEnemy2Fire(int x, int y)
{
    gotoxy(x, y);
    cout << ' ';
}

void generateEnemy3Fire()
{
    efX3[efCount3] = ex3 + 1;
    efY3[efCount3] = ey3 + 3;

    int randomValue = rand() % 100;

    if (randomValue < 10 && getCharAtxy(efX3[efCount3], efY3[efCount3]) == ' ')
    {
        gotoxy(efX3[efCount3], efY3[efCount3]);
        cout << ".";
        isEnemyBulletActive3[efCount3] = true;
        efCount3++;
    }
}

void moveEnemy3Fire()
{
    for (int i = 0; i < efCount3; i++)
    {
        if (isEnemyBulletActive3[i])
        {
            removeEnemy1Fire(efX3[i], efY3[i]);
            if (getCharAtxy(efX3[i], efY3[i] + 1) == ' ')
            {
                efY3[i]++;
                gotoxy(efX3[i], efY3[i]);
                cout << ".";
            }
            else if (getCharAtxy(efX3[i], efY3[i] + 1) == '/' || getCharAtxy(efX3[i], efY3[i] + 2) == '/' || getCharAtxy(efX3[i], efY3[i] + 1) == '^' || getCharAtxy(efX3[i], efY3[i] + 2) == '^' || getCharAtxy(efX3[i], efY3[i] + 1) == '\\' || getCharAtxy(efX3[i], efY3[i] + 2) == '\\')
            {
                playerHealth--;
                isEnemyBulletActive3[i] = false;
            }
            else if (efY3[i] >= 25)
            {
                isEnemyBulletActive3[i] = false;
            }
        }
    }
}

void generateRandomFire()
{
    int randomNumber = rand() % 100;
    if (randomNumber < 15)
    {
        efX_random[efCount_random] = 2;
        efY_random[efCount_random] = rand() % 19 + 17;

        if (getCharAtxy(efX_random[efCount_random], efY_random[efCount_random]) == ' ')
        {
            gotoxy(efX_random[efCount_random], efY_random[efCount_random]);
            setConsoleColor(4);
            cout << ">";
            isEnemyBulletActive_random[efCount_random] = true;
            efCount_random++;
        }
    }
}
void moveRandomFire()
{
    for (int i = 0; i < efCount_random; i++)
    {
        if (isEnemyBulletActive_random[i])
        {
            removeEnemy1Fire(efX_random[i], efY_random[i]);
            if (getCharAtxy(efX_random[i] + 1, efY_random[i]) == ' ')
            {
                efX_random[i]++;
                gotoxy(efX_random[i], efY_random[i]);
                setConsoleColor(4);
                cout << ">";
            }
            else if (getCharAtxy(efX_random[i] + 1, efY_random[i]) == '/' || getCharAtxy(efX_random[i] + 1, efY_random[i]) == '_' || getCharAtxy(efX_random[i] + 1, efY_random[i]) == '~')
            {
                playerHealth--;
                isEnemyBulletActive_random[i] = false;
            }
            else if (efX_random[i] + 1 >= 120)
            {
                isEnemyBulletActive_random[i] = false;
            }
        }
    }
}

void printMaze()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 1);
    cout << "#############################################################################################################" << endl;
    cout << "#|---------------------------------------------------------------------------------------------------------|#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|_____________                                                                              ______________|#" << endl;
    cout << "#|_____________|                                                                            |______________|#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#|                                                                                                         |#" << endl;
    cout << "#############################################################################################################" << endl;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
