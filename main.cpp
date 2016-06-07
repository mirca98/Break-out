#include <SFML/Graphics.hpp>
using namespace sf;

void menu(RenderWindow & window)
{
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	menuTexture3.loadFromFile("images/333.png");
	aboutTexture.loadFromFile("images/about.png");
	menuBackground.loadFromFile("images/fon.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menuBg.setPosition(345, 0);


	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (sf::Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////
};

int main()
{
	unsigned i;
	
	// Create a working window
	sf::RenderWindow window(sf::VideoMode(640, 480), "Breakout");
	menu(window);
	
	sf::RectangleShape bricks[500];// Create blocks
	sf::CircleShape ball(8.f);// Create a ball
	sf::RectangleShape paddle(sf::Vector2f(80, 10));// Create a paddle

	// Sets the color of the racquet and ball
	paddle.setFillColor(sf::Color::Green);
	ball.setFillColor(sf::Color::Red);
	
	// Set the initial position of the racquet and ball
	paddle.setPosition((window.getSize().x / 10), window.getSize().y - (10 + paddle.getSize().y));
	ball.setPosition(paddle.getPosition().x / 2 , paddle.getPosition().y / 2);

	// Set the initial velocity of the ball
	ball.setRotation(-90);
	sf::Vector2f ballSpeed(-1.5f, -1.5f); 
	
	// Setting game parties
	sf::RectangleShape top;
	sf::RectangleShape bottom;
	sf::RectangleShape left;
	sf::RectangleShape right;

	// We set the boundaries of the playing field
	left.setSize(sf::Vector2f(0.1, 640));
	left.setFillColor(sf::Color::White);
	left.setPosition(sf::Vector2f(0, 0));

	right.setSize(sf::Vector2f(0.1, 640));
	right.setFillColor(sf::Color::White);
	right.setPosition(sf::Vector2f(640, 0));

	bottom.setSize(sf::Vector2f(640, 0.1));
	bottom.setFillColor(sf::Color::White);
	bottom.setPosition(sf::Vector2f(0, 479));

	top.setSize(sf::Vector2f(640, 0.1));
	top.setFillColor(sf::Color::White);
	top.setPosition(sf::Vector2f(0, 0));

	
	// Create blocks
	for (i = 0; i < 500; i++)
	{
		bricks[i].setFillColor(sf::Color::Yellow);
		bricks[i].setSize(sf::Vector2f(30, 12));
		bricks[i].setOutlineColor(sf::Color::Black);
		bricks[i].setOutlineThickness(1.f);


		if (i == 0)
		{
			bricks[i].setPosition(0, 0);
		}
		else if (i < 50)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, 0);
		}
		else if (i == 50)
		{
			bricks[i].setPosition(0, 0 + bricks[i].getSize().y);
		}
		else if (i > 50 && i < 100)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}
		else if (i == 100)
		{
			bricks[i].setPosition(0, 12 + bricks[i].getSize().y);
		}
		else if (i > 100 && i < 150)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}
		else if (i == 150)
		{
			bricks[i].setPosition(0, 24 + bricks[i].getSize().y);
		}
		else if (i > 150 && i < 200)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}

		else if (i == 200)
		{
			bricks[i].setPosition(0, 36 + bricks[i].getSize().y);
		}
		else if (i > 200 && i < 250)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}
		else if (i == 250)
		{
			bricks[i].setPosition(0, 48 + bricks[i].getSize().y);
		}
		else if (i > 250 && i < 300)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}
		else if (i == 300)
		{
			bricks[i].setPosition(0, 60 + bricks[i].getSize().y);
		}
		else if (i > 300 && i < 350)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}
		else if (i == 350)
		{
			bricks[i].setPosition(0, 72 + bricks[i].getSize().y);
		}
		else if (i > 350 && i < 400)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}
		else if (i == 400)
		{
			bricks[i].setPosition(0, 84 + bricks[i].getSize().y);
		}
		else if (i > 400 && i < 450)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}
		else if (i == 450)
		{
			bricks[i].setPosition(0, 96 + bricks[i].getSize().y);
		}
		else if (i > 450 && i < 500)
		{
			bricks[i].setPosition(bricks[i - 1].getPosition().x + bricks[i].getSize().x, bricks[i - 1].getPosition().y);
		}

	}

	// Strarte ball with racket
	ball.setPosition(paddle.getPosition()); 

	while (window.isOpen())
	{
		// Process events in the cycle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Besides the usual method of our window will be closed by pressing the Escape
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		// Movement racket with the mouse
		if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < (window.getSize().x - paddle.getSize().x))
			paddle.setPosition(sf::Mouse::getPosition(window).x, paddle.getPosition().y);
		
		// Collision block and ball
		for (i = 0; i < 500; i++)
		{
			if (bricks[i].getGlobalBounds().intersects(ball.getGlobalBounds()))
			{
				ballSpeed.y = -ballSpeed.y;

				bricks[i].setSize(sf::Vector2f(0, 0)); // The collision of the ball with the block , the block is destroyed
				i = 499;
			}
		}
		
		// Bounce the ball on the operating window borders
		if (top.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			ballSpeed.y = -ballSpeed.y;
		}

		if (bottom.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			ballSpeed.y = -ballSpeed.y;
			window.close();
		}

		if (left.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			ballSpeed.x = -ballSpeed.x;
		}

		if (right.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			ballSpeed.x = -ballSpeed.x;
		}
		
		// Rebound from the racket
		if (paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			ballSpeed.y = -ballSpeed.y;
		}

		ball.move(ballSpeed.x, ballSpeed.y);

		window.clear(sf::Color::White);


		for (i = 0; i < 500; i++)
		{
			window.draw(bricks[i]);
		}

		window.draw(top);
		window.draw(bottom);
		window.draw(left);
		window.draw(right);

		window.draw(paddle);
		window.draw(ball);
		window.display();
	}
	return 0;
}