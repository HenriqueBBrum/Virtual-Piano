#pragma once

#include"tiles.hpp"
#define SOUNDS 13



class Piano{
    private:
        std::vector<WhiteTile> whiteTiles;
        std::vector<BlackTile> blackTiles;

        const int num_whiteTiles = 8;
        const int num_blackTiles = 5;


        sf::SoundBuffer buffer[SOUNDS];
        sf::Sound sound[SOUNDS];

        void initalize_sound();

        void play_sound(int pos);

        void play_sound_mouse();

        void play_sound_keyboard();

        int keyboard_to_sound();

        bool not_black_tile();

    public:

        Piano();

        void draw(sf::RenderWindow &win);

        void update();

};
