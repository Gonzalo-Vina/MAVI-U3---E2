//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

///Punto de entrada a la aplicación///
int main() {
	//////Variables//////
	Texture textureChessW, textureChessB;
	Sprite chessWhite, chessBlack;

	int posicionX[8] = { 100,175,250,325,400,475,550,625 };
	int posicionY[8] = { 0,75,150,225,300,375,450,525 };

	//Cargamos la textura del archivo
	textureChessB.loadFromFile("imagenes/chessb.png");
	textureChessW.loadFromFile("imagenes/chessw.png");

	//Cargamos el material del sprite
	chessBlack.setTexture(textureChessB);
	chessWhite.setTexture(textureChessW);

	//Escalamos las imagenes a 75x75 para que entren en un cuadrado de 600x600
	chessBlack.setScale(0.5859, 0.5859);
	chessWhite.setScale(0.5859, 0.5859);

	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Que ventana horrible");
	// Loop principal
	while (App.isOpen())
	{
		// Limpiamos la ventana
		App.clear();
		//Dibujamos la escena
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						chessWhite.setPosition(posicionX[i], posicionY[j]);
						App.draw(chessWhite);
					}
					else {
						chessBlack.setPosition(posicionX[i], posicionY[j]);
						App.draw(chessBlack);
					}
				}
				else {
					if (j % 2 == 0) {
						chessBlack.setPosition(posicionX[i], posicionY[j]);
						App.draw(chessBlack);
					}
					else {
						chessWhite.setPosition(posicionX[i], posicionY[j]);
						App.draw(chessWhite);
					}
				}
			}
		}

		// Mostramos la ventana
		App.display();
	}
	return 0;
}
