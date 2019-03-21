#include"piano.hpp"


int main(){
    sf::RenderWindow win(sf::VideoMode(LARG,ALT),title);

    sf::Event event;

    Piano* piano =  new Piano();

    while(win.isOpen()){

        while(win.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                win.close();

            piano->update();

        }

        win.clear();
        piano->draw(win);
        win.display();


    }

    delete piano;

}
