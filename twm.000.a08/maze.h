
/*********************************************************************************************
 *
 * last edited by me on: "https://www.onlinegdb.com/edit/lUtcBxVhq"
 *
 *********************************************************************************************/

// #define P(X) j = write(1, X, 1)
#define P(X) j = sprintf(sz++, "%.*s", 1, X) ///<== MODIFIED (CC)

// // // // #define USE_MTWISTER

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <time.h>

#ifdef USE_MTWISTER
#include "mtwister.h"
#endif

// // #define C 32 // <== old
// // #define H 32 // <== old

/** 
 * This function will fill the buffer sz (it must be big enough) with characters
 * describing a maze in ASCII text format, composed just from ' ', '|' and '_'-s.
 * The original was like below (see footnote of this module)
 */
int getMaze(char* sz, size_t const len, int const w, int const h);

/* ****************************************************************************
#define P(X)j=write(1,X,1)
#define C 39
int M[5000]={2},*u=M,N[5000],R=22,a[4],l[]={0,-1,C-1,-1},m[]={1,-C,-1,C},*b=N,
*d=N,c,e,f,g,i,j,k,s;main(){for(M[i=C*R-1]=24;f|d>=b;){c=M[g=i];i=e;for(s=f=0;
s<4;s++)if((k=m[s]+g)>=0&&k<C*R&&l[s]!=k%C&&(!M[k]||!j&&c>=16!=M[k]>=16))a[f++
]=s;if(f){f=M[e=m[s=a[rand()/(1+2147483647/f)]]+g];j=j<f?f:j;f+=c&-16*!j;M[g]=
c|1<<s;M[*d++=e]=f|1<<(s+2)%4;}else e=d>b++?b[-1]:e;}P(" ");for(s=C;--s;P("_")
)P(" ");for(;P("\n"),R--;P("|"))for(e=C;e--;P("_ "+(*u++/8)%2))P("| "+(*u/4)%2
);}
**************************************************************************** */
