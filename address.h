#ifndef ADDRESS_H
#define ADDRESS_H

class address 
{
    private:
        int PIN;
        char BldgNum[10], StreetName[30], city[20];

    public:
        // Member functions declarations
        void add2(void);
        void printadd(void);
};

#endif // ADDRESS_H