//
// libqgl - The quick game library
// Copyright 2009 Sean Farell
//
// This file is part of libqgl.
//
// libqgl is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libqgl is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with libqgl. If not, see <http://www.gnu.org/licenses/>.
//

#include "Image.h"

#include <cstring>
#include <stdexcept>
#include <SDL.h>
#include <SDL_image.h>
#include <GL/glew.h>

namespace qgl
{
//------------------------------------------------------------------------------
    Image::Image() {}

//------------------------------------------------------------------------------
    Image::Image(const std::string& f)
    {
        load(f);
    }

//------------------------------------------------------------------------------
    Image::Image(SDL_Surface* s)
    {
        if (s != NULL)
            data = SmartPtr<ImageData>(new ImageData(s));
        else
            throw std::logic_error("Sufrace is NULL.");
    }

//------------------------------------------------------------------------------
    Image::Image(const Image& orig)
    : data(orig.data) {}

//------------------------------------------------------------------------------
    Image::~Image() {}

//------------------------------------------------------------------------------
    const Image& Image::operator = (const Image& orig)
    {
        Image tmp(orig);
        tmp.swap(*this);
        return *this;
    }

//------------------------------------------------------------------------------
    const std::string& Image::get_file() const
    {
        return data->file;
    }

//------------------------------------------------------------------------------
    unsigned int Image::get_width() const
    {
        if (data)
            return data->surface->w;
        else
            return 0;
    }

//------------------------------------------------------------------------------
    unsigned int Image::get_height() const
    {
        if (data)
            return data->surface->h;
        else
            return 0;
    }

//------------------------------------------------------------------------------
    ColorFormat Image::get_format() const
    {
        if (data->surface->format->BytesPerPixel == 3)
        {
            return RGB_COLOR_FORMAT;
        }
        else if (data->surface->format->BytesPerPixel == 4)
        {
            return RGBA_COLOR_FORMAT;
        }
        else
        {
            throw std::runtime_error("Unhandled color format.");
        }
    }

//------------------------------------------------------------------------------
    const void* Image::get_data() const
    {
        if (data)
            return data->surface->pixels;
        else
            return NULL;
    }

//------------------------------------------------------------------------------
    unsigned int Image::get_data_size() const
    {
        return get_width() * get_height() * sizeof(char);
    }

//------------------------------------------------------------------------------
    void Image::bind(unsigned int i) const
    {
        if (data)
        {
            if (! data->loaded_opengl)
                upload_to_opengl();

            glEnable(GL_TEXTURE_2D);
            //glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, data->gl_id);
        }
    }
    
//------------------------------------------------------------------------------
    void Image::unbind(unsigned int i) const
    {
        //glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

//------------------------------------------------------------------------------
    void Image::upload_to_opengl() const
    {
        if (data)
        {
            if (! data->loaded_opengl)
            {
                int mode = 0;
                if (get_format() == RGB_COLOR_FORMAT)
                    mode = GL_RGB;
                else if (get_format() == RGBA_COLOR_FORMAT)
                    mode = GL_RGBA;
                else
                    throw std::logic_error("qgl::opengl::TextureManager::load_image(): Unknoen pixel format.");

                glEnable(GL_TEXTURE_2D);
                glGenTextures(1, &data->gl_id);

                glBindTexture(GL_TEXTURE_2D, data->gl_id);

                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                glTexImage2D(GL_TEXTURE_2D, 0, mode, get_width(), get_height(), 0, mode, GL_UNSIGNED_BYTE, get_data());

                //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                //gluBuild2DMipmaps(GL_TEXTURE_2D, 4, get_width(), get_height(), mode, GL_UNSIGNED_BYTE, get_data());

                data->loaded_opengl = true;
            }
        }
    }

//------------------------------------------------------------------------------
    void Image::load(const std::string& file)
    {
        SDL_Surface* surface = IMG_Load(file.c_str());
        if (surface == NULL)
            throw std::runtime_error(IMG_GetError());
        else
            data = SmartPtr<ImageData>(new ImageData(surface, file));
    }

//------------------------------------------------------------------------------
    bool Image::equals(const Image& other) const
    {
        return get_width() == other.get_width() &&
               get_height() == other.get_height() &&
               std::memcmp(get_data(), other.get_data(), get_data_size()) == 0;
    }

//------------------------------------------------------------------------------
    void Image::swap(Image& other)
    {
        data.swap(other.data);
    }

//------------------------------------------------------------------------------
    Image::ImageData::ImageData(SDL_Surface* s)
    : surface(s), loaded_opengl(false), gl_id(0) {}

//------------------------------------------------------------------------------
    Image::ImageData::ImageData(SDL_Surface* s, const std::string& f)
    : file(f), surface(s), loaded_opengl(false), gl_id(0) {}

//------------------------------------------------------------------------------
    Image::ImageData::~ImageData()
    {
        SDL_FreeSurface(surface);
        if (loaded_opengl)
            glDeleteTextures(1, &gl_id);
    }

//------------------------------------------------------------------------------
    bool operator == (const Image& a, const Image& b)
    {
        return a.equals(b);
    }

//------------------------------------------------------------------------------
    bool operator != (const Image& a, const Image& b)
    {
        return ! a.equals(b);
    }
}

