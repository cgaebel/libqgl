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

#ifndef _QGL_SMART_PTR_H_
#define _QGL_SMART_PTR_H_

#include <algorithm>
#include <stdexcept>

namespace qgl
{
    /**
	 * Non instrusive reference counting smart pointer.
	 **/
    template <typename Type>
    class SmartPtr
    {
    public:
        /**
         * Default constructor
         **/
        SmartPtr()
		: object(NULL), count(NULL) {}

        /**
         * Initialize
         *
         * @param o the obejct to manage
         */
        explicit SmartPtr(Type* o)
        : object(o), count(new unsigned int(1)) {}

        /** 
         * Copy constructor
         *
         * @param orig the pointer to copy
         **/
        SmartPtr(const SmartPtr<Type>& orig)
        : object(orig.object), count(orig.count)
        {
            if (count != NULL)
                (*count)++;
        }

        /** 
         * Destructor
         **/
        ~SmartPtr()
        {
            if (count != NULL)
            {
                (*count)--;
                if (*count == 0)
                {
                    delete object;
                    delete count;
                }
            }
            count = NULL;
            object = NULL;
        }

        /** 
         * Assignment operator
         **/
        const SmartPtr<Type>& operator = (const SmartPtr<Type>& orig)
        {
            SmartPtr<Type> tmp(orig);
            tmp.swap(*this);
            return *this;
        }

        /**
         * Dereference operator
         **/
        Type& operator * ()
        {
            if (object != NULL)
                return *object;
            else
                throw std::logic_error("NULL pointer");
        }

        /**
         * Const dereference operator
         **/
        const Type& operator * () const
        {
            if (object != NULL)
                return *object;
            else
                throw std::logic_error("NULL pointer");
        }

        /**
         * Member access operator
         **/
        Type* operator -> ()        
        {
            if (object != NULL)
                return object;
            else
                throw std::logic_error("NULL pointer");
        }

        /**
         * Const member access operator
         **/
        const Type* operator -> () const 
        {
            if (object != NULL)
                return object;
            else
                throw std::logic_error("NULL pointer");
        }
        
        /**
         * Check if the pointer is valid.
         **/
        operator bool () const
        {
            return object != NULL;
        }

        /**
         * Check if two smart pointers are same.
         **/
        bool equals(const SmartPtr<Type>& other) const
        {
            return object == other.object;
        }
        
        /**
         * Check if the addres of this pointe is less than the given one.
         **/
        bool less(const SmartPtr<Type>& other) const
        {
            return object < other.object;
        }

        /**
         * Swap two smart pointers
         **/
        void swap(SmartPtr<Type>& other)
        {
            std::swap(object, other.object);
            std::swap(count, other.count);
        }

    protected:
        Type* object;
        unsigned int* count;
    };

    /**
     * Equals operator for SmartPtr
     *
     * @relates SmartPtr
     **/
    template <typename Type>
    bool operator == (const SmartPtr<Type>& a, const SmartPtr<Type>& b)
    {
        return a.equals(b);
    }

    /**
     * Not equals operator for SmartPtr
     *
     * @relates SmartPtr
     **/
    template <typename Type>
    bool operator != (const SmartPtr<Type>& a, const SmartPtr<Type>& b)
    {
        return ! a.equals(b);
    }

    /**
     * Less than operator
     *
     * @relates SmartPtr
     **/
    template <typename Type>
    bool operator < (const SmartPtr<Type>& a, const SmartPtr<Type>& b)
    {
        return a.less(b);
    }
}

#endif
