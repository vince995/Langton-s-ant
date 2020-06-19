#include "dialog.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
//#include <map.h>
#include <ant.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>


void split(const std::string &chaine, char delimiteur, std::vector<std::string> &elements)
{
    std::stringstream ss(chaine);
    std::string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Dialog w;
    w.exec();



    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1000, 1000), "SFML window");

    sf::View view(sf::Vector2f(500, 500), sf::Vector2f(1000, 1000));
    app.setView(view);


    std::vector<int> rules;
    std::vector<sf::Color> colors;

    std::string configStr = "";
    std::vector<std::string> config;
    std::vector<std::string> configColors;
    std::vector<std::string> configRules;

    std::string::size_type sz;

    std::vector<std::string> rvb;

    std::ifstream file("config.txt");
    if(file)
    {
        while(std::getline(file, configStr)){
            split(configStr, ';', config);
            configColors.push_back(config[0]);
            configRules.push_back(config[1]);
            split(configColors[0], ',', rvb);
            std::cout << configColors[0] << std::endl;
            std::cout << rvb[0] << " " << rvb[1] << " " << rvb[2] << std::endl;
            std::cout << std::stoi(rvb[0], &sz) << " " << std::stoi(rvb[1], &sz) << " " << std::stoi(rvb[2], &sz) << std::endl;
            if(configRules[0] == "R"){
                rules.push_back(0);
            }else{
                rules.push_back(1);
            }
            colors.push_back(sf::Color(std::stoi(rvb[0], &sz), std::stoi(rvb[1], &sz), std::stoi(rvb[2], &sz)));
            config.clear();configRules.clear();configColors.clear();rvb.clear();
        }
        file.close();
    }
    else
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;

    //std::cout << colors[0].r << " " << colors[0].g << " " <<colors[0].b << std::endl;


    /** rules and colors */
    /*std::vector<int> rules;
    rules.push_back(0);
    rules.push_back(1);
    rules.push_back(1);
    rules.push_back(0);



    std::vector<sf::Color> colors;
    colors.push_back(Map->getPixel(0, 0));
    colors.push_back(sf::Color(255, 86, 39));
    colors.push_back(sf::Color(201, 0, 53));
    colors.push_back(sf::Color(147, 7, 62));*/


    sf::Image *Map = new sf::Image;
    Map->create(1000, 1000, colors[0]);
    sf::Sprite MapShape;
    sf::Texture Image;
    Image.loadFromImage((*Map));
    MapShape.setTexture(Image);


    ant Ant(500, 500, Map, colors, rules);

    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            else if(event.type == sf::Event::MouseWheelMoved)
            {
                view.zoom(1.f+event.mouseWheel.delta*-0.1f);
                //view.setCenter(view.getCenter().x+((sf::Mouse::getPosition(app).x-500)/100), view.getCenter().y+((sf::Mouse::getPosition(app).y-500)/100));
                app.setView(view);
                std::cout << event.mouseWheel.delta << std::endl;
            }
        }

        // Clear screen
        app.clear(sf::Color::White);
        //Map->setPixel(i, i, sf::Color::Red);
        Ant.update();
        Image.update((*Map));
        app.draw(MapShape);
        //app.draw(Ant.getShape());
        // Update the window
        app.display();
    }

    delete Map;
//    delete rules;
//    delete colors;

    return EXIT_SUCCESS;
}

