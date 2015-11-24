/* ----------------------------------------------------------- */
/*                                                             */
/*                          ___                                */
/*                       |_| | |_/   SPEECH                    */
/*                       | | | | \   RECOGNITION               */
/*                       =========   SOFTWARE                  */ 
/*                                                             */
/*                                                             */
/* ----------------------------------------------------------- */
/*         Copyright: Microsoft Corporation                    */
/*          1995-2000 Redmond, Washington USA                  */
/*                    http://www.microsoft.com                 */
/*                                                             */
/*   Use of this software is governed by a License Agreement   */
/*    ** See the file License for the Conditions of Use  **    */
/*    **     This banner notice must not be removed      **    */
/*                                                             */
/* ----------------------------------------------------------- */
/*         File: HMath.h:   Math Support                       */
/* ----------------------------------------------------------- */

/*  *** THIS IS A MODIFIED VERSION OF HTK ***                        */
/* ----------------------------------------------------------------- */
/*           The HMM-Based Speech Synthesis System (HTS)             */
/*           developed by HTS Working Group                          */
/*           http://hts.sp.nitech.ac.jp/                             */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2001-2008  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                                                                   */
/*                2001-2008  Tokyo Institute of Technology           */
/*                           Interdisciplinary Graduate School of    */
/*                           Science and Engineering                 */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the HTS working group nor the names of its  */
/*   contributors may be used to endorse or promote products derived */
/*   from this software without specific prior written permission.   */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

/* !HVER!HMath:   3.3 [CUED 28/04/05] */

#ifndef _HMATH_H_
#define _HMATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef PI
#undef PI                /* PI is defined in Linux */
#endif
#define PI   3.14159265358979
#define TPI  6.28318530717959     /* PI*2 */
#define LZERO  (-1.0E10)   /* ~log(0) */
#define LSMALL (-0.5E10)   /* log values < LSMALL are set to LZERO */
#define MINEARG (-708.3)   /* lowest exp() arg  = log(MINLARG) */
#define MINLARG 2.45E-308  /* lowest log() arg  = exp(MINEARG) */

/* NOTE: On some machines it may be necessary to reduce the
         values of MINEARG and MINLARG
*/

typedef float  LogFloat;   /* types just to signal log values */
typedef double LogDouble;

typedef enum {  /* Various forms of covariance matrix */
   DIAGC,         /* diagonal covariance */
   INVDIAGC,      /* inverse diagonal covariance */
   FULLC,         /* inverse full rank covariance */
   XFORMC,        /* arbitrary rectangular transform */
   LLTC,          /* L' part of Choleski decomposition */
   NULLC,         /* none - implies Euclidean in distance metrics */
   NUMCKIND       /* DON'T TOUCH -- always leave as final element */
} CovKind;

typedef union {
   SVector var;         /* if DIAGC or INVDIAGC */
   STriMat inv;         /* if FULLC or LLTC */
   SMatrix xform;       /* if XFORMC */
} Covariance;


/* ------------------------------------------------------------------- */

void InitMath(void);
/*
   Initialise the module
*/

void ResetMath(void);
/*
   Reset the module
*/

/* ------------------ Vector Oriented Routines ----------------------- */

void ZeroShortVec(ShortVec v);
void ZeroIntVec(IntVec v);
void ZeroVector(Vector v);
void ZeroDVector(DVector v);
/*
   Zero the elements of v
*/

void CopyShortVec(ShortVec v1, ShortVec v2);
void CopyIntVec(IntVec v1, IntVec v2);
void CopyVector(Vector v1, Vector v2);
void CopyRVector(Vector v1, Vector v2, int n);
void CopyDVector(DVector v1, DVector v2);
/*
   Copy v1 into v2; sizes must be the same
*/

Boolean ReadShortVec(Source *src, ShortVec v, Boolean binary);
Boolean ReadIntVec(Source *src, IntVec v, Boolean binary);
Boolean ReadVector(Source *src, Vector v, Boolean binary);
Boolean ReadDVector (Source *src, DVector v,  Boolean binary);
/*
   Read vector v from source in ascii or binary
*/

void WriteShortVec(FILE *f, ShortVec v, Boolean binary);
void WriteIntVec(FILE *f, IntVec v, Boolean binary);
void WriteVector(FILE *f, Vector v, Boolean binary);
void WriteDVector (FILE *f, DVector v,  Boolean binary);
/*
   Write vector v to stream f in ascii or binary
*/

void ShowShortVec(char * title, ShortVec v,int maxTerms);
void ShowIntVec(char * title, IntVec v,int maxTerms);
void ShowVector(char * title,Vector v,int maxTerms);
void ShowDVector(char * title,DVector v,int maxTerms);
/*
   Print the title followed by upto maxTerms elements of v
*/

/* Quadratic prod of a full square matrix C and an arbitry full matrix transform A */
void LinTranQuaProd(Matrix Prod, Matrix A, Matrix C);

/* ------------------ Matrix Oriented Routines ----------------------- */

void ZeroMatrix(Matrix m);
void ZeroIMatrix(IMatrix m);
void ZeroDMatrix(DMatrix m);
void ZeroTriMat(TriMat m);
void ZeroDTriMat(DTriMat m);
/*
   Zero the elements of m
*/

