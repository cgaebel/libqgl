dnl
dnl libqgl - The quick game library
dnl Copyright 2009 Sean Farell
dnl
dnl This file is part of libqgl.
dnl
dnl libqgl is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU Lesser General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl libqgl is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU Lesser General Public License
dnl along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
dnl

AC_INIT([libqgl], [0.1.0])
AM_INIT_AUTOMAKE(foreign)

AC_LANG([C++])
AC_PROG_CXX

AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

dnl current
dnl     The most recent interface number that this library implements.
dnl revision
dnl     The implementation number of the current interface.
dnl age
dnl     The difference between the newest and oldest interfaces that this 
dnl     library implements. In other words, the library implements all the 
dnl     interface numbers in the range from number current - age to current. 

dnl 1. Start with version information of ‘0:0:0’ for each libtool library.
dnl 2. Update the version information only immediately before a public release 
dnl    of your software. More frequent updates are unnecessary, and only 
dnl    guarantee that the current interface number gets larger faster.
dnl 3. If the library source code has changed at all since the last update, 
dnl    then increment revision (‘c:r:a’ becomes ‘c:r+1:a’).
dnl 4. If any interfaces have been added, removed, or changed since the last 
dnl    update, increment current, and set revision to 0.
dnl 5. If any interfaces have been added since the last public release, 
dnl    then increment age.
dnl 6. If any interfaces have been removed since the last public release, 
dnl    then set age to 0. 

dnl current:revision:age
LT_VERSION="0:0:0"
AC_SUBST(LT_VERSION)

dnl Check for SDL

SDL_VERSION=1.2.0
AM_PATH_SDL($SDL_VERSION, :, AC_MSG_ERROR([SDL version $SDL_VERSION not found!]))
AC_CHECK_LIB([SDL_image], [IMG_Load], SDL_LIBS+=" -lSDL_image", AC_MSG_ERROR([SDL_image not found.]))
AC_CHECK_LIB([SDL_ttf], [TTF_Init], SDL_LIBS+=" -lSDL_ttf", AC_MSG_ERROR([SDL_ttf not found.]))
AC_SUBST(SDL_CFLAGS)
AC_SUBST(SDL_LIBS)

dnl Check for openGL

AC_CHECK_LIB([GL], [main], [GL_LIBS="-lGL"], :)
AC_CHECK_LIB([opengl32], [main], [GL_LIBS="-lopengl32"], :)

AC_CHECK_LIB([GLU], [main], [GL_LIBS+=" -lGLU"], :)
AC_CHECK_LIB([glu32], [main], [GL_LIBS+=" -lglu32"], :)

dnl FIXME check if the openGL libs where actually found
dnl TODO add other platform specific libs like MAC

AC_CHECK_LIB([GLEW], [glewInit], [GL_LIBS+=" -lGLEW"])
AC_CHECK_LIB([glew32], [glewInit], [GL_LIBS+=" -lglew32"])
AC_CHECK_HEADER([GL/glew.h], :, 
    AC_MSG_ERROR([Failed to find <GL/glew.h> header.]))

AC_SUBST(GL_LIBS)


dnl Check for sigc++

PKG_CHECK_MODULES(SIGC, [sigc++-2.0], :, AC_MSG_ERROR([sigc++ not found!]))
AC_SUBST(SIGC_CFLAGS)
AC_SUBST(SIGC_LIBS)

dnl Check for UnitTest++

AC_CHECK_LIB(UnitTest++, main, :, AC_MSG_WARN([UnitTest++ library not found.]))
AC_CHECK_HEADER([UnitTest++/UnitTest++.h], :, AC_MSG_WARN([<UnitTest++/UnitTest++.h> header not found.]))

UT_LIBS="-lUnitTest++"
AC_SUBST(UT_LIBS)


dnl Output

AC_CONFIG_FILES([    
    Makefile
    libqgl.pc
    include/Makefile
    src/Makefile
    test/Makefile
])

AC_OUTPUT
