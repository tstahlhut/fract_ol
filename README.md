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

## Background Knowledge

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

C is between -2 and 2 as everything beyond that radius in the complex plane diverges for sure with this calculation. 
At the beginning of each iteration, z equals 0. Afterwards, z equals the result of the previous calculation.
E.g. $c=1/4$
$z_{1]=0^2+1/4$
$z_{2}=1/4^2+1/4$
$z_{3}=5/16^2+1/4$
and so forth.

Now you can set thresholds for iterations and assign colours to it. 

 "The "style" of this recursive detail depends on the region of the set boundary being examined. Mandelbrot set images may be created by sampling the complex numbers and testing, for each sample point c c, whether the sequence f c ( 0 ) , f c ( f c ( 0 ) ) , … {\displaystyle f_{c}(0),f_{c}(f_{c}(0)),\dotsc } goes to infinity. Treating the real and imaginary parts of c c as image coordinates on the complex plane, pixels may then be colored according to how soon the sequence | f c ( 0 ) | , | f c ( f c ( 0 ) ) | , … {\displaystyle |f_{c}(0)|,|f_{c}(f_{c}(0))|,\dotsc } crosses an arbitrarily chosen threshold (the threshold must be at least 2, as -2 is the complex number with the largest magnitude within the set, but otherwise the threshold is arbitrary). If c c is held constant and the initial value of z z is varied instead, the corresponding Julia set for the point c c is obtained. " (Wikipedia: https://en.wikipedia.org/wiki/Mandelbrot_set)

## Bringing Fractals on the Screen

We plot the Mandelbrot and Julia set on a 2D graph:
x axis = real component of z
y axis = imaginary component of z

c = starting point of graph

Through iteration the patterns are created. The result of the equation is our new starting point c. These iterations will either diverge or converge. If they diverge (go to infinity), a "null" point is created on the graph. Thus, you get the pattern. The colours are created by assigning the number of iterations colours. 

Outside the radius of 2, all iterations diverge. Therefore we stay between -2 and 2.

If it is stable (finite), we colour it black.
If it is unstable (explodes, goes to infinity), there will be a colour. The colour differs in accordance to how many iterations we need for it to "explode", i.e. grow so big that it goes out of the radius. Thus, the intersting patterns in which we can zoom in infinitely are the boundaries of the Mandelbrot set. And they are so interesting and different because only a tiny change in c leads to a huge difference in the iteration and result. 

Nice explaining video of the Mandelbrot set: 
https://www.youtube.com/watch?v=NGMRB4O922I
https://www.youtube.com/watch?v=FFftmWSzgmk



Sources: https://ohmyphysics.com/blogs/news/introduction-to-fractals
Wikipedia (en & de on the fractals, the sets, etc)
 
