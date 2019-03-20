#include"piano.hpp"


Piano::Piano(){
    WhiteTile w_t;

    for(auto i = 0; i < num_whiteTiles; i++){
        w_t.setPosition(sf::Vector2f(LARG/num_whiteTiles*i,1));
        w_t.setSize(sf::Vector2f(LARG/num_whiteTiles, ALT-2));
        whiteTiles.push_back(w_t);
    }

    initalize_sound();

}

void Piano::initalize_sound(){





}

void Piano::play_sound(bool white,int pos){

    std::string file;
    std::string aux;
    std::ostringstream convert;


    convert << pos;
    aux = convert.str();
    if(white && (pos<num_whiteTiles && pos>=0)){
        file  = "Sounds/w_t"+aux+".wav";

        if(!buffer.loadFromFile(file)){
            std::cerr<<"Cade o arquivo: "<<file;
            exit(0);
        }

        sound.setBuffer(buffer);
        sound.play();
    }


}

void Piano::update(){
    for(auto i = 0; i < num_whiteTiles; i++){
        if(whiteTiles[i].mouse_inside() && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            play_sound(true, i);

        }

    }
}

void Piano::draw(sf::RenderWindow &win){
    for(auto i : whiteTiles)
        i.draw(win);

    //for(auto i : blackTiles)
        //i.draw(win);

}


