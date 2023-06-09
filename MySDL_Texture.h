//
// Created by DF on 4/17/2023.
//

#ifndef SDLPRACTICE_MYSDL_TEXTURE_H
#define SDLPRACTICE_MYSDL_TEXTURE_H

#include "SDL_blendmode.h"
#include "SDL_stdinc.h"
#include "SDL_render.h"
#include <string>
#include <vector>


class MySDL_Texture {
public:
    MySDL_Texture();
    ~MySDL_Texture();
    bool loadFromFile(const std::string& path, SDL_Renderer* renderer);
    bool loadFromRenderedText(SDL_Renderer* renderer);
    void free();
    void render(const int& x = 0, const int& y = 0, SDL_Renderer* renderer = nullptr, SDL_Rect* clip = nullptr,
                double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // setters
    void setAlpha(const Uint8& alpha);
    void setBlendMode(SDL_BlendMode blendMode);
    void setColor(const Uint8& red, const Uint8& green, const Uint8& blue);
    void setText(const std::string& text);
    void setWidth(const int& width);
    void setHeight(const int& height);

    // getters
    int getWidth() const;
    int getHeight() const;
    std::string getText() const;

private:
    SDL_Texture* _texture;
    SDL_BlendMode _blendMode;
    SDL_Color _color;
    int _width;
    int _height;
    std::string _text;
};


#endif //SDLPRACTICE_MYSDL_TEXTURE_H
