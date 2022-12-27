#include "GameObject.h"
#include"TextureManager.h"
#include<iostream>
using namespace std;
GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren,int x,int y) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
	srcR.h = 436;
	srcR.w = 242;
	srcR.x = 0;
	srcR.y = 0;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w *0.5;
	destR.h = srcR.h *0.5;
}
GameObject::~GameObject() {

}
void GameObject::Update() {
	xpos++;
	ypos++;
	destR.x = xpos;
	destR.y = ypos;
}
void GameObject::Render() {
	SDL_RenderCopy(renderer, objTexture, &srcR, &destR);
}
