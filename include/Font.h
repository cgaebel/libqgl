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

#ifndef _QGL_FONT_H_
#define _QGL_FONT_H_

#include <string>
#include <vector>
#include <SDL_ttf.h>

#include "defines.h"

#include "SdlSentry.h"

#include "Vector.h"
#include "Image.h"
#include "SmartPtr.h"

namespace qgl
{
    //! True Type Font
    class QGL_EXPORT Font
    {
    public:
        //! Default Constructor
        Font();

        //! Load font from file.
        Font(const std::string& file, unsigned int size);

        Font(const Font& orig);

        ~Font();

        const Font& operator = (const Font& orig);

        //! Get the file the font was loaded from.
        std::string get_file() const;

        //! Get the size the font was loaded in.
        unsigned int get_size() const;

        //! Load a font.
        void load(const std::string& file, unsigned int size);

        //! Estimate the size a given text will require.
        Vector2ui estimate(const std::string& text) const;

        //! Estimate the size a given multiline text will require.
        Vector2ui estimate_multiline(const std::string& text) const;

        //! Render the text into an image.
        Image render(const std::string& text) const;

        //! Render the text into an image.
        Image render(const std::string& text, const Vector3f& color) const;

        //! Render a text with multiple lines.
        std::vector<Image> render_multiline(const std::string& text) const;

        //! Render a text with multiple lines.
        std::vector<Image> render_multiline(const std::string& text, const Vector3f& color) const;

        //! Check if two fonts are the same.
        bool equals(const Font& other) const;

        //! Swap two fonts.
        void swap(Font& other);

    private:
        SdlSentry sdl_sentry;

        struct FontData
        {
            std::string file;
            unsigned int size;
            TTF_Font* font;

            FontData(const std::string& fi, unsigned int s, TTF_Font* fo);
            ~FontData();
        };
        SmartPtr<FontData> data;
    };

    //! Equal operator for Font.
    QGL_EXPORT bool operator == (const Font& a, const Font& b);

    //! Not equal operator for Font.
    QGL_EXPORT bool operator != (const Font& a, const Font& b);
}

#endif
