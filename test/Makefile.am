##
## libqgl - The quick game library
## Copyright 2009 Sean Farell
##
## This file is part of libqgl. 
##
## libqgl is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## libqgl is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with libqgl. If not, see <http://www.gnu.org/licenses/>.
##

check_PROGRAMS = unittests

## We use include/qgl instead of only include to enshure that we include
## the headers from our package and not those that are installed.

INCLUDES = -I$(top_srcdir)/include @SDL_CFLAGS@ @SIGC_CFLAGS@

unittests_LDADD = $(top_builddir)/src/libqgl.la @SDL_LIBS@ @SIGC_LIBS@ @GL_LIBS@ @UT_LIBS@ 

unittests_SOURCES = \
	main.cpp \
    StringTest.cpp \
	SdlGraphicSystemTest.cpp \
	SdlInputSystemTest.cpp \
	ImageTest.cpp \
    FontTest.cpp \
    EngineTest.cpp

TESTS = unittests
