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

#ifndef _QGL_IMAGE_H_
#define _QGL_IMAGE_H_

#include <string>
#include <SDL.h>

#include "defines.h"
#include "Vector.h"
#include "ColorFormat.h"
#include "SmartPtr.h"

namespace qgl
{
    /**
     * 2D Image Buffer
     **/
    class QGL_EXPORT Image
    {
    public:
        //! Default Constructor
        Image();

        //! Create a image from file.
        explicit Image(const std::string& f);

        //! Wrap SDL surface.
        explicit Image(SDL_Surface* s);

        //! Copy constructor
        Image(const Image& orig);

        //! Destructor
        ~Image();

        //! Assignment operator.
        const Image& operator = (const Image& orig);

        /**
         * Get the file the image was loaded from.
         **/
        const std::string& get_file() const;

        //! Get the image's width.
        unsigned int get_width() const;

        //! Get the image's height.
        unsigned int get_height() const;

        //! Get the data format.
        ColorFormat get_format() const;

        //! Get the raw data.
        const void* get_data() const;

        //! Get the number of bytes used.
        unsigned int get_data_size() const;

        //! Bind the image to a openGL texture.
        void bind(unsigned int i = 0) const;
        
        /**
         * Unbind the image
         **/
        void unbind(unsigned int i = 0) const;

        //! Upload the image to video memory.
        void upload_to_opengl() const;

        //! Load image from file.
        void load(const std::string& file);

        //! Compare two images for equality.
        bool equals(const Image& other) const;

        //! Swap two images.
        void swap(Image& other);

    private:
        struct ImageData
        {
            std::string file;
            SDL_Surface* surface;
            bool loaded_opengl;
            unsigned int gl_id;

            ImageData(SDL_Surface* s);
            ImageData(SDL_Surface* s, const std::string& file);
            ~ImageData();

            // prevent implicit copy
            ImageData(const ImageData&);
            const ImageData& operator = (const ImageData&);
        };
        mutable SmartPtr<ImageData> data;
    };

    //! Equal operator for Image.
    bool operator == (const Image& a, const Image& b);

    //! Not equal operator for Image.
    bool operator != (const Image& a, const Image& b);
}

#endif
