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

#ifndef _QGL_LABEL_H_
#define _QGL_LABEL_H_

#include <string>
#include <vector>

#include "defines.h"
#include "Widget.h"

#include "Font.h"

namespace qgl
{
    /**
     * Label displaying some text.
     **/
    class QGL_EXPORT Label : public Widget
    {
    public:
        /**
         * Default Constructor
         **/
        Label();
    
        /**
         * Initialize label.
         **/
        Label(const Font& font, const std::string& text);
        
        /**
         * Get the font.
         **/
        const Font& get_font() const;
        
        /**
         * Set the font.
         **/
        void set_font(const Font& value);
        
        /**
         * Get text.
         **/
        const std::string& get_text() const;
        
        /**
         * Set text.
         **/
        void set_text(const std::string& value);
        
        virtual void draw() const;
        
    private:
        Font font;
        std::string text;
        
        mutable std::vector<Image> imgs;
    };
}

#endif
