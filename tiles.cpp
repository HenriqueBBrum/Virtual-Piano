#include"tiles.hpp"

void Tile::draw(sf::RenderWindow &win){
    win.draw(rect);
}

sf::RectangleShape Tile::getRect(){
    return rect;
}

void Tile::setPosition(sf::Vector2f pos){
    rect.setPosition(pos);
}

void Tile::setSize(sf::Vector2f size_){
    rect.setSize(size_);
}

bool Tile::mouse_inside(){
    sf::Mouse mouse;
    sf::Vector2f rect_pos(rect.getPosition());
    sf::Vector2f rect_size(rect.getSize());

    if((mouse.getPosition().x>=rect_pos.x && mouse.getPosition().x<=rect_pos.x+rect_size.x) &&
       (mouse.getPosition().y>=rect_pos.y && mouse.getPosition().y<=rect_pos.y+rect_size.y)){
        return true;
    }

    return false;
}

WhiteTile::WhiteTile(){
    rect.setPosition(0,0);
    rect.setSize(rect.getPosition());
    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color::Black);
}

WhiteTile::WhiteTile(sf::RectangleShape rect_){
    rect = rect_;
    rect.setFillColor(sf::Color::Red);
    rect.setOutlineColor(sf::Color::Blue);
}

BlackTile::BlackTile(){
    rect.setPosition(0,0);
    rect.setSize(rect.getPosition());
    rect.setFillColor(sf::Color::Black);
}

BlackTile::BlackTile(sf::RectangleShape rect_){
    rect = rect_;
    rect.setFillColor(sf::Color::Black);
}

