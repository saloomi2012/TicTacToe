//
// Created by Suliman Alsaid on 2/7/20.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



class Game {

    struct Board {
        sf::RectangleShape lVert;
        sf::RectangleShape rVert;
        sf::RectangleShape tHorz;
        sf::RectangleShape bHorz;

    };

    Board board;
    sf::RenderWindow win;
    int squares[9];
    int winning[3];

    sf::Texture xtex;
    sf::Texture otex;

    void loop();
    void draw();
    void input();

    void updateBoard(int x, int y);

    bool xshape;

    bool run;

    bool won;
    bool stalemate;


public:
    Game();


    void drawBoard();

    void checkWin();

    bool boardFull();

    void reset();
};


#endif //TICTACTOE_GAME_H
