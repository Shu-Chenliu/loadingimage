#include"TextureManager.h"
SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren) {
	SDL_Surface* tmpsurface = IMG_Load(texture);
	SDL_Texture* text = SDL_CreateTextureFromSurface(ren, tmpsurface);
	SDL_FreeSurface(tmpsurface);
	return text;
}