# ofxTablet

Addon for OpenFrameworks to read tablet (eg. Wacom) sensor data such as pressure and tilt.

It's pulling the embedded tablet data from Cocoa events, and as such the code is structured a bit weirdly to get obj-C to play nicely in the C++ OF application. I'm not very experienced with OF, nor C++ or obj-C so if you have suggestions, please feel free to fork/ make a pull request. It works fine for my purposes at the moment anyway!

Known Issues
------------

* Currently only implemented/tested on MacOS X 10.9. Contributions for other OSes are very welcome, there's some good reference in Blender (eg. [X11](https://github.com/nicholasbishop/blender/blob/trunk/intern/ghost/intern/GHOST_SystemX11.cpp#L1928), [Windows](https://github.com/nicholasbishop/blender/blob/trunk/intern/ghost/intern/GHOST_WindowWin32.cpp#L313))
* Currently only supports one connected tablet. Probably not too had to support more, but I have no need for it and no way of testing.
* Doesn't support reading Wacom Intuos 3+ touch strips etc. I only have an old Intuos 2, so can't test it. Wacom supplies some sample code for accessing those sensors here: http://us.wacom.com/en/developerrelations/macintosh/

