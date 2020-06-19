#ifndef ANT_H
#define ANT_H
#include <SFML/Graphics.hpp>
#include <vector>

class ant
{
    public:
        ant(int x, int y, sf::Image *earth, std::vector<sf::Color> colors, std::vector<int> rules);
        virtual ~ant();
        void update();
        sf::RectangleShape getShape();

    protected:

    private:
        int m_x;
        int m_y;
        int dir;
        sf::Image *m_earth;
        sf::RectangleShape m_shape;
        sf::Color m_colors[100];
        int m_rules[100];
        int numberRules;
};

#endif // ANT_H
