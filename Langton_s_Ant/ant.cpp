#include "ant.h"
#include "iostream"

ant::ant(int x, int y, sf::Image *earth, std::vector<sf::Color> colors, std::vector<int> rules) : m_x(x), m_y(y), m_earth(earth)
{
    dir = 0;
    m_shape.setSize(sf::Vector2f(1, 1));
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(sf::Vector2f(m_x, m_y));

    /*for(int i = 0; i < colors.size(); i++){
        m_colors.push_back(colors[i]);
    }*/
    /*m_rules = rules;
    m_colors = colors;*/

    numberRules = rules.size();

    for(int i = 0; i < colors.size(); i++){
        m_colors[i] = colors[i];
        m_rules[i] = rules[i];
    }

    std::cout << "!" << numberRules << std::endl;

    /*rules[0] = 0;
    rules[1] = 0;
    rules[2] = 1;
    rules[3] = 1;

    color[0] = m_earth.getPixel(m_x, m_y);
    color[1] = sf::Color::Green;
    color[2] = sf::Color::Cyan;
    color[3] = sf::Color::Blue;*/

    //ctor
}

ant::~ant()
{

}

sf::RectangleShape ant::getShape(){
    return m_shape;
}

void ant::update(){
    for(int i = 0; i < numberRules; i++){
        if(m_earth->getPixel(m_x, m_y) == m_colors[i]){
            if(i == numberRules-1){
                m_earth->setPixel(m_x, m_y, m_colors[0]);
            }else{
                m_earth->setPixel(m_x, m_y, m_colors[i+1]);
            }
            if(m_rules[i] == 1){
                dir++;
            }else{
                dir--;
            }
            if(dir < 0){
                dir = 3;
            }else if(dir > 3){
                dir = 0;
            }
            break;
        }
        //std::cout << m_shape.getRotation() << std::endl;
    }

    //dir = m_shape.getRotation();
    /*if(dir == 0 or dir == 4){
        m_y--;
    }else if(dir == 1){
        m_x++;
    }else if(dir == 2){
        m_y++;
    }else if(dir == 3){
        m_x--;
    }*/

    switch(dir){
        case 0:
            m_y--;
            break;
        case 1:
            m_x++;
            break;
        case 2:
            m_y++;
            break;
        case 3:
            m_x--;
            break;

    }

    //m_shape.setPosition(sf::Vector2f(m_x, m_y));
    /*if(m_earth->getPixel(m_x, m_y) == sf::Color::Black){
        m_earth->setPixel(m_x, m_y, sf::Color::White);
        m_shape.rotate(-90);
        if(m_shape.getRotation() < 0){
            m_shape.setRotation(360);
        }
    }else{
        m_earth->setPixel(m_x, m_y, sf::Color::Black);
        m_shape.rotate(90);
        if(m_shape.getRotation() > 360){
            m_shape.setRotation(0);
        }
    }

    dir = m_shape.getRotation();
    if(dir == 0 or dir == 360){
        m_y--;
    }else if(dir == 90){
        m_x++;
    }else if(dir == 180){
        m_y++;
    }else if(dir == 270){
        m_x--;
    }

    m_shape.setPosition(sf::Vector2f(m_x, m_y));
    std::cout << m_y << std::endl;*/
}