void CopyMatrix (Matrix m1,  Matrix m2);
void CopyIMatrix(IMatrix m1, IMatrix m2);
void CopyDMatrix(DMatrix m1, DMatrix m2);
void CopyTriMat (TriMat m1,  TriMat m2);
void CopyDTriMat(DTriMat m1, DTriMat m2);
/*
   Copy matrix m1 to m2 which must have identical dimensions
*/

void Mat2DMat(Matrix m1,  DMatrix m2);
void DMat2Mat(DMatrix m1, Matrix m2);
void Mat2Tri (Matrix m1,  TriMat m2);
void Tri2Mat (TriMat m1,  Matrix m2);
void DMat2DTri(DMatrix m1, DTriMat m2);
void DTri2DMat(DTriMat m1, DMatrix m2);
/*
   Convert matrix format from m1 to m2 which must have identical 
   dimensions
*/

Boolean ReadMatrix(Source *src, Matrix m, Boolean binary);
Boolean ReadIMatrix(Source *src, IMatrix m, Boolean binary);
Boolean ReadDMatrix(Source *src, DMatrix m, Boolean binary);
Boolean ReadTriMat(Source *src, TriMat m, Boolean binary);
Boolean ReadDTriMat(Source *src, DTriMat m, Boolean binary);
/*
   Read matrix from source into m using ascii or binary.
   TriMat version expects m to be in upper triangular form
   but converts to lower triangular form internally.
*/
   
void WriteMatrix(FILE *f, Matrix m, Boolean binary);
void WriteIMatrix(FILE *f, IMatrix m, Boolean binary);
void WriteDMatrix(FILE *f, DMatrix m, Boolean binary);
void WriteTriMat(FILE *f, TriMat m, Boolean binary);
void WriteDTriMat(FILE *f, DTriMat m, Boolean binary);
/*
    Write matrix to stream in ascii or binary.  TriMat version 
    writes m in upper triangular form even though it is stored
    in lower triangular form!
*/

void ShowMatrix (char * title,Matrix m, int maxCols,int maxRows);
void ShowIMatrix(char *title, IMatrix m, int maxCols, int maxRows);  
void ShowDMatrix(char * title,DMatrix m,int maxCols,int maxRows);
void ShowTriMat (char * title,TriMat m, int maxCols,int maxRows);
void ShowDTriMat(char *title, DTriMat m, int maxCols, int maxRows);
/*
   Print the title followed by upto maxCols elements of upto
   maxRows rows of m.
*/

/* ------------------- Linear Algebra Routines ----------------------- */

void MatrixMult(Matrix m1, Matrix m2, Matrix m);
/* 
   Matrix multiplication
*/

LogFloat CovInvert(TriMat c, Matrix invc);
LogDouble DCovInvert(DTriMat c, DMatrix invc);
/*
   Computes inverse of c in invc and returns the log of Det(c),
   c must be positive definite.
*/

LogFloat CovDet(TriMat c);
LogDouble DCovDet(DTriMat c);
/*
   Returns log of Det(c), c must be positive definite.
*/

/* EXPORT->MatDet: determinant of a matrix */
float MatDet(Matrix c);

/* EXPORT->DMatDet: determinant of a double matrix */
double DMatDet(DMatrix c);

/* EXPORT-> MatInvert: puts inverse of c in invc, returns Det(c) */
  float MatInvert(Matrix c, Matrix invc);
  double DMatInvert(DMatrix c, DMatrix invc);
 
/* DMatCofact: generates the cofactors of row r of doublematrix c */
double DMatCofact(DMatrix c, int r, DVector cofact);

/* MatCofact: generates the cofactors of row r of doublematrix c */
double MatCofact(Matrix c, int r, Vector cofact);

/* ------------- Singular Value Decomposition Routines --------------- */

void SVD(DMatrix A, DMatrix U,  DMatrix V, DVector d);
/* 
   Singular Value Decomposition (based on MESCHACH)
   A is m x n ,  U is m x n,  W is diag N x 1, V is n x n
*/

void InvSVD(DMatrix A, DMatrix U, DVector W, DMatrix V, DMatrix Result);
/* 
   Inverted Singular Value Decomposition (calls SVD)
   A is m x n ,  U is m x n,  W is diag N x 1, V is n x n, Result is m x n 
*/

/* ------------------- Log Arithmetic Routines ----------------------- */

LogDouble LAdd(LogDouble x, LogDouble y);
/*
   Return x+y where x and y are stored as logs, 
   sum < LSMALL is floored to LZERO 
*/

LogDouble LSub(LogDouble x, LogDouble y);
/*
   Return x-y where x and y are stored as logs, 
   diff < LSMALL is floored to LZERO 
*/

double L2F(LogDouble x);
/*
   Convert log(x) to real, result is floored to 0.0 if x < LSMALL 
*/

/* ------------------- Random Number Routines ------------------------ */

void RandInit(int seed);
/* 
   Initialise random number generators, if seed is -ve, then system 
   clock is used.  RandInit(-1) is called by InitMath.
*/

float RandomValue(void);
/*
   Return a random number in range 0.0->1.0 with uniform distribution
*/

float GaussDeviate(float mu, float sigma);
/*
   Return a random number with a N(mu,sigma) distribution
*/

int MultiNomial(Vector prob, const int N);
/* 
   Return a random number in range 1->N with multinomial distribution
*/

#ifdef __cplusplus
}
#endif

#endif  /* _HMATH_H_ */

/* ------------------------- End of HMath.h -------------------------- */
