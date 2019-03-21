#include"piano.hpp"


Piano::Piano(){
    WhiteTile w_t;

    for(auto i = 0; i < num_whiteTiles; i++){
        w_t.setPosition(sf::Vector2f(LARG/(num_whiteTiles)*i,1));
        w_t.setSize(sf::Vector2f(LARG/(num_whiteTiles), ALT-2));
        whiteTiles.push_back(w_t);

    }


    BlackTile b_t;
    const float x_proportion = 0.7;
    const float y_proportion = 0.66;

    b_t.setSize(sf::Vector2f(w_t.getRect().getSize().x*x_proportion, w_t.getRect().getSize().y*y_proportion));
    float size_x = b_t.getRect().getSize().x;
    b_t.setPosition(sf::Vector2f(whiteTiles[1].getRect().getPosition().x-size_x/1.5, 0));
    blackTiles.push_back(b_t);

    b_t.setPosition(sf::Vector2f(whiteTiles[1].getRect().getPosition().x+size_x, 0));
    blackTiles.push_back(b_t);

    b_t.setPosition(sf::Vector2f(whiteTiles[5].getRect().getPosition().x-size_x/1.5, 0));
    blackTiles.push_back(b_t);

    b_t.setPosition(sf::Vector2f(whiteTiles[6].getRect().getPosition().x-size_x/2, 0));
    blackTiles.push_back(b_t);

    b_t.setPosition(sf::Vector2f(whiteTiles[6].getRect().getPosition().x+size_x, 0));
    blackTiles.push_back(b_t);

    initalize_sound();

}

void Piano::initalize_sound(){

    std::string file;
    int i = 0;
    for(; i < num_whiteTiles;i++){
        file  = "Sounds/w_t"+std::to_string(i)+".wav";

        if(!buffer[i].loadFromFile(file)){
            std::cerr<<"Cade o arquivo: "<<file;
            exit(0);
        }

    }
    for(int j = 0; j < num_blackTiles;j++){
        file  = "Sounds/b_t"+std::to_string(j)+".wav";

        if(!buffer[i].loadFromFile(file)){
            std::cerr<<"Cade o arquivo: "<<file;
            exit(0);
        }
        i++;

    }


}

void Piano::play_sound(int pos){

        sound[pos].setBuffer(buffer[pos]);
        sound[pos].play();

}

bool Piano::not_black_tile(){
    for(int i = 0; i < num_blackTiles;i++){
        if(blackTiles[i].mouse_inside())
            return false;
    }
    return true;
}

void Piano::play_sound_mouse(){

    for(auto i = 0; i < num_whiteTiles; i++){
        if(whiteTiles[i].mouse_inside() && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(not_black_tile())
                play_sound(i);

        }

    }

    for(int i = 0; i < num_blackTiles;i++){
        if(blackTiles[i].mouse_inside() && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            play_sound(i+num_whiteTiles);

        }

    }

}

int Piano::keyboard_to_sound(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
        return 0;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        return 1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        return 2;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        return 3;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        return 4;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
        return 5;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
        return 6;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
        return 7;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
        return 8;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
        return 9;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
        return 10;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
        return 11;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
        return 12;

    return -1;
}

void Piano::play_sound_keyboard(){
    if(keyboard_to_sound()<0)
        return;
    play_sound(keyboard_to_sound());

}

void Piano::update(){
    play_sound_keyboard();
    play_sound_mouse();
}

void Piano::draw(sf::RenderWindow &win){
    for(auto i : whiteTiles)
        i.draw(win);

    ///Black tile's lower part play white key
    ///Draws black tile according  to playable part
    BlackTile aux;
    for(auto i : blackTiles){
        aux.setPosition(i.getRect().getPosition());
        aux.setSize({i.getRect().getSize().x, i.getRect().getSize().y-27});

        aux.draw(win);
    }

}
