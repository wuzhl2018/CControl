/* r1f5kf.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*     *                                                               * */
/*     *                  copyright (c) 2011 by UCAR                   * */
/*     *                                                               * */
/*     *       University Corporation for Atmospheric Research         * */
/*     *                                                               * */
/*     *                      all rights reserved                      * */
/*     *                                                               * */
/*     *                     FFTPACK  version 5.1                      * */
/*     *                                                               * */
/*     *                 A Fortran Package of Fast Fourier             * */
/*     *                                                               * */
/*     *                Subroutines and Example Programs               * */
/*     *                                                               * */
/*     *                             by                                * */
/*     *                                                               * */
/*     *               Paul Swarztrauber and Dick Valent               * */
/*     *                                                               * */
/*     *                             of                                * */
/*     *                                                               * */
/*     *         the National Center for Atmospheric Research          * */
/*     *                                                               * */
/*     *                Boulder, Colorado  (80307)  U.S.A.             * */
/*     *                                                               * */
/*     *                   which is sponsored by                       * */
/*     *                                                               * */
/*     *              the National Science Foundation                  * */
/*     *                                                               * */
/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Subroutine */ int r1f5kf_(integer *ido, integer *l1, real *cc, integer *
	in1, real *ch, integer *in2, real *wa1, real *wa2, real *wa3, real *
	wa4)
{
    /* System generated locals */
    integer cc_dim1, cc_dim2, cc_dim3, cc_offset, ch_dim1, ch_dim2, ch_offset,
	     i__1, i__2;

    /* Builtin functions */
    double atan(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__, k, ic;
    static real arg, ti11, ti12, tr11, tr12;
    static integer idp2;


    /* Parameter adjustments */
    --wa4;
    --wa3;
    --wa2;
    --wa1;
    cc_dim1 = *in1;
    cc_dim2 = *ido;
    cc_dim3 = *l1;
    cc_offset = 1 + cc_dim1 * (1 + cc_dim2 * (1 + cc_dim3));
    cc -= cc_offset;
    ch_dim1 = *in2;
    ch_dim2 = *ido;
    ch_offset = 1 + ch_dim1 * (1 + ch_dim2 * 6);
    ch -= ch_offset;

    /* Function Body */
    arg = atan(1.f) * 8.f / 5.f;
    tr11 = cos(arg);
    ti11 = sin(arg);
    tr12 = cos(arg * 2.f);
    ti12 = sin(arg * 2.f);
    i__1 = *l1;
    for (k = 1; k <= i__1; ++k) {
	ch[((k * 5 + 1) * ch_dim2 + 1) * ch_dim1 + 1] = cc[((k + cc_dim3) * 
		cc_dim2 + 1) * cc_dim1 + 1] + (cc[((k + cc_dim3 * 5) * 
		cc_dim2 + 1) * cc_dim1 + 1] + cc[((k + (cc_dim3 << 1)) * 
		cc_dim2 + 1) * cc_dim1 + 1]) + (cc[((k + (cc_dim3 << 2)) * 
		cc_dim2 + 1) * cc_dim1 + 1] + cc[((k + cc_dim3 * 3) * cc_dim2 
		+ 1) * cc_dim1 + 1]);
	ch[(*ido + (k * 5 + 2) * ch_dim2) * ch_dim1 + 1] = cc[((k + cc_dim3) *
		 cc_dim2 + 1) * cc_dim1 + 1] + tr11 * (cc[((k + cc_dim3 * 5) *
		 cc_dim2 + 1) * cc_dim1 + 1] + cc[((k + (cc_dim3 << 1)) * 
		cc_dim2 + 1) * cc_dim1 + 1]) + tr12 * (cc[((k + (cc_dim3 << 2)
		) * cc_dim2 + 1) * cc_dim1 + 1] + cc[((k + cc_dim3 * 3) * 
		cc_dim2 + 1) * cc_dim1 + 1]);
	ch[((k * 5 + 3) * ch_dim2 + 1) * ch_dim1 + 1] = ti11 * (cc[((k + 
		cc_dim3 * 5) * cc_dim2 + 1) * cc_dim1 + 1] - cc[((k + (
		cc_dim3 << 1)) * cc_dim2 + 1) * cc_dim1 + 1]) + ti12 * (cc[((
		k + (cc_dim3 << 2)) * cc_dim2 + 1) * cc_dim1 + 1] - cc[((k + 
		cc_dim3 * 3) * cc_dim2 + 1) * cc_dim1 + 1]);
	ch[(*ido + (k * 5 + 4) * ch_dim2) * ch_dim1 + 1] = cc[((k + cc_dim3) *
		 cc_dim2 + 1) * cc_dim1 + 1] + tr12 * (cc[((k + cc_dim3 * 5) *
		 cc_dim2 + 1) * cc_dim1 + 1] + cc[((k + (cc_dim3 << 1)) * 
		cc_dim2 + 1) * cc_dim1 + 1]) + tr11 * (cc[((k + (cc_dim3 << 2)
		) * cc_dim2 + 1) * cc_dim1 + 1] + cc[((k + cc_dim3 * 3) * 
		cc_dim2 + 1) * cc_dim1 + 1]);
	ch[((k * 5 + 5) * ch_dim2 + 1) * ch_dim1 + 1] = ti12 * (cc[((k + 
		cc_dim3 * 5) * cc_dim2 + 1) * cc_dim1 + 1] - cc[((k + (
		cc_dim3 << 1)) * cc_dim2 + 1) * cc_dim1 + 1]) - ti11 * (cc[((
		k + (cc_dim3 << 2)) * cc_dim2 + 1) * cc_dim1 + 1] - cc[((k + 
		cc_dim3 * 3) * cc_dim2 + 1) * cc_dim1 + 1]);
/* L101: */
    }
    if (*ido == 1) {
	return 0;
    }
    idp2 = *ido + 2;
    i__1 = *l1;
    for (k = 1; k <= i__1; ++k) {
	i__2 = *ido;
	for (i__ = 3; i__ <= i__2; i__ += 2) {
	    ic = idp2 - i__;
	    ch[(i__ - 1 + (k * 5 + 1) * ch_dim2) * ch_dim1 + 1] = cc[(i__ - 1 
		    + (k + cc_dim3) * cc_dim2) * cc_dim1 + 1] + (wa1[i__ - 2] 
		    * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 
		    + 1] + wa1[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 1)) * 
		    cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ - 1 + (
		    k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] + wa4[i__ - 1] 
		    * cc[(i__ + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])) 
		    + (wa2[i__ - 2] * cc[(i__ - 1 + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (k + 
		    cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2] * 
		    cc[(i__ - 1 + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 
		    1] + wa3[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1]));
	    ch[(i__ + (k * 5 + 1) * ch_dim2) * ch_dim1 + 1] = cc[(i__ + (k + 
		    cc_dim3) * cc_dim2) * cc_dim1 + 1] + (wa1[i__ - 2] * cc[(
		    i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] - 
		    wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * 
		    cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) + (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * cc_dim2)
		     * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k + 
		    cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2] * 
		    cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1]));
	    ch[(i__ - 1 + (k * 5 + 3) * ch_dim2) * ch_dim1 + 1] = cc[(i__ - 1 
		    + (k + cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr11 * (wa1[
		    i__ - 2] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * cc_dim2) *
		     cc_dim1 + 1] + wa1[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 
		    1)) * cc_dim2) * cc_dim1 + 1] + wa4[i__ - 2] * cc[(i__ - 
		    1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] + wa4[i__ 
		    - 1] * cc[(i__ + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 
		    1]) + tr12 * (wa2[i__ - 2] * cc[(i__ - 1 + (k + cc_dim3 * 
		    3) * cc_dim2) * cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (
		    k + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + wa3[i__ - 2] 
		    * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 
		    + 1] + wa3[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1]) + ti11 * (wa1[i__ - 2] * cc[(i__ 
		    + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] - wa1[
		    i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * cc_dim2) *
		     cc_dim1 + 1] - (wa4[i__ - 2] * cc[(i__ + (k + cc_dim3 * 
		    5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * cc[(i__ - 1 
		    + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])) + ti12 * (
		    wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * cc_dim2) * 
		    cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k + cc_dim3 *
		     3) * cc_dim2) * cc_dim1 + 1] - (wa3[i__ - 2] * cc[(i__ + 
		    (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] - wa3[i__ 
		    - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * cc_dim2) * 
		    cc_dim1 + 1]));
	    ch[(ic - 1 + (k * 5 + 2) * ch_dim2) * ch_dim1 + 1] = cc[(i__ - 1 
		    + (k + cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr11 * (wa1[
		    i__ - 2] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * cc_dim2) *
		     cc_dim1 + 1] + wa1[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 
		    1)) * cc_dim2) * cc_dim1 + 1] + wa4[i__ - 2] * cc[(i__ - 
		    1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] + wa4[i__ 
		    - 1] * cc[(i__ + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 
		    1]) + tr12 * (wa2[i__ - 2] * cc[(i__ - 1 + (k + cc_dim3 * 
		    3) * cc_dim2) * cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (
		    k + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + wa3[i__ - 2] 
		    * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 
		    + 1] + wa3[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1]) - (ti11 * (wa1[i__ - 2] * cc[(
		    i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] - 
		    wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * 
		    cc_dim2) * cc_dim1 + 1] - (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) + ti12 * (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k 
		    + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] - (wa3[i__ - 2] *
		     cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1])));
	    ch[(i__ + (k * 5 + 3) * ch_dim2) * ch_dim1 + 1] = cc[(i__ + (k + 
		    cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr11 * (wa1[i__ - 2] 
		    * cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1]
		     - wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * 
		    cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) + tr12 * (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k 
		    + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2] *
		     cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1])) + (ti11 * (wa4[i__ - 2] * cc[(
		    i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] + 
		    wa4[i__ - 1] * cc[(i__ + (k + cc_dim3 * 5) * cc_dim2) * 
		    cc_dim1 + 1] - (wa1[i__ - 2] * cc[(i__ - 1 + (k + (
		    cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] + wa1[i__ - 1] * 
		    cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1]))
		     + ti12 * (wa3[i__ - 2] * cc[(i__ - 1 + (k + (cc_dim3 << 
		    2)) * cc_dim2) * cc_dim1 + 1] + wa3[i__ - 1] * cc[(i__ + (
		    k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] - (wa2[i__ 
		    - 2] * cc[(i__ - 1 + (k + cc_dim3 * 3) * cc_dim2) * 
		    cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (k + cc_dim3 * 3) 
		    * cc_dim2) * cc_dim1 + 1])));
	    ch[(ic + (k * 5 + 2) * ch_dim2) * ch_dim1 + 1] = ti11 * (wa4[i__ 
		    - 2] * cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * 
		    cc_dim1 + 1] + wa4[i__ - 1] * cc[(i__ + (k + cc_dim3 * 5) 
		    * cc_dim2) * cc_dim1 + 1] - (wa1[i__ - 2] * cc[(i__ - 1 + 
		    (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] + wa1[i__ 
		    - 1] * cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * 
		    cc_dim1 + 1])) + ti12 * (wa3[i__ - 2] * cc[(i__ - 1 + (k 
		    + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] + wa3[i__ - 1]
		     * cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 
		    1] - (wa2[i__ - 2] * cc[(i__ - 1 + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (k + 
		    cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1])) - (cc[(i__ + (k 
		    + cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr11 * (wa1[i__ - 
		    2] * cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 
		    + 1] - wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) *
		     cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) + tr12 * (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k 
		    + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2] *
		     cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1])));
	    ch[(i__ - 1 + (k * 5 + 5) * ch_dim2) * ch_dim1 + 1] = cc[(i__ - 1 
		    + (k + cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr12 * (wa1[
		    i__ - 2] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * cc_dim2) *
		     cc_dim1 + 1] + wa1[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 
		    1)) * cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ - 
		    1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] + wa4[i__ 
		    - 1] * cc[(i__ + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 
		    1])) + tr11 * (wa2[i__ - 2] * cc[(i__ - 1 + (k + cc_dim3 *
		     3) * cc_dim2) * cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (
		    k + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2]
		     * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * cc_dim2) * 
		    cc_dim1 + 1] + wa3[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 
		    2)) * cc_dim2) * cc_dim1 + 1])) + (ti12 * (wa1[i__ - 2] * 
		    cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] 
		    - wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * 
		    cc_dim2) * cc_dim1 + 1] - (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) - ti11 * (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k 
		    + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] - (wa3[i__ - 2] *
		     cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1])));
	    ch[(ic - 1 + (k * 5 + 4) * ch_dim2) * ch_dim1 + 1] = cc[(i__ - 1 
		    + (k + cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr12 * (wa1[
		    i__ - 2] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * cc_dim2) *
		     cc_dim1 + 1] + wa1[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 
		    1)) * cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ - 
		    1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] + wa4[i__ 
		    - 1] * cc[(i__ + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 
		    1])) + tr11 * (wa2[i__ - 2] * cc[(i__ - 1 + (k + cc_dim3 *
		     3) * cc_dim2) * cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (
		    k + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2]
		     * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * cc_dim2) * 
		    cc_dim1 + 1] + wa3[i__ - 1] * cc[(i__ + (k + (cc_dim3 << 
		    2)) * cc_dim2) * cc_dim1 + 1])) - (ti12 * (wa1[i__ - 2] * 
		    cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] 
		    - wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * 
		    cc_dim2) * cc_dim1 + 1] - (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) - ti11 * (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k 
		    + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] - (wa3[i__ - 2] *
		     cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1])));
	    ch[(i__ + (k * 5 + 5) * ch_dim2) * ch_dim1 + 1] = cc[(i__ + (k + 
		    cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr12 * (wa1[i__ - 2] 
		    * cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1]
		     - wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) * 
		    cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) + tr11 * (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k 
		    + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2] *
		     cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1])) + (ti12 * (wa4[i__ - 2] * cc[(
		    i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] + 
		    wa4[i__ - 1] * cc[(i__ + (k + cc_dim3 * 5) * cc_dim2) * 
		    cc_dim1 + 1] - (wa1[i__ - 2] * cc[(i__ - 1 + (k + (
		    cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] + wa1[i__ - 1] * 
		    cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1]))
		     - ti11 * (wa3[i__ - 2] * cc[(i__ - 1 + (k + (cc_dim3 << 
		    2)) * cc_dim2) * cc_dim1 + 1] + wa3[i__ - 1] * cc[(i__ + (
		    k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] - (wa2[i__ 
		    - 2] * cc[(i__ - 1 + (k + cc_dim3 * 3) * cc_dim2) * 
		    cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (k + cc_dim3 * 3) 
		    * cc_dim2) * cc_dim1 + 1])));
	    ch[(ic + (k * 5 + 4) * ch_dim2) * ch_dim1 + 1] = ti12 * (wa4[i__ 
		    - 2] * cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * 
		    cc_dim1 + 1] + wa4[i__ - 1] * cc[(i__ + (k + cc_dim3 * 5) 
		    * cc_dim2) * cc_dim1 + 1] - (wa1[i__ - 2] * cc[(i__ - 1 + 
		    (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 + 1] + wa1[i__ 
		    - 1] * cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * 
		    cc_dim1 + 1])) - ti11 * (wa3[i__ - 2] * cc[(i__ - 1 + (k 
		    + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] + wa3[i__ - 1]
		     * cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 
		    1] - (wa2[i__ - 2] * cc[(i__ - 1 + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] + wa2[i__ - 1] * cc[(i__ + (k + 
		    cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1])) - (cc[(i__ + (k 
		    + cc_dim3) * cc_dim2) * cc_dim1 + 1] + tr12 * (wa1[i__ - 
		    2] * cc[(i__ + (k + (cc_dim3 << 1)) * cc_dim2) * cc_dim1 
		    + 1] - wa1[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 1)) *
		     cc_dim2) * cc_dim1 + 1] + (wa4[i__ - 2] * cc[(i__ + (k + 
		    cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1] - wa4[i__ - 1] * 
		    cc[(i__ - 1 + (k + cc_dim3 * 5) * cc_dim2) * cc_dim1 + 1])
		    ) + tr11 * (wa2[i__ - 2] * cc[(i__ + (k + cc_dim3 * 3) * 
		    cc_dim2) * cc_dim1 + 1] - wa2[i__ - 1] * cc[(i__ - 1 + (k 
		    + cc_dim3 * 3) * cc_dim2) * cc_dim1 + 1] + (wa3[i__ - 2] *
		     cc[(i__ + (k + (cc_dim3 << 2)) * cc_dim2) * cc_dim1 + 1] 
		    - wa3[i__ - 1] * cc[(i__ - 1 + (k + (cc_dim3 << 2)) * 
		    cc_dim2) * cc_dim1 + 1])));
/* L102: */
	}
/* L103: */
    }
    return 0;
} /* r1f5kf_ */

