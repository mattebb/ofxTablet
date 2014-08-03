# ofxTablet

Addon for OpenFrameworks to read tablet (eg. Wacom) sensor data such as pressure and tilt.

If the code looks organised in weird ways, it's because I had to jump through a few hoops to get Cocoa (obj-C) to play nicely in the c++ application. I'm not very experienced with OF, nor C++ or obj-C so if you have suggestions, please feel free to fork/ make a pull request. It works fine for my purposes though.

Known Issues
------------

* Currently only implemented/tested on MacOS X 10.9. Contributions for other OSes are very welcome, there's some good reference in Blender (eg. [X11](https://github.com/nicholasbishop/blender/blob/trunk/intern/ghost/intern/GHOST_SystemX11.cpp#L1928), [Windows](https://github.com/nicholasbishop/blender/blob/trunk/intern/ghost/intern/GHOST_WindowWin32.cpp#L313))
* Currently only supports one connected tablet. Probably not too had to support more, but I have no need for it and no way of testing.
* Doesn't support reading Wacom Intuos 3+ touch strips etc. I only have an old Intuos 2, so can't test it. Wacom supplies some sample code for accessing those sensors here: http://us.wacom.com/en/developerrelations/macintosh/


        License:
        /**
         * 
         * The MIT License
         * 
         * Copyright (c) 2014 Matt Ebb http://mattebb.com
         * 
         * Permission is hereby granted, free of charge, to any person obtaining a copy
         * of this software and associated documentation files (the "Software"), to deal
         * in the Software without restriction, including without limitation the rights
         * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
         * copies of the Software, and to permit persons to whom the Software is
         * furnished to do so, subject to the following conditions:
         * 
         * The above copyright notice and this permission notice shall be included in
         * all copies or substantial portions of the Software.
         * 
         * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
         * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
         * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
         * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
         * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
         * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
         * THE SOFTWARE.
         * 
         */