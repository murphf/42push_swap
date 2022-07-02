First: the parsing,
i've already made code that the number from one string , argv[1]
but I don't think they want that,
they want each argument to be a number.
I can make it work with both approaches:
> ./push_swap 9 8 7 4  && 
> ./push_swap "9 8 7 4"

--------I'll let the parsing part for last, and let's emulated with a given array----
**parsing rules:


0- sort 2
1- sort 3
2- sort 5
3- sort 100
4- sort 500
5- sort 1000+
--------
used data structure: circular doubly linked list

for the sake of simplification: I'll create a "libft_utils.c", but I'll have to call the makefile of libft in makefile of push_swap afterwards..

--------
the allowed actions:
let's say we have list [9, 4, 8, 7] in stack A and [1, 2] in stack B:
NOTE: initially stack b is empty

sa *Swap the first 2 elements at the top of stack*
sa: A = [4, 9, 8, 7] 	sb: B = [2, 1]
ss = sa + sb

pa * Take the first element at the top of b and put it at the top of a*
pa: [1, 9, 4, 8, 7]	B = [2]
pb: A = [4, 8, 7] 	B = [9, 2, 1]

ra *first element becomes last one*
ra: A = [4, 8, 7, 9]   rb: B = [1, 2]
rr = ra + rb

rra *The last element becomes the first one*
rra: A = [7, 9, 4, 8]	rrb: B = [2, 1]
rrr = rra + rrb
-------

sorting 5 numbers algorithm:
INPUT: -7 4 7 6 -2
EXPECTED OUTPUT: -7 -2 4 6 7
what happens:
1- pb + pb + (sort 3 numbers remaining in stack A)

---STACK A---		---STACK B---
	-2					
	6					4
	7					-7

2- see if the first number in stack B is an extreme (i.e smaller than the smallest or bigger than the biggest)
	a- if smallest: pa
	b- if biggest: pa + ra

3- if not an extreme, search its interval: we want the direct follower of the stack B number 

TESTING OF 5 NUMBERS:
1 2 5 0 8		10mv  --- could be 8mv
-1 2 5 0 8		8mv	  --- 
1 22 -5 0 8		9mv	  --- could be 7mv
1 22 -5 0 -8 	10mv
-------------
make libft inside the push_swap makefile
-------------
BEST ELEMENT ALGORITHM:
1- find the smallest number in STACK A and make it to the top (depending on its position, ra or rra)
2-determine the LIS (longuest increasing subsequence) starting ofc from the min of stack A 
	a- find the most optimized algorithm for that
3- remove all the numbers that doesn't belong to LIS from stack A (push them to STACK B)
	a-what 's the best element we can push from stack A to stack B (least moves)
-----------------

100 numbers:
19 43 5 57 95 90 52 65 98 26 56 84 94 12 99 69 10 53 73 88 45 81 72 16 37 78 62 14 60 63 36 4 91 54 39 20 86 79 23 9 70 41 82 97 44 1 38 66 11 100 48 8 32 25 83 15 71 17 27 6 31 61 21 22 59 34 58 93 3 85 30 24 67 55 89 2 75 51 33 35 13 46 7 64 40 76 28 68 42 77 92 80 96 0 49 18 50 74 87 29

100 numbers (with the smallest on top):
0 49 18 50 74 87 29 19 43 5 57 95 90 52 65 98 26 56 84 94 12 99 69 10 53 73 88 45 81 72 16 37 78 62 14 60 63 36 4 91 54 39 20 86 79 23 9 70 41 82 97 44 1 38 66 11 100 48 8 32 25 83 15 71 17 27 6 31 61 21 22 59 34 58 93 3 85 30 24 67 55 89 2 75 51 33 35 13 46 7 64 40 76 28 68 42 77 92 80 96

longuest increasing subsequence (python): 
len (17):
0, 5, 12, 16, 20, 23, 25, 27, 31, 34, 58, 67, 75, 76, 77, 92, 96

