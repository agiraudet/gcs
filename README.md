# What is GCS ?
GCS is a set of C++ classes. It's purpose is to allow the user to put together the most basic possible GUI in a SDL2 project. This can either be done on top of a existing SDL2 context, or as a standalone.
GCS stand for GUI Components for SDL. Also for "Garde ça simple." Meaning "Keep it simple".

# How to use
GCS can be used in differents ways.

You can simply copy the classes you need in your project directory and call it a day.

Or you can compile it as a library using the provided Makefile, then copy libgcs.a in you (distro-dependant) standard library path, and do the same with the includes folder.
For example, on Fedora, libgcs.a would go in /user/lib/ and the content of the include folder in /usr/include/gcs/

In the code of the project, you should then be able to simply use
```
#include "gcs/gcs.hpp"
```
to acces any GCS class.

# Examples
GCS is provided with examples. To try them out, simply run
```
Make example
```
You should endup with exampleGui and exampleRoot, two executable demonstrating the usage of theGCS classes based either on a Root or a Gui instance.
Look at the source code located in srcs/exampleGui.cpp and srcs/exampleRoot.cpp for more info.

# Expanding GCS
GCS as a really small codebase, making it easy to get a grasp on it and building your own widgets.
I would advise to take a simple on as a template, and building your own ones upon that.

# Compiling
GCS use SDL2 and SDL2_ttf, so those should be installed on you machine.
If you have installed GCS in you standard library path, you should be able to compile you project with something like this :
```
clang++ myproject.cpp -o myproject -lSDL2 -lSDL2_ttf -lgcs
```
For other usecase, look at the provided Makefile as a example.

# Documentation
The Doc is not really done yet, but you can look a the most important part of it by opening doc/html/index.html in your browser.

# TODO next
* add comments to the examples
* add a gcs namespace
* add pictures to the README
* add new widgets (such as Pictures, Canvas, List, etc)
* make a real documentation
* make a proper way to set the used font
