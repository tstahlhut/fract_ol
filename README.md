# fract_ol
42 project: First graphical project of the core curriculum of 42 school

## Description

Fract_ol is one of the first graphical projects a 42 student may choose. The aim is to display fractals, the Mandelbrot set and the Julia set with the help of a graphical school library (MiniLibX) which has been internally developed. MiniLibX only includes basic tools, as opening a window, creating images and dealing with keyboard and mouse events.

From the manual of MiniLibX:
  "MiniLibX is an easy way to create graphical software, without any X-Window programming knowledge.
    It provides simple window creation, a drawing tool, image and basic events management."

During this project one learns about complex numbers, the concept of optimization in computer graphics and event handling. 

### Allowed Functions

Besides MiniLibX, all functions of the math library are allowed, as well as the following functions:
- open, close
- read, write
- malloc, free
- perror, strerror
- exit

All other functions have to be written by the students themselves.

(taken from the subject description)

## What to know first

### What is a fractal?

The term fractal was coined by mathematican Benoît Mandelbrot in 1975 and is derived from the latin word fractus. 

Fractals are geometric shapes (or patterns) that have a detailed structure at arbitrarily small scales. Usually, fractals do not have an integer dimension (ganzzahlige Dimension) but a fractal dimension. This leads to its complex patterns. 
Each set with non-integer dimension is a fractal. (But be aware that a fractal can have an integer dimension, e.g. Sierpiński-Tetrahedron.)

The most common fractals are defined in the two- and three-dimensional Euclidean space and include for example the Mandelbrot and Julia set. Both of which are defined in the complex plane.

### Mandelbrot Set

The Mandelbrot set is a two-dimensional set defined in the complex plane as the complex number c, with
                           $z_{n+1}=z_{n}^{2}+c$
 starting its iteration at $z = 0$
 following the sequence $z_{0}, z_{1}, z_{2}, ...$
 and thus not diverging to infinity.
 The boundary of the Mandelbrot set is a fractal curve and "exhibits an infinitely complicated boundary that reveals progressively ever-finer recursive detail at increasing magnifications" (Wikipedia).

 "The "style" of this recursive detail depends on the region of the set boundary being examined. Mandelbrot set images may be created by sampling the complex numbers and testing, for each sample point c c, whether the sequence f c ( 0 ) , f c ( f c ( 0 ) ) , … {\displaystyle f_{c}(0),f_{c}(f_{c}(0)),\dotsc } goes to infinity. Treating the real and imaginary parts of c c as image coordinates on the complex plane, pixels may then be colored according to how soon the sequence | f c ( 0 ) | , | f c ( f c ( 0 ) ) | , … {\displaystyle |f_{c}(0)|,|f_{c}(f_{c}(0))|,\dotsc } crosses an arbitrarily chosen threshold (the threshold must be at least 2, as -2 is the complex number with the largest magnitude within the set, but otherwise the threshold is arbitrary). If c c is held constant and the initial value of z z is varied instead, the corresponding Julia set for the point c c is obtained. " (Wikipedia: https://en.wikipedia.org/wiki/Mandelbrot_set)
 
