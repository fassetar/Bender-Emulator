#ifndef _FFXNOR_H
#define _FFXNOR_H
#include "xnor.h"

class FFXNOR
{
  public:
      FFXNOR();
      void reset();
      void  setS(bool);
      void  setR(bool);
      bool getQ();
      bool getQ1();
      void get(bool, bool);
  private:
       bool r;
       bool s; 
       bool q;
       bool q1;
};
#endif		
