[![Build Status](https://travis-ci.org/fassetar/Bender-Emulator.svg)](https://travis-ci.org/fassetar/Bender-Emulator)
<br>

This is the repository for the CSCS2650 Computer Organization CPU Simulator,
a project being undertaken in the Spring 2011 semester.

The intent of this project is to build, in Object-Oriented C++, a functional
CPU simulator that can process instructions.

Documentation for the CPU simulator will be on the ASM course notes wiki,
which is located here: http://lab46.corning-cc.edu/notes/asm

For those who took Data Structures in Fall 2010, we'll likely want to 
assemble a page similar to what we ended up with for the Backgammon 
project.

We'll be making using of subversion once again to track our changes, and
with the class being entirely on the internet, we should be able to enjoy
more regular changes, instead of a flurry of updates surrounding given days.

Here is what I see to be our initial implementation roadmap:

Phase 1: Build component classes
--------------------------------
A CPU is actually just an electronic circuit, composed of many discrete
components. Through advanced manufacturing processes it is difficult for
us to often physically see this, but in reality, a CPU is just a collection
of transistors, resistors, etc. along with their more aggregate components-
logic gates, registers, etc.

There are different places where we could begin this project, depending on 
how in-depth you'd like to get (we could start at the atomic level, the
transistor level, the component level, or already-assembled level). I have
chosen to start us on the COMPONENT level. If there is resounding support
from the class, we can notch it down to the transistor level (won't make
the project more difficult, just a lot bigger as we'll be implementing a
lot more components and have a much more detailed view of things).

There are some in the class who carry experience to be a wealth of knowledge
at the transistor level.

But, not knowing the feeling of the class, I opted for more of a programming
approach than an electrical/computer engineering approach. I think we'd have
fun either way.

What we will start off doing is construct C++ classes to build the following
objects:

	- input AND
	- input OR
	- input NOT
	- input NAND
	- input NOR
	- input XOR
	- input XNOR
	* aside from the NOT, which is unary, the others are at least binary
	  (2-input). For starters, we can implement them as 2-input, but we may
	  want to explore multi-input flexibility.
	- flip-flops (we can build multiple, we're aiming for registers)
	- register (series of flip-flops, size determined on instantiation)
	- memory

Already I've listed enough components where each class member can have a
specific task. In many cases some of these components can reuse code from
other components (a NAND is really just a NOTted AND). So be sure to start
collaborating and communicating to work towards maximum code re-use.

Obviously, some trips to Google and Wikipedia are in order to familiarize
yourself with items. I'd recommend EVERYONE start reading up on the AND,
OR. NOT, etc. logical operators, and BEGIN ASKING QUESTIONS.

We're largely an empty slate at the moment, I'd like for the class to 
assist in some elements of the actual infrastructure of the project. I will
be endeavoring to be an active participant as well, but perhaps focusing
on rounding rough edges and implementing intuitive functionality.
