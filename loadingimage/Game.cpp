#include "Game.h"//1
#include<iostream>
#include"TextureManager.h"//2
#include"GameObject.h"//3
using namespace std;
//SDL_Texture* playertex;
//SDL_Rect srcR, destR;
GameObject* player;
GameObject* enemy;
Game::Game() {

}
Game::~Game() {

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "subsystem initialized" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			cout << "window created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
			cout << "renderer created" << endl;
		}
		isrunning = true;
		//SDL_Surface* surface = IMG_Load("assets/player.png");
		//playertex = SDL_CreateTextureFromSurface(renderer, surface);
		//SDL_FreeSurface(surface);
		// 
		//playertex = TextureManager::LoadTexture("assets/player.png", renderer);
		player = new GameObject("assets/player.png", renderer,0,0);
		enemy = new GameObject("assets/enemy.png", renderer, 50, 50);
	}
	else {
		isrunning = false;
	}
}
void Game::handleevents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isrunning = false;
		break;
	default:
		break;
	}
}
void Game::update() {
	/*cnt++;
	destR.h = 64;
	destR.w = 64;
	destR.x = cnt;
	cout << cnt << endl;*/
	player->Update();
	enemy->Update();
}
void Game::render() {
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, playertex, NULL, &destR);
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "game cleaned" << endl;
}
