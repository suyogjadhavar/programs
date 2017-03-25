//Write a C++ class for a Line drawing method using overloading 
//DDA and Bresenhams Algorithms, inheriting the pixel or point.

#include<graphics.h>
#include<iostream>
using namespace std;

class pt //base class
{
   protected: int xco,yco,color;
   public:
          pt()
          {
            xco=0;yco=0;color=15;
          }

          void setco(int x,int y)
          {
            xco=x;
            yco=y;
          }

          void setcolor(int c)
          {
            color=c;
          }

          void draw()
          {
            putpixel(xco,yco,color);
          }

};

class dline: public pt //derived class
{
    private: int x2,y2;
    public:
           dline():pt()
           {
             x2=0,y2=0;
           }

           void setline(int x, int y, int xx, int yy)
           {
             pt::setco(x,y);
             x2=xx;
             y2=yy;
           }

           void drawl() //Bresenham's Line
           {
             float x,y,dx,dy,e,temp;
             int i,s1,s2,ex;
             int xmax,xmid,ymax,ymid;
             xmax = getmaxx();
             ymax = getmaxy();
             xmid = xmax /2;
             ymid = ymax /2;

             //Step2
             dx=abs(x2-xco);
             dy=abs(y2-yco);

             //Step3
             x=xco;
             y=yco;
             pt::setco(x,y);
             pt::draw();

             //Step4.....sign() function
             if(x2 > xco) 
             {
                s1=1;
             }
             if(x2 < xco)
             {
                s1=-1;
             }
             if(x2 == xco)
             {
                s1=0;
             }

              
             if(y2 > yco)
             {
                s2=1;
             }
             if(y2 < yco)
             {
                s2=-1;
             }
             if(y2 == yco)
             {
                s2=0;
             }
             
             //Step5
             if(dy > dx)
             {
                temp = dx;
                dx = dy;
                dy = temp;

                ex = 1;
             }
             else
             {
                ex=0;
             }

             //Step6
             e=2*dy-dx; //decision variable
             cout<<"\t"<<1;
             cout<<"\t"<<e;
             cout<<"\t"<<x-xmid;
             cout<<"\t"<<ymid-y<<endl;
            
             //Step7
             i=1;
             do
             {
                  while(e>=0)
                  {
                     if(ex==1)
                     {
                        x = x + s1;
                     }
                     else
                     {
                        y = y + s2;
                     }
                     e = e - 2*dx;
                  }
                  if(ex==1)
                  {
                     y = y + s2;
                  }
                  else
                  {
                     x = x + s1;
                  }
     
                  e = e + 2*dy;
                  //cout<<"\tdy==="<<dy<<"And e===<<"<<e;
                  pt::setco(x,y);
                  pt::draw();
                  i = i + 1;
                  cout<<"\t"<<i;
                  cout<<"\t"<<e;
                  cout<<"\t"<<x-xmid;
                  cout<<"\t"<<ymid-y<<endl;
                  
           }while(i<=dx);

      }//funciton closed

      
      void drawl(int colour) //DDA Line
      {
          float x,y,dx,dy,len;
          int i;
          int xmax,xmid,ymax,ymid;
          xmax = getmaxx();
          ymax = getmaxy();
          xmid = xmax /2;
          ymid = ymax /2;
          pt::setcolor(colour);
           
          
          //step2 
          dx=abs(x2-xco);    
          dy=abs(y2-yco);

          //step3
          if(dx >= dy)
          {
             len=dx;
          }
          else
          {
             len=dy;
          }

          //step4
          dx=(x2-xco)/len;
          dy=(y2-yco)/len;

          //step5
          x = xco + 0.5;
          y = yco + 0.5;
          pt::setco(x,y);
          pt::draw();
          cout<<"\t"<<1;
          cout<<"\t"<<x-xmid;
          cout<<"\t\t"<<ymid-y<<endl;

          //step6
          i=1;
          while(i<=len)
          {
               x = x + dx;
               y = y + dy;
               i = i + 1;
               pt::setco(x,y);
               pt::draw();               
               cout<<"\t"<<i;
               cout<<"\t"<<x-xmid;
               cout<<"\t\t"<<ymid-y<<endl;
         }

     
     }//function closed

};

int main()
{
    int gd=DETECT,gm=VGAMAX;
    int ch,x1,y1,x2,y2, xmax,ymax,xmid,ymid;
    char a;
    initgraph(&gd,&gm,NULL);
    pt p;
    dline dda;

    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax /2;
    ymid = ymax /2;

    line(xmid,0,xmid,ymax); //Y-Axis
    line(0,ymid,xmax,ymid); //X-Axis 

    while(1)
    {
       xmax = getmaxx();
       ymax = getmaxy();
       xmid = xmax /2;
       ymid = ymax /2;

      
       cout<<"\n1.DDA LINE..";
       cout<<"\n2.BRESENHAM'S LINE..";
       cout<<"\n3.EXIT..";
       cout<<"\nEnter your choice: ";
       cin>>ch;

       switch(ch)
       {
         case 1:
                 cout<<"\nEnter the co-ordinates of the endpoints of line Below";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"Enter y1: "; cin>>y1;
                 cout<<"Enter x2: "; cin>>x2;
                 cout<<"Enter y2: "; cin>>y2;
                 
                 cout<<"\nFollowing Result Table Shows Step-by-Step Processing\n"; 
                 cout<<"\n------------------------------------------------------------------\n";
                 cout<<"\ti\tx\t\ty\n";
                 cout<<"-----------------------------------------------------------------\n";
                 dda.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
                 dda.drawl(5);
                 break;

         case 2:
                 cout<<"\nEnter the co-ordinates of the endpoints of line Below\n";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"Enter y1: "; cin>>y1;
                 cout<<"Enter x2: "; cin>>x2;
                 cout<<"Enter y2: "; cin>>y2;
               
                 cout<<"\nFollowing Result Table Shows Step-by-Step Processing\n"; 
                 cout<<"\n------------------------------------------------------------------\n";
                 cout<<"\ti\te\tx\ty\n";
                 cout<<"-----------------------------------------------------------------\n";
                 dda.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
                 dda.drawl();
                 break;

         case 3:
                 exit(0);
                 break;

       }

      

   }

   delay(3000);
   closegraph();
   return 0;


}
