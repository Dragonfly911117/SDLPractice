//
// Created by DF on 4/17/2023.
//

#include "MySDL_Texture.h"
#include "SDL_render.h"
#include "SDL_image.h"

MySDL_Texture::MySDL_Texture() {
    _texture = nullptr;
    _width = 0;
    _height = 0;
    _walkClips.resize(_walkAnimationFrames);
    for (int i = 0; i < _walkAnimationFrames; i++) {
        _walkClips[i].x = i * 64;
        _walkClips[i].y = 0;
        _walkClips[i].w = 64;
        _walkClips[i].h = 205;
    }
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
    _width = image->w;
    _height = image->h;
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
        _width = 0;
        _height = 0;
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
    SDL_Rect rect = {x, y, _width, _height};
    SDL_RenderCopyEx(renderer, _texture, &_walkClips.at(_currentFrame), &rect, angle, center, flip);
    SDL_RenderPresent(renderer);

    return;
}

int MySDL_Texture::getWidth() {
    return _width;
}

int MySDL_Texture::getHeight() {
    return _height;
}

void MySDL_Texture::toggleAnimation() {
    setFrame(_currentFrame + 1);
}

void MySDL_Texture::setFrame(int frame) {
    if (frame >= _walkAnimationFrames) {
        _currentFrame = 0;
    } else {
        _currentFrame = frame;
    }
}

int MySDL_Texture::getFrame() const {
    return _currentFrame;
}


