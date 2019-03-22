#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<vector>
#include<map>


#define LARG 1000
#define ALT 600

const std::string  title = "Virtual Piano";


class Tile{
    protected:

        sf::RectangleShape rect;


    public:

        void draw(sf::RenderWindow &win);

        sf::RectangleShape getRect();

        void setSize(sf::Vector2f pos);

        void setPosition(sf::Vector2f pos);

        bool mouse_inside();

};

class WhiteTile : public Tile{
    public:
        WhiteTile();

        WhiteTile(sf::RectangleShape rect);

};

class BlackTile : public Tile{
    public:
    
        BlackTile();

        BlackTile(sf::RectangleShape rect);



};
