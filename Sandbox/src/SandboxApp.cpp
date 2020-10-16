#include <EngClient.h>

class Sandbox : public Game {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

int main(int argc, char* args[]){
	Sandbox* myGame = new Sandbox();

	myGame->Init();

	delete myGame;

	return 0;
}
