#pragma once

#include"tiles.hpp"



class Piano{
    private:
        std::vector<WhiteTile> whiteTiles;
        std::vector<BlackTile> blackTiles;


        sf::SoundBuffer buffer;
        sf::Sound sound;


        const int num_whiteTiles = 8;
        const int num_blackTiles = 5;

        void initalize_sound();

        void play_sound(bool white, int pos);

    public:

        Piano();

        void draw(sf::RenderWindow &win);

        void update();

};
