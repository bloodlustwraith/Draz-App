//#include "Graphichs.h"
//#include<SFML/Audio.hpp>
//#include<SFML/Graphics.hpp>
//#include<SFML/Network.hpp>
//#include<SFML/System.hpp>
//#include<SFML/Window.hpp>
//#include<iostream>
//using namespace std;
//using namespace sf;
//
//
//void Graphichs::startDaraz()
//{
//	RenderWindow window(VideoMode(1280, 720), "Daraz", Style::Default);
//	RectangleShape Daraz(Vector2f(1280, 720));
//	Texture picture;
//	picture.loadFromFile("Daraz Intro 2.png");
//	Daraz.setTexture(&picture);
//	double temp = 0;
//	while(window.isOpen()) {
//		if(temp < 255) {
//			temp += 0.2;
//			Daraz.setFillColor(Color::Color(255, 255, 255, temp));
//		}
//		if(temp >= 255)
//			window.close();
//		window.clear();
//		window.draw(Daraz);
//		window.display();
//	}
//}
//
//void Graphichs::endDaraz()
//{
//	RenderWindow window(VideoMode(1280, 720), "ThanK You", Style::Default);
//	RectangleShape Daraz(Vector2f(1280, 720));
//	Texture picture;
//	picture.loadFromFile("Thank you for shopping at daraz.png");
//	Daraz.setTexture(&picture);
//	double temp = 0;
//	while(window.isOpen()) {
//		if(temp < 255) {
//			temp += 0.3;
//			Daraz.setFillColor(Color::Color(255, 255, 255, temp));
//		}
//		if(temp >= 255)
//			window.close();
//		window.clear();
//		window.draw(Daraz);
//		window.display();
//	}
//}
