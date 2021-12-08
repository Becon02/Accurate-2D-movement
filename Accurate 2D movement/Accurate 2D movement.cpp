#include <string>
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

#define width 21
#define heigth 21

class Player
{
public:

    string name;
    float xPos, yPos;
    float rotation;
    float speed;

    Player()
    {
        name = "Default";
        xPos = 0.f;
        yPos = 0.f;
        rotation = 0.f;
        speed = 0.f;
    }
};

class Game
{
public:

    Player player[1];

    Game()
    {
        //Values for player 1
        player[0].name = "Becon02";
        player[0].xPos = 10.5f;
        player[0].yPos = 10.5f;
        player[0].rotation = 0.f;
        player[0].speed = 0.5f;
    }
};

void SpaceLine();
void UpdatePosition(Game game);
float MovementX(float _xPos, float _rotation);
float MovementY(float _yPos, float _rotation);

int main()
{
    Game game;

    SpaceLine();

    UpdatePosition(game);
}

void SpaceLine()
{
    std::cout << "--------------------------------------------------------------------------------------\n";
}

void UpdatePosition(Game game)
{
    char keyPress;
    int asciiValue;
    bool keepGoing = true;

    std::cout << "Move with (w/a/s/d) regular direction and move with (q,e,z,c) for diagonals." << endl;
    std::cout << "q: North West, e: North East, z: South West and c: South East." << endl;

    while (keepGoing == true)
    {
        keyPress = _getch();
        asciiValue = keyPress;

        //cout << asciiValue << endl;

        switch (asciiValue)
        {
        case 'w':
        {
            if (game.player[0].yPos <= 0)
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].yPos -= 1;
            }
            break;
        }
        case 'a':
        {
            if (game.player[0].xPos <= 0)
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].xPos -= 1;
            }
            break;
        }
        case 's':
        {
            if (game.player[0].yPos >= (heigth - 1))
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].yPos += 1;
            }
            break;
        }
        case 'd':
        {
            if (game.player[0].xPos >= (width - 1))
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].xPos += 1;
            }
            break;
        }
        case 'q':
        {
            if (game.player[0].xPos >= 0 || game.player[0].yPos >= (heigth - 1))
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].xPos = MovementX(game.player[0].xPos, 135.f);
                game.player[0].yPos = MovementY(game.player[0].yPos, 135.f);
            }

            break;
        }
        case 'e':
        {
            if (game.player[0].xPos >= (width - 1) || game.player[0].yPos >= (heigth - 1))
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].xPos = MovementX(game.player[0].xPos, 45.f);
                game.player[0].yPos = MovementY(game.player[0].yPos, 45.f);
            }

            break;
        }

        case 'z':
        {
            if (game.player[0].xPos <= 0 || game.player[0].yPos <= 0)
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].xPos = MovementX(game.player[0].xPos, 225.f);
                game.player[0].yPos = MovementY(game.player[0].yPos, 225.f);
            }

            break;
        }
        case 'c':
        {
            if (game.player[0].xPos >= (width - 1) || game.player[0].yPos <= 0)
            {
                game.player[0].xPos = 10.5f;
                game.player[0].yPos = 10.5f;
            }
            else
            {
                game.player[0].xPos = MovementX(game.player[0].xPos, 315.f);
                game.player[0].yPos = MovementY(game.player[0].yPos, 315.f);
            }

            break;
        }
        default:
            break;
        }

        system("CLS");

        SpaceLine();

        std::cout << "Player position is (" << game.player[0].xPos << ", " << game.player[0].yPos << ")" << endl;
    }

    SpaceLine();
}

float MovementX(float _xPos, float _rotation)
{
    Game game;

    float radians;
    float rotationInRadians;

    radians = (3.14 / 180);
    rotationInRadians = _rotation * radians;

    _xPos += (game.player[0].speed * cos(rotationInRadians));

    return(_xPos);

}

float MovementY(float _yPos, float _rotation)
{
    Game game;

    float radians;
    float rotationInRadians;

    radians = (3.14 / 180);
    rotationInRadians = _rotation * radians;

    _yPos += (game.player[0].speed * sin(rotationInRadians));

    return(_yPos);

}
