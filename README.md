
# Exploring C++11: A look at the new language and library features

by Gavin Baker <gavinb@antonym.org>

This source repository contains a series of sample programs designed to
illustrate some of the major new features of C++11.  It constitutes the complete
set of source files to accompany the articles posted at:

  * http://antonym.org/blog/categories/cplusplus11

## Motivation

Once drafts of the C++11 specification became widely available, numerous
articles were published discussing the proposed new features.  It became clear
that this standards update was the most significant yet.  C++11 introduces a
raft of new language features, as well as sweeping changes and major new
additions to the standard library.

I decided that reading about the new features wasn't enough; I had to use them,
write lots of new code, experiment, and write up notes on the experience.  That
is the best way to really learn something new - theory followed by lots of
practice. This series of articles is a distillation of this process, published
here in the hope that it might be useful for others.

## Topics

The subfolders herein contain code illustrating the following areas:

 - `smart_pointers`: modern memory management
 - `threads`: multithreading and concurrency
 - `async`: asynchronous processing with futures and promises
 - `chrono`: simple time point and duration support
 - `regex`: regular expressions
 - `string`: numeric conversions

Each has a brief explanation, and a `Makefile` to build the samples.

## Compatibility

This code has been tested on Mac OS X and Linux using the `clang` and `gcc`
toolchains.  It should work on Windows with a suitably standards-conformant
compiler.  Every effort has been made to ensure the code is portable, and to
avoid using any platform-specific features.

## Licenses

The text, explanations and relevant blog posts are licensed under the
Creative Commons Attribution-ShareAlike 4.0 International license:

- http://creativecommons.org/licenses/by-sa/4.0/

To the extent that there exists any originality, the example source files are
published under the MIT license (the simplest and most permissive):

- http://opensource.org/licenses/MIT

## Feedback

If you have any questions, comments or suggestions for improvement, please feel
free to drop me an email, or even send me a patch.

-- Melbourne, Summer 2014
