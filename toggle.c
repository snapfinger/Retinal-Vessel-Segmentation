/*implement the toggle mapping filter for gray-scale imagetoggle mapping: based on comparison between the input image g and its opening y and closing fh(x)=[TM(g)](x)=f b1 (g)(x), if f b1 (g)(x)-g(x)<=g(x)-f b2 (g)(x)or y b2 (g)(x), if f b1 (g)(x)-g(x)>g(x)-f b2 (g)(x)y b1 -> opening with structuring element b1f b2 -> closing with structuring element b2*/#include "VisXV4.h"          /* VisX structure include file     */#include "Vutil.h"           /* VisX utility header files       */#include <stdbool.h>VXparam_t par[] =       {                           {    "if=",    0,   "opening input"},{    "ig=",    0,   "closing input"},{    "bf=",    0,   "original image"},{    "of=",    0,   " output file"},{     0,       0,   0}  };#define  OPEN   par[0].val#define  CLOSE  par[1].val#define  ORIGIN par[2].val#define  OVAL   par[3].valmain(argc, argv)int argc;char *argv[];{Vfstruct (im);                      /* i/o image structure          */Vfstruct (tm);                      /* temp image structure         */Vfstruct (im_op);Vfstruct (im_cl);VXparse(&argc, &argv, par);   Vfread(&im,ORIGIN);Vfread(&im_op,OPEN);Vfread(&im_cl,CLOSE);Vfembed(&tm,&im,0,0,0,0); //for toggle map outputint y,x;//image indexfor(y=im.ylo;y<=im.yhi;y++){	for(x=im.xlo;x<=im.xhi;x++){		if(im_cl.u[y][x]-im.u[y][x]<=im.u[y][x]-im_op.u[y][x]){			tm.u[y][x]=im_cl.u[y][x];		}else{			tm.u[y][x]=im_op.u[y][x];				}	}}fprintf(stderr,"toggle mapping filter done...\n");Vfwrite(&tm, OVAL);exit(0);}