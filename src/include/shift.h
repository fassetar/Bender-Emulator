#define SHIFT_H

#include "and.h"
#include "not.h"

class SHIFT
{
        public:
                SHIFT();

                void set(bool, bool);
                bool getSum();
                bool getLatch();

        private:
                bool input1;
                bool input2;
                NOT sum;
                AND Latch;
};

