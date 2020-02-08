//
// Created by Suliman Alsaid on 2/7/20.
//

#include "Game.h"

Game::Game(): win(sf::VideoMode(800, 800), "Tic-Tac-Toe"){
        board.lVert.setSize({15, 800});
        board.rVert.setSize({15, 800});

        board.lVert.setPosition(250, 0);
        board.rVert.setPosition(515, 0);

        board.tHorz.setSize({800, 15});
        board.bHorz.setSize({800, 15});

        board.tHorz.setPosition(0, 250);
        board.bHorz.setPosition(0, 515);

        board.lVert.setFillColor(sf::Color::White);
        board.rVert.setFillColor(sf::Color::White);
        board.tHorz.setFillColor(sf::Color::White);
        board.bHorz.setFillColor(sf::Color::White);

        for(int& i: squares) {
            i = 0;
        }

        win.setFramerateLimit(60);

        xshape = true;

        xtex.loadFromFile("res/x.png");
        otex.loadFromFile("res/o.png");

        run = true;
        won = false;
        stalemate = false;
        loop();



}

void Game::loop() {

    while(run) {
        input();
        if(!won && !stalemate) checkWin();
        draw();
    }

}

void Game::draw() {
    win.clear(sf::Color::Blue);
    drawBoard();
    win.display();

}

void Game::input() {

    sf::Event e{};
    while(win.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                run = false;
                break;
            case sf::Event::MouseButtonPressed:
                if(e.mouseButton.button == sf::Mouse::Button::Left && !won && !stalemate) {
                    updateBoard(e.mouseButton.x, e.mouseButton.y);

                }
                break;
            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::R) {
                    reset();
                }
                break;


        }
    }



}

void Game::updateBoard(int x, int y) {
    if(x < 250) {
        if(y < 250) {
            if(squares[0] == 0) {
                squares[0] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        } else if (y < 515) {
            if(squares[3] == 0) {
                squares[3] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        } else {
            if(squares[6] == 0) {
                squares[6] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        }
    } else if(x < 515) {
        if(y < 250) {
            if(squares[1] == 0) {
                squares[1] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        } else if (y < 515) {
            if(squares[4] == 0) {
                squares[4] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        } else {
            if(squares[7] == 0) {
                squares[7] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        }
    } else {
        if(y < 250) {
            if(squares[2] == 0) {
                squares[2] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        } else if (y < 515) {
            if(squares[5] == 0) {
                squares[5] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        } else {
            if(squares[8] == 0) {
                squares[8] = (xshape) ? 1 : 2;
                xshape = !xshape;
            }
        }
    }
}

void Game::drawBoard() {
    win.draw(board.lVert);
    win.draw(board.rVert);
    win.draw(board.bHorz);
    win.draw(board.tHorz);

    sf::Sprite s;

    for(int i = 0; i < 9; i++) {
        if(squares[i] > 0) {
            s.setTexture((squares[i] == 1) ? xtex : otex);
            switch(i) {
                case 0:
                    s.setPosition(0, 0);
                    win.draw(s);
                    break;
                case 1:
                    s.setPosition(265, 0);
                    win.draw(s);
                    break;
                case 2:
                    s.setPosition(530, 0);
                    win.draw(s);
                    break;
                case 3:
                    s.setPosition(0, 265);
                    win.draw(s);
                    break;
                case 4:
                    s.setPosition(265, 265);
                    win.draw(s);
                    break;
                case 5:
                    s.setPosition(530, 265);
                    win.draw(s);
                    break;
                case 6:
                    s.setPosition(0, 530);
                    win.draw(s);
                    break;
                case 7:
                    s.setPosition(265, 530);
                    win.draw(s);
                    break;
                case 8:
                    s.setPosition(530, 530);
                    win.draw(s);
                    break;
            }
        }
    }

    if(won) {

        for (int i : winning) {
            if(squares[i] > 0) {
                s.setTexture((squares[i] == 1) ? xtex : otex);
                s.setColor(sf::Color::Yellow);
                switch(i) {
                    case 0:
                        s.setPosition(0, 0);
                        win.draw(s);
                        break;
                    case 1:
                        s.setPosition(265, 0);
                        win.draw(s);
                        break;
                    case 2:
                        s.setPosition(530, 0);
                        win.draw(s);
                        break;
                    case 3:
                        s.setPosition(0, 265);
                        win.draw(s);
                        break;
                    case 4:
                        s.setPosition(265, 265);
                        win.draw(s);
                        break;
                    case 5:
                        s.setPosition(530, 265);
                        win.draw(s);
                        break;
                    case 6:
                        s.setPosition(0, 530);
                        win.draw(s);
                        break;
                    case 7:
                        s.setPosition(265, 530);
                        win.draw(s);
                        break;
                    case 8:
                        s.setPosition(530, 530);
                        win.draw(s);
                        break;
                }
            }
        }

    }


}

void Game::checkWin() {

    if((squares[0] > 0) && (squares[0] == squares[1]) &&  (squares[0] == squares[2])) {
        winning[0] = 0;
        winning[1] = 1;
        winning[2] = 2;
        won = true;
    } else if(squares[3] > 0 && squares[3] == squares[4] && squares[3] == squares[5]) {
        winning[0] = 3;
        winning[1] = 4;
        winning[2] = 5;
        won = true;
    } else if(squares[6] > 0 && squares[6] == squares[7] && squares[6] == squares[8]) {
        winning[0] = 6;
        winning[1] = 7;
        winning[2] = 8;
        won = true;
    } else if(squares[0] > 0 && squares[0] == squares[4] && squares[0] == squares[8]) {
        winning[0] = 0;
        winning[1] = 4;
        winning[2] = 8;
        won = true;
    } else if(squares[2] > 0 && squares[2] == squares[4] && squares[2] == squares[6]) {
        winning[0] = 2;
        winning[1] = 4;
        winning[2] = 6;
        won = true;
    } else if(squares[0] > 0 && squares[0] == squares[3] && squares[0] == squares[6]) {
        winning[0] = 0;
        winning[1] = 3;
        winning[2] = 6;
        won = true;
    } else if(squares[1] > 0 && squares[1] == squares[4] && squares[1] == squares[7]) {
        winning[0] = 1;
        winning[1] = 4;
        winning[2] = 7;
        won = true;
    } else if(squares[2] > 0 && squares[2] == squares[5] && squares[2] == squares[8]) {
        winning[0] = 2;
        winning[1] = 5;
        winning[2] = 8;
        won = true;
    }

    if(boardFull() && !won) {
        stalemate = true;
    }


}

bool Game::boardFull() {
    for(int i : squares) {
        if(i == 0) {
            return false;
        }
    }

    return true;
}

void Game::reset() {
    xshape = true;
    run = true;
    won = false;
    stalemate = false;

    for(int& i: squares)
        i = 0;
}
