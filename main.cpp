#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct Board {
    sf::RectangleShape lVert;
    sf::RectangleShape rVert;
    sf::RectangleShape tHorz;
    sf::RectangleShape bHorz;

};

void setUpBoard(Board &b) {
    b.lVert.setSize({15, 800});
    b.rVert.setSize({15, 800});

    b.lVert.setPosition(250, 0);
    b.rVert.setPosition(515, 0);

    b.tHorz.setSize({800, 15});
    b.bHorz.setSize({800, 15});

    b.tHorz.setPosition(0, 250);
    b.bHorz.setPosition(0, 515);

    b.lVert.setFillColor(sf::Color::White);
    b.rVert.setFillColor(sf::Color::White);
    b.tHorz.setFillColor(sf::Color::White);
    b.bHorz.setFillColor(sf::Color::White);

}

void drawBoard(sf::RenderWindow& win, Board &b) {
    win.draw(b.lVert);
    win.draw(b.rVert);
    win.draw(b.bHorz);
    win.draw(b.tHorz);
}

int main() {
    sf::RenderWindow win(sf::VideoMode(800, 800), "Tic-Tac-Toe");
    Board b;
    setUpBoard(b);

    while(true) {
        sf::Event e;
        while(win.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed:
                    exit(0);

            }
        }

        win.clear(sf::Color::Blue);
        drawBoard(win, b);
        win.display();
    }
}