500 numbers:
278 234 220 457 198 464 20 132 81 261 258 29 365 224 58 392 485 401 12 156 176 158 353 209 410 328 405 349 336 439 419 105 484 74 195 475 377 149 487 21 66 298 101 91 332 469 372 150 38 232 229 77 104 62 182 248 309 450 82 264 174 243 478 122 378 494 417 438 455 479 86 300 256 52 285 270 61 39 97 402 370 327 214 40 292 148 495 155 498 227 287 343 196 125 136 440 318 231 205 310 404 428 2 179 3 488 398 49 170 212 69 107 447 493 192 361 131 329 6 240 42 424 8 16 199 364 449 83 423 352 276 279 0 169 180 437 188 337 312 68 4 73 500 213 128 46 489 435 251 53 451 411 445 92 407 171 420 133 388 177 109 259 120 48 393 483 463 137 47 37 476 221 202 499 295 95 456 87 239 359 338 141 184 117 166 35 94 194 223 235 222 344 5 358 93 263 75 482 315 311 123 59 283 7 347 121 268 389 262 27 400 211 331 126 265 190 160 446 497 416 413 90 79 284 22 275 145 139 324 474 362 55 486 154 334 157 72 18 65 187 181 244 67 44 260 350 371 366 414 28 118 368 454 354 50 112 108 113 238 25 346 291 480 408 330 477 356 24 269 453 403 433 467 345 374 375 442 314 207 357 274 297 254 308 186 215 461 100 17 383 431 135 348 191 189 153 13 45 1 301 173 321 51 397 218 204 245 384 460 110 496 144 11 444 281 54 34 138 129 193 277 33 200 106 36 491 242 379 31 140 84 381 32 249 63 373 165 376 459 10 492 323 26 161 175 325 96 111 390 363 43 178 225 391 466 425 89 124 290 288 355 317 326 367 70 468 396 448 217 71 172 418 119 443 409 473 294 341 293 429 64 236 399 406 335 57 299 130 88 167 257 430 103 203 306 114 201 387 19 142 333 394 246 14 60 427 115 255 247 273 15 441 152 289 159 432 127 271 339 78 340 143 98 351 360 280 216 230 436 164 210 452 233 80 134 286 147 385 76 415 462 472 320 319 252 434 30 197 316 412 168 426 470 313 303 369 206 421 458 9 23 481 422 183 56 380 41 116 471 241 267 266 302 163 219 146 226 322 296 185 342 253 228 490 386 151 307 99 395 208 162 272 382 305 102 282 465 85 237 304

500 numbers (with the smallest on top):

longuest increasing subsequence (python): 
len (42):
0, 4, 46, 53, 92, 109, 120, 137, 141, 184, 194, 223, 235, 263, 283, 284, 324, 334, 350, 366, 368, 374, 375, 383, 384, 390, 391, 396, 418, 429, 430, 432, 436, 452, 462, 472, 481, 485, 487, 494, 495, 498

15 numbers to detect the problems:
13 4 1 2 0 15 12 10 11 3 14 6 5 9 7

15 with the smallest on top:
0, 15, 12, 10, 11, 3, 14, 6, 5, 9, 7, 13, 4, 1, 2

longuest increasing subsequence (python): 
len (5):
0, 3, 6, 9, 13

30 numbers to detect the problems:
8 25 22 26 16 15 3 24 18 19 30 27 7 14 29 6 0 12 4 2 28 9 10 11 21 13 23 5 1 17

30 with the smallest on top:
0, 12, 4, 2, 28, 9, 10, 11, 21, 13, 23, 5, 1, 17, 8, 25, 22, 26, 16, 15, 3, 24, 18, 19, 30, 27, 7, 14, 29, 6

longuest increasing subsequence (python): 
len (11):
0, 4, 9, 10, 11, 21, 23, 25, 26, 27, 29