# fract_ol
42 project: First graphical project in the core curriculum of 42 school

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

### Complex Numbers

Complex numbers are made of a real part and an imaginary part. The real part is a normal number. The imaginary number i a normal number multiplied by i. i represents the square root of -1 (imaginary because you can actually not take the square root of a negative number). 

Complex numbers can be made graphically visible on a two-dimensional graph. The x axis represents the real part of the complex number and the y axis the imaginary part. 
2+3i will then be located at: x = 2 and y = 3.

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

### Understand the Iterations and Boundaries of the Mandelbrot Set
#### Simple Equation: $z = z^2$

The boundaries of the set can already be calculated approximately by iterating the simple equation: $z = z^2$
0 stays 0.
1 stays 1. 
Everything between 0 and 1 converges to 0.
Everything above 1 diverges to infinity.
Everything below 0, becomes positive. If smaller than -1 it goes to infinity, if between 0 and -1, it goes to 0.

Thus, everything between -1 to 1 does not diverge and stays inside the set. (It is coloured black.)
Everything < -1 and > 1, is coloured according to how fast it diverges to infinity. 

#### Equation: $z = z^2 + c$

Introducing c, it becomes more interesting:
Those iterations that do not diverge to inifity, either end at some point between -2 and 2 or they jump back and forth between different values inside the range of -2 and 2. Thus, any point whose orbit (sequence of iterations) escapes from the radius (-2 to 2) is known to be outside the Mandelbrot set. 

Values above 0.25 quickly escape, below not.
$0>= 0.25$ stay in Mandelbrot set.
< -2: diverge to infinity
-2 to 0.25: inside Mandelbrot set. (coloured black)
-> This is the real number line (x axis) of the Mandelbrot set.

 "The "style" of this recursive detail depends on the region of the set boundary being examined. Mandelbrot set images may be created by sampling the complex numbers and testing, for each sample point c c, whether the sequence f c ( 0 ) , f c ( f c ( 0 ) ) , … {\displaystyle f_{c}(0),f_{c}(f_{c}(0)),\dotsc } goes to infinity. Treating the real and imaginary parts of c c as image coordinates on the complex plane, pixels may then be colored according to how soon the sequence | f c ( 0 ) | , | f c ( f c ( 0 ) ) | , … {\displaystyle |f_{c}(0)|,|f_{c}(f_{c}(0))|,\dotsc } crosses an arbitrarily chosen threshold (the threshold must be at least 2, as -2 is the complex number with the largest magnitude within the set, but otherwise the threshold is arbitrary). If c c is held constant and the initial value of z z is varied instead, the corresponding Julia set for the point c c is obtained. " (Wikipedia: https://en.wikipedia.org/wiki/Mandelbrot_set)

 ## The Julia Set

Julia sets can be obtained with different equations but interestingly, also with the same equation used for the Mandelbrot set: $z = z^2$.

The only difference is that while the point of interest in the Mandelbrot set is c (and z starts at 0), the point of interest, i.e. the pixel, is z and c stays constant.


## Bringing Fractals on the Screen

The Mandelbrot set and the Julia set are grounded on the same equation: $z = z^2 + c$

Actually, both sets are two views on the very same thing.

We plot the Mandelbrot and Julia set on a 2D graph:
x axis = real component of z
y axis = imaginary component of z

c = starting point of graph

Through iteration the patterns are created. The result of the equation is our new starting point c. These iterations will either diverge or converge. If they diverge (go to infinity), a "null" point is created on the graph. Thus, you get the pattern. The colours are created by assigning the number of iterations colours. 

Outside the radius of 2, all iterations diverge. Therefore we stay between -2 and 2.

If it is stable (finite), we colour it black.
If it is unstable (explodes, goes to infinity), there will be a colour. The colour differs in accordance to how many iterations we need for it to "explode", i.e. grow so big that it goes out of the radius. Thus, the intersting patterns in which we can zoom in infinitely are the boundaries of the Mandelbrot set. And they are so interesting and different because only a tiny change in c leads to a huge difference in the iteration and result. 

Nice explaining video of the Mandelbrot set: 
Short intros:
https://www.youtube.com/watch?v=NGMRB4O922I

https://www.youtube.com/watch?v=FFftmWSzgmk

Best (more detailed) explanation:
https://www.youtube.com/watch?v=7MotVcGvFMg

## Escape Time Algorithm
"Escape conditions can be simple or complex. Because no complex number with a real or imaginary part greater than 2 can be part of the set, a common bailout is to escape when either coefficient exceeds 2. A more computationally complex method that detects escapes sooner, is to compute distance from the origin using the Pythagorean theorem, i.e., to determine the absolute value, or modulus, of the complex number. If this value exceeds 2, or equivalently, when the sum of the squares of the real and imaginary parts exceed 4, the point has reached escape. More computationally intensive rendering variations include the Buddhabrot method, which finds escaping points and plots their iterated coordinates. " (https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)



Sources: https://ohmyphysics.com/blogs/news/introduction-to-fractals
Wikipedia (en & de on the fractals, the sets, etc)
 
