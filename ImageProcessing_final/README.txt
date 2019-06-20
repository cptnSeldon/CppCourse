Image File Format

ASCII
    PBM (Portable Bit Map)
        > code :   P1
        > size :   w h
        > data :   black = 0, white = 1

    PGM (Portable Gray Map)
        > code :   P2
        > size :   w h
        > max  :   0-255    (maximum value for white)
        > data :   0-max

    PPM (Portable Pixel Map)
        > code :   P3
        > size :   w h
        > max  :   0-255    (maximum value for white)
        > data :   r=0-max, g=0-max, b=0-max

LINKS :
    ----------------------------------------------------------------------------------
                                        BASE
    ----------------------------------------------------------------------------------
	- http://dlib.net/imaging.html
    - https://www.scratchapixel.com/lessons/digital-imaging/simple-image-manipulations
    - https://stackoverflow.com/questions/33114302/converting-image-from-colored-to-grayscale
    - https://en.wikipedia.org/wiki/Grayscale#Converting_color_to_grayscale
    - https://stackoverflow.com/questions/7367770/how-to-flatten-or-index-3d-array-in-1d-array
    - https://people.sc.fsu.edu/~jburkardt/data/pbma/pbma.html
    - https://people.sc.fsu.edu/~jburkardt/data/pgma/pgma.html
    - https://people.sc.fsu.edu/~jburkardt/data/ppma/ppma.html
    ----------------------------------------------------------------------------------
                                        ADVANCED
    ----------------------------------------------------------------------------------
    - https://www.programming-techniques.com/2013/02/calculating-convolution-of-image-with-c_2.html