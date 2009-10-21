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

#include "Font.h"

#include <stdexcept>

#include "utils.h"

namespace qgl
{
//------------------------------------------------------------------------------
    Font::Font()
    : data(NULL) {}

//------------------------------------------------------------------------------
    Font::Font(const std::string& file, unsigned int size)
    : data(NULL)
    {
        load(file, size);
    }

//------------------------------------------------------------------------------
    Font::Font(const Font& orig)
    : data(orig.data) {}

//------------------------------------------------------------------------------
    Font::~Font() {}

//------------------------------------------------------------------------------
    const Font& Font::operator = (const Font& orig)
    {
        Font tmp(orig);
        tmp.swap(*this);
        return *this;
    }

//------------------------------------------------------------------------------
    std::string Font::get_file() const
    {
        if (data)
            return data->file;
        else
            return "";
    }

//------------------------------------------------------------------------------
    unsigned int Font::get_size() const
    {
        if (data)
            return data->size;
        else
            return 0;
    }

//------------------------------------------------------------------------------
    void Font::load(const std::string& file, unsigned int size)
    {
        TTF_Font* font = TTF_OpenFont(file.c_str(), size);
        if (font == NULL)
            throw std::runtime_error(TTF_GetError());

        data = SmartPtr<FontData>(new FontData(file, size, font));
    }

//------------------------------------------------------------------------------
    Vector2ui Font::estimate(const std::string& text) const
    {
        if (! data)
            return Vector2ui(0, 0);

        int result = 0;
        int w = 0;
        int h = 0;

        if (text.empty())
            result = TTF_SizeUTF8(data->font, " ", &w, &h);
        else
            result = TTF_SizeUTF8(data->font, text.c_str(), &w, &h);

        if (result == 0)
            return Vector2ui(w, h);
        else
           throw std::logic_error(TTF_GetError());
    }

//------------------------------------------------------------------------------
    Vector2ui Font::estimate_multiline(const std::string& text) const
    {
        std::vector<std::string> lines = explode(text, "\n");
        Vector2ui result(0,0);

        for (unsigned int i = 0; i < lines.size(); i++)
        {
            Vector2ui line_size = estimate(lines[i]);
            result(0) = std::max(result(0), line_size(0));
            result(1) += line_size(1);
        }

        return result;
    }

//------------------------------------------------------------------------------
    Image Font::render(const std::string& text) const
    {
        return render(text, Vector3f(1.0, 1.0, 1.0));
    }

//------------------------------------------------------------------------------
    Image Font::render(const std::string& text, const Vector3f& color) const
    {
        if (! data)
            throw std::logic_error("No font to render.");

        SDL_Surface* surface = NULL;

        SDL_Color sdl_color = {0};
        sdl_color.r = static_cast<unsigned int>(color(0) * 255);
        sdl_color.g = static_cast<unsigned int>(color(1) * 255);
        sdl_color.b = static_cast<unsigned int>(color(2) * 255);

        if (text.empty())
            // SDL_ttf won't let us render an empty string, thus
            // we render a space.
            surface = TTF_RenderUTF8_Blended(data->font, " ", sdl_color);
        else
            surface = TTF_RenderUTF8_Blended(data->font, text.c_str(), sdl_color);
        if (surface != NULL)
            return Image(surface);
        else
            throw std::logic_error(TTF_GetError());
    }

//------------------------------------------------------------------------------
    std::vector<Image> Font::render_multiline(const std::string& text) const
    {
        return render_multiline(text, Vector3f(1.0, 1.0, 1.0));
    }

//------------------------------------------------------------------------------
    std::vector<Image> Font::render_multiline(const std::string& text, const Vector3f& color) const
    {
        std::vector<std::string> lines = explode(text, "\n");
        std::vector<Image> images;

        for (unsigned int i = 0; i < lines.size(); i++)
        {
            images.push_back(render(lines[i], color));
        }

        return images;
    }

//------------------------------------------------------------------------------
    bool Font::equals(const Font& other) const
    {
        if (data == other.data)
            return true;
        else if (data)
            return data->file == other.data->file &&
                   data->size == other.data->size;
        else
            return false;
    }

//------------------------------------------------------------------------------
    void Font::swap(Font& other)
    {
        std::swap(data, other.data);
    }

//------------------------------------------------------------------------------
    Font::FontData::FontData(const std::string& fi, unsigned int s, TTF_Font* fo)
    : file(fi), size(s), font(fo) {}

//------------------------------------------------------------------------------
    Font::FontData::~FontData()
    {
        TTF_CloseFont(font);
        font = NULL;
    }

//------------------------------------------------------------------------------
    QGL_EXPORT bool operator == (const Font& a, const Font& b)
    {
        return a.equals(b);
    }

//------------------------------------------------------------------------------
    QGL_EXPORT bool operator != (const Font& a, const Font& b)
    {
        return !a.equals(b);
    }
}

