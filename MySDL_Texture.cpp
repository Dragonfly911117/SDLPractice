//
// Created by DF on 4/17/2023.
//

#include "MySDL_Texture.h"
#include "SDL_render.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "config.h"

MySDL_Texture::MySDL_Texture() {
    _texture = nullptr;
    _width = 1000;
    _height = 100;
    _blendMode = SDL_BLENDMODE_BLEND;
    _color = {0, 0, 0, 255};
    _text = "Hello World!";
    return;
}

MySDL_Texture::~MySDL_Texture() {
    free();
    return;
}

bool MySDL_Texture::loadFromFile(const std::string& path, SDL_Renderer* renderer) {
    free();
    SDL_Surface* image = IMG_Load(path.c_str());
    if (image == nullptr) {
        SDL_Log("Failed to load image: %s", IMG_GetError());
        return false;
    }
    _width = fmin(image->w, WINDOW_WIDTH);
    _height = fmin(image->h, WINDOW_HEIGHT);
    SDL_SetColorKey( image, SDL_TRUE, SDL_MapRGB( image->format, 0, 0xFF, 0xFF ) );
    _texture = SDL_CreateTextureFromSurface(renderer, image);
    if (_texture == nullptr) {
        SDL_Log("Failed to create _texture: %s", SDL_GetError());
        return false;
    }
    return true;
}

void MySDL_Texture::free() {
    if (_texture != nullptr) {
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
//        _width = 1000;
//        _height = 100;
    }
    return;
}

void
MySDL_Texture::render(const int& x, const int& y, SDL_Renderer* renderer, SDL_Rect* clip,
                      double angle, SDL_Point* center, SDL_RendererFlip flip) {
    if (_texture == nullptr) {
        SDL_Log("Texture is null");
        return;
    }
    if (renderer == nullptr) {
        SDL_Log("Renderer is null");
        return;
    }
    SDL_Rect rect = {x, y, _width, _height};
    if (clip != nullptr) {
        rect.h = clip->h;
        rect.w = clip->w;
    }
    SDL_RenderCopyEx(renderer, _texture, clip, &rect, angle, center, flip);

    return;
}

int MySDL_Texture::getWidth() const{
    return _width;
}

int MySDL_Texture::getHeight() const{
    return _height;
}


void MySDL_Texture::setAlpha(const Uint8& alpha) {
    _color.a = alpha;
}

void MySDL_Texture::setBlendMode(SDL_BlendMode blendMode) {
    _blendMode = blendMode;
}

void MySDL_Texture::setColor(const Uint8& red, const Uint8& green, const Uint8& blue) {
    _color.r = red;
    _color.g = green;
    _color.b = blue;
}



void MySDL_Texture::setText(const std::string& text) {
    _text = text;
}

std::string MySDL_Texture::getText() const {
    return _text;
}

bool MySDL_Texture::loadFromRenderedText( SDL_Renderer* renderer) {
    free();
    char fontPath[64] = {0};
     strcat(fontPath, FONT_DIR);
     strcat(fontPath, "Inkfree.ttf");
    TTF_Font* font = TTF_OpenFont(fontPath, 400);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, _text.c_str(), _color);
    if (textSurface == nullptr){
        SDL_Log("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }
    else {
        _texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (_texture == nullptr){
            SDL_Log("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        SDL_FreeSurface(textSurface);
    }
    TTF_CloseFont(font);
    return true;
}

void MySDL_Texture::setHeight(const int& height) {
    _height = height;
}

void MySDL_Texture::setWidth(const int& width) {
    _width = width;
}




