#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Paddle.h"
#include "Ball.h"




int main()
{

	//Création de la fenêtre 
	sf::RenderWindow window;
	window.create(sf::VideoMode(640, 480), "Pong");
	//Modification de la position de la fenêtre ( x=L , y=H)
	window.setPosition(sf::Vector2i(150, 50));
	//Définition des images par secondes maximal 
	window.setFramerateLimit(60);

	//Création du Paddle de gauche 
	Paddle lPaddle(10,60,40,210);
	sf::RectangleShape leftPaddle(sf::Vector2f(lPaddle.getm_width(),lPaddle.getm_height()));
	leftPaddle.setPosition(sf::Vector2f(lPaddle.getm_x(), lPaddle.getm_y()));
	
	//Création du Paddle de droite
	Paddle rPaddle(10, 60, 590, 210);
	sf::RectangleShape rightPaddle(sf::Vector2f(rPaddle.getm_width(), rPaddle.getm_height()));
	rightPaddle.setPosition(sf::Vector2f(rPaddle.getm_x(), rPaddle.getm_y()));
		
	//Création de la balle 
	Ball cball;
	sf::CircleShape ball(cball.getm_radius());
	ball.setPosition(sf::Vector2f(cball.getm_x(), cball.getm_y()));
	sf::Vector2f ballSpeed(cball.getm_speed(),cball.getm_speed());
	
	
	//Tant que la fenêtre est ouverte...
	while (window.isOpen()) {

		sf::Event event;
		//Test des évènements 
		while (window.pollEvent(event))	{ 

			//Si on clique sur fermer
			if (event.type == sf::Event::Closed)
				//On ferme la fenêtre
				window.close();
		}

			/* Gestion des déplacements clavier du paddle de gauche */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			leftPaddle.move(0, -lPaddle.getm_speed());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			leftPaddle.move(0, lPaddle.getm_speed());
			}

		    /* Gestion des déplacements clavier du paddle de droite */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
				rightPaddle.move(0, -rPaddle.getm_speed());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				rightPaddle.move(0, rPaddle.getm_speed());
			}

			/*Initialisation de la direction de la balle au départ*/
			ball.move(-ballSpeed.x, ballSpeed.y*2);

			/*Gestion de collision avec un mur*/
			if (ball.getPosition().y <= 0) {
				std::cout << "Balle collision Haut" << std::endl;
				ballSpeed.y = -ballSpeed.y;
				
			}
			else if (ball.getPosition().y >= 463) {
				std::cout << "Balle collision Bas" << std::endl;
				ballSpeed.y = -ballSpeed.y;
			}
			else if (ball.getPosition().x <= 20) {
				std::cout << "Joueur 2 a marqué" << std::endl;
				ball.setPosition(sf::Vector2f(cball.getm_x(), cball.getm_y()));
				
			}
			else if (ball.getPosition().x >= 620) {
				std::cout << "Joueur 1 a marqué" << std::endl;
				ball.setPosition(sf::Vector2f(cball.getm_x(), cball.getm_y()));
				
			}

			/*Gestion de collision avec un paddle*/
			sf::FloatRect ballBox = ball.getGlobalBounds();
			sf::FloatRect leftBox = leftPaddle.getGlobalBounds();
			sf::FloatRect rightBox = rightPaddle.getGlobalBounds();

			if (leftBox.intersects(ballBox)) {
				ballSpeed.x = -ballSpeed.x;
			}
			else if (rightBox.intersects(ballBox)) {
				ballSpeed.x = -ballSpeed.x;
			}
			
			/*Gestion de collision paddle gauche & mur*/
			if (leftPaddle.getPosition().y <= 0) {
				std::cout << "Padlle gauche collision Haut " << std::endl;
				leftPaddle.setPosition (40,0);
			}
			else if (leftPaddle.getPosition().y >= 420) {
				std::cout << "Padlle gauche collision Bas " << std::endl;
				leftPaddle.setPosition(40, 420);
			}

			/*Gestion de collision paddle droite & mur*/
			if (rightPaddle.getPosition().y <= 0) {
				std::cout << "Padlle droite collision Haut " << std::endl;
				rightPaddle.setPosition(590, 0);
			}
			else if (rightPaddle.getPosition().y >= 420) {
				std::cout << "Padlle droite collision Bas " << std::endl;
				rightPaddle.setPosition(590, 420);
			}

		window.clear();
		window.draw(leftPaddle);
		window.draw(rightPaddle);
		window.draw(ball);
		window.display();
		
	}

	return 0;
}