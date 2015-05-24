/*
 * Copyright 2015 MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MACRO_VARGS_MAGIC_H
#define MACRO_VARGS_MAGIC_H

/* thanks to http://jonjagger.blogspot.com/2010/11/c-macro-magic-ppnarg.html */

#define ARGC(...)    ARGC_(__VA_ARGS__,REVERSE_SEQ())
#define ARGC_(...)   SEQ_NUM(__VA_ARGS__)

#define SEQ_NUM(\
        _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
        _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
        _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
        _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
        _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
        _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
        _61, _62, _63, N, ...) N

#define REVERSE_SEQ() \
        63,62,61,60,                   \
        59,58,57,56,55,54,53,52,51,50, \
        49,48,47,46,45,44,43,42,41,40, \
        39,38,37,36,35,34,33,32,31,30, \
        29,28,27,26,25,24,23,22,21,20, \
        19,18,17,16,15,14,13,12,11,10, \
        9,8,7,6,5,4,3,2,1,0


#define PASTE(a, b)  a ## b
#define XPASTE(a, b) PASTE(a,b)
#define APPLYX_(EACH_FN, MACRO_FN, ...) MACRO_FN(EACH_FN, __VA_ARGS__)

/* thanks http://sohu.io/questions/2016985/foreach-macro-on-macros-arguments */

#define APPLYX1(X, a)                X(a)
#define APPLYX2(X, a, b)             X(a) X(b)
#define APPLYX3(X, a, b, c)          X(a) X(b) X(c)
#define APPLYX4(X, a, b, c, d)       X(a) X(b) X(c) X(d)
#define APPLYX5(X, a, b, c, d, e)    X(a) X(b) X(c) X(d) X(e)
#define APPLYX6(X, a, b, c, d, e, f) X(a) X(b) X(c) X(d) X(e) X(f)
#define APPLYX7(X, a, b, c, d, e, f, g) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g)
#define APPLYX8(X, a, b, c, d, e, f, g, h) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h)
#define APPLYX9(X, a, b, c, d, e, f, g, h, i) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i)
#define APPLYX10(X, a, b, c, d, e, f, g, h, i, j) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j)
#define APPLYX11(X, a, b, c, d, e, f, g, h, i, j, k) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k)
#define APPLYX12(X, a, b, c, d, e, f, g, h, i, j, k, l) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l)
#define APPLYX13(X, a, b, c, d, e, f, g, h, i, j, k, l, m) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l) X(m)
#define APPLYX14(X, a, b, c, d, e, f, g, h, i, j, k, l, m, n) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l) X(m) X(n)
#define APPLYX15(X, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l) X(m) X(n) X(o)

#define FOREACH(EACH_FN, ...) APPLYX_(EACH_FN, XPASTE(APPLYX, ARGC(__VA_ARGS__)), __VA_ARGS__)

/* apologies to everyone */

#define APPLYX_MINUS_ONE1(X, a)
#define APPLYX_MINUS_ONE2(X, a, b)             X(a)
#define APPLYX_MINUS_ONE3(X, a, b, c)          X(a) X(b)
#define APPLYX_MINUS_ONE4(X, a, b, c, d)       X(a) X(b) X(c)
#define APPLYX_MINUS_ONE5(X, a, b, c, d, e)    X(a) X(b) X(c) X(d)
#define APPLYX_MINUS_ONE6(X, a, b, c, d, e, f) X(a) X(b) X(c) X(d) X(e)
#define APPLYX_MINUS_ONE7(X, a, b, c, d, e, f, g) \
    X(a) X(b) X(c) X(d) X(e) X(f)
#define APPLYX_MINUS_ONE8(X, a, b, c, d, e, f, g, h) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g)
#define APPLYX_MINUS_ONE9(X, a, b, c, d, e, f, g, h, i) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h)
#define APPLYX_MINUS_ONE10(X, a, b, c, d, e, f, g, h, i, j) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i)
#define APPLYX_MINUS_ONE11(X, a, b, c, d, e, f, g, h, i, j, k) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j)
#define APPLYX_MINUS_ONE12(X, a, b, c, d, e, f, g, h, i, j, k, l) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k)
#define APPLYX_MINUS_ONE13(X, a, b, c, d, e, f, g, h, i, j, k, l, m) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l)
#define APPLYX_MINUS_ONE14(X, a, b, c, d, e, f, g, h, i, j, k, l, m, n) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l) X(m)
#define APPLYX_MINUS_ONE15(X, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) \
    X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l) X(m) X(n)

#define FOREACH_EXCEPT_LAST(EACH_FN, ...) APPLYX_(EACH_FN, XPASTE(APPLYX_MINUS_ONE, ARGC(__VA_ARGS__)), __VA_ARGS__)


#define LAST_ARG1(a) a
#define LAST_ARG2(a, b) b
#define LAST_ARG3(a, b, c) c
#define LAST_ARG4(a, b, c, d) d
#define LAST_ARG5(a, b, c, d, e) e
#define LAST_ARG6(a, b, c, d, e, f) f
#define LAST_ARG7(a, b, c, d, e, f, g) g
#define LAST_ARG8(a, b, c, d, e, f, g, h) h
#define LAST_ARG9(a, b, c, d, e, f, g, h, i) i
#define LAST_ARG10(a, b, c, d, e, f, g, h, i, j) j
#define LAST_ARG11(a, b, c, d, e, f, g, h, i, j, k) k
#define LAST_ARG12(a, b, c, d, e, f, g, h, i, j, k, l) l
#define LAST_ARG13(a, b, c, d, e, f, g, h, i, j, k, l, m) m
#define LAST_ARG14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) n
#define LAST_ARG15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) o

#define LAST_ARG(...) XPASTE(LAST_ARG, ARGC(__VA_ARGS__))(__VA_ARGS__)

#endif //MACRO_VARGS_MAGIC_H
